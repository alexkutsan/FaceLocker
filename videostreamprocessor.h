#ifndef VIDEOSTREAMPROCESSOR_H
#define VIDEOSTREAMPROCESSOR_H
#include "facematcher.h"

class VideoStreamProcessor {
public:
    VideoStreamProcessor();
    void process(cv::Mat curren_frame);
    void onClick(long x, long y);
    FaceMatcher face_matcher;
    cv::Mat saved_frame_;
    cv::Mat current_frame_;
    dlib::matrix<rgb_pixel> saved_face_;
    void setSaved(const cv::Mat &value);
};

#endif // VIDEOSTREAMPROCESSOR_H
