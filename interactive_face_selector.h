#ifndef INTERACTIVEFACESELECTOR_H
#define INTERACTIVEFACESELECTOR_H
#include <mutex>
#include <iostream>
#include <atomic>
#include <functional>

#include "opencv2/opencv.hpp"

#include "frame_processor.h"
namespace training {

typedef std::function<void(cv::Mat, cv::Rect)> OnFaceSelectedCallback;
class InteractiveFaceSelector : public FrameProcessor {
 public:
  InteractiveFaceSelector();
  OnFaceSelectedCallback on_face_selected_call_back_;
  void set_on_face_selected_call_back(
      const OnFaceSelectedCallback& on_face_selected_call_back);

 private:
  void OnRectSelected(cv::Rect rect);

  static void on_mouse(int event, int x, int y, int flags, void* param = NULL);

  std::string main_window_name_;
  cv::Mat current_frame_;

  // FrameProcessor interface:
  void ProcessFrame(const cv::Mat& frame) override;
};
}

#endif  // INTERACTIVEFACESELECTOR_H
