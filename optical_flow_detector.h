#ifndef OPTICAL_FLOW_DETECTOR_H
#define OPTICAL_FLOW_DETECTOR_H
#include <vector>
#include <cstdint>
#include "frame_processor.h"

typedef std::function<void(cv::Mat, cv::Rect)> TrackedFrameCallback;
namespace training {
typedef std::function<void(cv::Mat)> NewObjectViewAvaliable;
class OpticalFlowDetector : public FrameProcessor {
 public:
  virtual void InitTracking(cv::Mat frame,
                            std::vector<cv::Point2f>& points_to_track) = 0;
  virtual void set_on_object_tracked(TrackedFrameCallback func) = 0;
};
}

#endif  // OPTICAL_FLOW_DETECTOR_H
