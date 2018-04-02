#include "faceoverlayhandler.h"
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>


FaceOverlayHandler::FaceOverlayHandler()
{

}

void FaceOverlayHandler::drawOverlay(cv::Mat frame) {
    for(auto& rect: frame_overlay_.all_faces) {
        cv::rectangle(frame, rect, cv::Scalar(255,255,255),
                      1);
    }
    cv::rectangle(frame, frame_overlay_.main_face, cv::Scalar(255,0,0),
                  3);
}
