#ifndef OBJECTTRACKER_H
#define OBJECTTRACKER_H
#include "frame_processor.h"
#include "opencv2/core/core.hpp"

namespace training {

typedef std::function<void(cv::Mat)> NewObjectViewAvaliable;
/**
 * @brief The ObjectTracker class provides object tracking and finding new forms
 * of it
 * uses optical flow and SURF
 */
class ObjectTracker : public FrameProcessor {
 public:
  /**
 * @brief new_form add new form to collection
 * @param frame
 */
  virtual void InitTracking(const cv::Mat& frame, const cv::Rect& form) = 0;
  virtual void set_object_view_detected_callback(
      NewObjectViewAvaliable func) = 0;
};

}  // namespace training

#endif  // OBJECTTRACKER_H
