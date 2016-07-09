#include "face_model_impl.h"
#include "face_finder_impl.h"
#include "opencv2/core/core.hpp"
#include <iostream>

static const unsigned PERSON_LABEL = 1;

/** LBPH face recognizer: **/
static const unsigned LBPH_RADIUS = 3;
static const unsigned LBPH_NEIGHBORS = 8;
static const unsigned LBPH_GRID_X =   8;
static const unsigned LBPH_GRID_Y    = 8;
static const unsigned LBPH_THRESHOLD = 180.0;

namespace finding {
FaceModelImpl::FaceModelImpl() {
    face_finder_.reset(new FaceFinderImpl);
}


void FaceModelImpl::AddFaceView(const cv::Mat &view) {
    cv::Mat gray;
    cv::cvtColor(view, gray, CV_BGR2GRAY);
    if (object_views_.empty()) {
        faceSize_ = cv::Size(gray.size().width, gray.size().height);
    } else {
        cv::resize(gray, gray, faceSize_);
    }
    object_views_.push_back(gray);
    Retrain();
}

bool FaceModelImpl::IsTrained() {
    return object_views_.size() > 100;
}

void FaceModelImpl::Retrain() {
    std::vector<int> labels(object_views_.size());
     for (auto it = labels.begin() ; it != labels.end() ; *(it++) = PERSON_LABEL);
     model_ = cv::createLBPHFaceRecognizer(LBPH_RADIUS, LBPH_NEIGHBORS, LBPH_GRID_X, LBPH_GRID_Y, LBPH_THRESHOLD);
     model_->train(object_views_, labels);
}


double FaceModelImpl::FaceOnFrameProbability(const cv::Mat &frame,
                                             std::vector<cv::Rect>& faces) {
    ;
    const int face_count = face_finder_->FindFaces(frame, faces);
    assert(face_count == faces.size());
    if (face_count == 0) {
        return 0;
    }
    double prob = 0;
    for (auto face: faces) {
        cv::Mat face_on_frame = frame(face);
        prob = MatchFace(face_on_frame);
        if (prob > 0.5) {
            return prob;
        }
    }
    return prob;
}

double FaceModelImpl::MatchFace(cv::Mat &face) {
       cv::Mat gray;
       cv::cvtColor(face, gray, CV_BGR2GRAY);
       cv::resize(gray, gray, faceSize_);
       int label;
       double confidence = 0.0;
       model_->predict(gray, label, confidence);
       return label == PERSON_LABEL ? confidence : 0;
}

}
