#include "video_capture.h"
#include <atomic>
#include <vector>


VideoCapture::VideoCapture() : frame_processor_(NULL), video_input_(0) {}

void VideoCapture::CaptureLoop() {
  if (!video_input_.isOpened())
    return;
  stop_flag_ = false;
  while (!stop_flag_) {
    cv::Mat frame;
    mtx_.lock();
    video_input_ >> frame;  // get a new frame from camera
    if (frame_processor_) {
      frame_processor_->ProcessFrame(frame);
    }
    mtx_.unlock();
    if (cv::waitKey(30) >= 0)
      break;
  }
  cv_.notify_all();
}

void VideoCapture::Stop() {
    stop_flag_ = true;
}

void VideoCapture::StopAndWait() {
    std::unique_lock<std::mutex> lck(mtx_);
    Stop();
    cv_.wait(lck);
}

void VideoCapture::set_frame_processor(FrameProcessor* frame_processor) {
  frame_processor_ = frame_processor;
}
