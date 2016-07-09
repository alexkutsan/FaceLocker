#include "model_finder.h"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <sstream>

namespace finding {
ModelFinderImpl::ModelFinderImpl(FaceModelPtr &&face_model):
    face_model_(std::move(face_model)) {

}

void ModelFinderImpl::ProcessFrame(const cv::Mat &frame) {
    std::vector<cv::Rect> faces;
    double prob = face_model_->FaceOnFrameProbability(frame, faces);
    if (prob == 0)
        return;
    std::stringstream ss;
    ss << "Is Face on frame : " << prob << std::endl;
    cv::Mat show = frame;
    cv::Point textOrg(10, 20);
    cv::putText(show, ss.str().c_str(), textOrg,
                cv::FONT_HERSHEY_SIMPLEX, 1,cv::Scalar::all(255), 3,4);
    if(prob > 100) {
            std::cout << "Prob: " << prob<< std::endl;
            cv::Mat face = frame(faces[0]);
            face_model_->AddFaceView(face);
            cv::circle(show,  cv::Point(400, 20), 10, cv::Scalar(0, 0, 255), -1);
    }  else {
        cv::circle(show,  cv::Point(400, 20), 10, cv::Scalar(0, 255,0), -1);
    }

    cv::imshow("MainWindow", show);
}

}
