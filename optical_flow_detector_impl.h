#ifndef OPTICAL_FLOW_DETECTOR_IMPL_H
#define OPTICAL_FLOW_DETECTOR_IMPL_H
#include <functional>

#include "opencv2/core/core.hpp"

#include "optical_flow_detector.h"
namespace training {

struct TackedPoint {
  cv::Point2f prev;
  cv::Point2f next;
  bool is_tracked;
  float error;
};

typedef std::function<bool(const TackedPoint& point)> FilterFunction;
typedef std::function<FilterFunction(float mean_error, float stddev_error)>
    ThreasholdFunction;

class OpticalFlowDetectorImpl : public OpticalFlowDetector {
  // OpticalFlowDetector interface
 public:
  OpticalFlowDetectorImpl();
  void ProcessFrame(const cv::Mat& frame);
  void InitTracking(cv::Mat frame,
                    std::vector<cv::Point2f>& points_to_track) override;

  ThreasholdFunction threashold_func() const;
  void set_threashold_func(const ThreasholdFunction& threashold_func);

 private:
  std::function<bool(const TackedPoint& point)> GetExtractTrackedFilter(
      std::vector<TackedPoint> tracked);

  cv::Rect RectByPoints(std::vector<cv::Point2f> points);

  const std::vector<cv::Point2f> GetNewPoints(
      const std::vector<cv::Point2f>& previous_points,
      const std::vector<cv::Point2f>& next_points,
      const std::vector<uchar>& tracked_status,
      const cv::Mat& errors);

  std::vector<cv::Point2f> FilterVeryFarPoints(
      const std::vector<cv::Point2f>& points);
  cv::Mat last_frame_;
  std::vector<cv::Point2f> last_good_key_points_;
  ThreasholdFunction threashold_func_;
  TrackedFrameCallback tracked_frame_callback_;

  // FrameProcessor interface
 public:
  // OpticalFlowDetector interface
 public:
  void set_on_object_tracked(TrackedFrameCallback func);
};
}
#endif  // OPTICAL_FLOW_DETECTOR_IMPL_H
