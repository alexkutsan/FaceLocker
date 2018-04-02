#ifndef FACEOVERLAYHANDLER_H
#define FACEOVERLAYHANDLER_H
#include <opencv2/core.hpp>

struct FaceOverlay {
    cv::Rect main_face;
    std::vector<cv::Rect> all_faces;
    cv::Mat frame;
};

class FaceOverlayHandler {
public:
    FaceOverlayHandler();
    void set_current_overlay(FaceOverlay& overlay){
        frame_overlay_ = frame_overlay_;
    }

    void drawOverlay(cv::Mat frame);

    FaceOverlay frame_overlay_;
};

#endif // FACEOVERLAYHANDLER_H
