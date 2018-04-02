#include "videostreamprocessor.h"
#include <dlib/opencv.h>

void DrawSimpleRect(cv::Mat frame, cv::Rect rect) {
    cv::rectangle(frame,rect, cv::Scalar(255,255,255),
                  1);
}

void DrawBoldRect(cv::Mat frame, cv::Rect rect) {
    cv::rectangle(frame,rect, cv::Scalar(255,0,0),
                  3);
}


VideoStreamProcessor::VideoStreamProcessor(FaceOverlayHandler& handler):
    handler_(handler) {

}

void VideoStreamProcessor::process(cv::Mat curren_frame) {
    current_frame_ = curren_frame;
    FaceOverlay overlay_;
    overlay_.frame = curren_frame;
    auto all_faces = face_matcher.ExtractFacesRect(curren_frame);
    overlay_.all_faces = all_faces;
    if (!saved_frame_.empty()) {
        for(auto& rect: all_faces) {
            cv::Mat face = curren_frame(rect);

            dlib::matrix<rgb_pixel> dface;
            if(!face_matcher.ExtractFace(face, &dface)) {
                std::cout << "OpenCV did found face but dlib does not" << std::endl;
                return;
            }
            double distance = face_matcher.MatchFaces(dface,
                                                      saved_face_);
            std::cout << distance << std::endl;
            if (distance < 0.6) {
                overlay_.main_face = rect;
            }
        }
    }
    handler_.set_current_overlay(overlay_);
}

void VideoStreamProcessor::onClick(long x, long y) {
    setSaved(current_frame_);
    auto rects = face_matcher.ExtractFacesRect(saved_frame_);
    std::cout << "Faces on frame " << rects.size() << std::endl;
    for (cv::Rect& rect: rects) {
        if(rect.contains(cv::Point(x,y))) {
            auto face = saved_frame_(rect);
            if(!face_matcher.ExtractFace(face, &saved_face_)) {
                throw "OpenCV did found face but dlib does not";
            }
            std::cout << "Save face" << std::endl;
        } else {
            std::cout << "Rect not contains face" << std::endl;
        }
    }
}


void VideoStreamProcessor::setSaved(const cv::Mat &value) {
    saved_frame_ = value;
}

