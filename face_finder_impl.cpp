#include "face_finder_impl.h"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/video/tracking.hpp>
#include "opencv2/features2d/features2d.hpp"
#include <iostream>

namespace finding {
FaceFinderImpl::FaceFinderImpl() {
  assert(face_cascade.load("/home/alex/pro/FaceRecognizer/build/haarcascade_frontalface_alt.xml"));
}


int FaceFinderImpl::FindFaces(const cv::Mat &frame, std::vector<cv::Rect> &faces) {
    cv::Mat frame_gray;
    cv::cvtColor( frame, frame_gray, CV_BGR2GRAY );
    cv::equalizeHist( frame_gray, frame_gray );
    face_cascade.detectMultiScale( frame_gray, faces,
                                   1.1, 2, 0|CV_HAAR_SCALE_IMAGE, cv::Size(30, 30) );
    cv::imshow("MainWindow", frame);
    return faces.size();
}
}
