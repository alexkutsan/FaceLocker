#ifndef ENGINE_H
#define ENGINE_H
#include <memory>
#include "object_tracker.h"
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "optical_flow_detector.h"
#include "object_finder.h"

namespace training {
class ObjectTrackerImpl : public ObjectTracker {
 public:
  ObjectTrackerImpl();
  void ProcessFrame(const cv::Mat& frame) override;
  void InitTracking(const cv::Mat& frame, const cv::Rect& form) override;

 private:
  void OnNewObjectView(cv::Mat view);
  std::vector<cv::KeyPoint> DetectKeyPoints(const cv::Mat& frame);
  std::unique_ptr<OpticalFlowDetector> flow_detector_;
  std::unique_ptr<ObjectFinder> object_finder_;
  std::unique_ptr<cv::FeatureDetector> kp_detector_;
  NewObjectViewAvaliable new_object_view_callback_;
  // ObjectTracker interface
 public:
  void set_object_view_detected_callback(NewObjectViewAvaliable func) override;
};

}  // namespace training
#endif  // ENGINE_H
