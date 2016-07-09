#include <iostream>
#include "object_tracker_impl.h"
#include "optical_flow_detector_impl.h"
#include "opencv2/features2d/features2d.hpp"`
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/highgui/highgui.hpp>

namespace training {

ObjectTrackerImpl::ObjectTrackerImpl()
    : kp_detector_(new cv::DenseFeatureDetector())
    , flow_detector_(new OpticalFlowDetectorImpl()) {
  flow_detector_->set_on_object_tracked(
      [&](cv::Mat frame, cv::Rect object_rect) {
        this->OnNewObjectView(frame(object_rect));
      });
}

void ObjectTrackerImpl::ProcessFrame(const cv::Mat& frame) {
  flow_detector_->ProcessFrame(frame);
}

void ObjectTrackerImpl::InitTracking(const cv::Mat& frame,
                                     const cv::Rect& form) {
  std::vector<cv::KeyPoint> keypoints = DetectKeyPoints(frame);
  std::vector<cv::Point2f> form_key_points;
  for (auto kp : keypoints) {
    if (form.contains(kp.pt)) {
      form_key_points.push_back(kp.pt);
    }
  }
  std::cout << "Extracted " << form_key_points.size() << std::endl;
  cv::Mat to_draw;
  cv::drawKeypoints(frame, keypoints, to_draw);
  cv::imshow("MainWindow", to_draw);
  flow_detector_->InitTracking(frame, form_key_points);
}

void ObjectTrackerImpl::OnNewObjectView(cv::Mat view) {
  new_object_view_callback_(view);
}

std::vector<cv::KeyPoint> ObjectTrackerImpl::DetectKeyPoints(
    const cv::Mat& frame) {
  std::vector<cv::KeyPoint> keypoints;
  cv::Mat grey;
  cv::cvtColor(frame, grey, CV_BGR2GRAY);
  kp_detector_->detect(grey, keypoints);
  return keypoints;
}

void ObjectTrackerImpl::set_object_view_detected_callback(
    NewObjectViewAvaliable func) {
  new_object_view_callback_ = func;
}
}
