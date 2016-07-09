#ifndef VIDEOCAPTURE_H
#define VIDEOCAPTURE_H
#include <atomic>
#include <condition_variable>
#include <mutex>
#include "opencv2/opencv.hpp"

#include "frame_processor.h"

/**
 * @brief The VideoCapture class provide FrameProcessor to handle video frames.
 * FrameProcessor can be changed in life cycle
 */
class VideoCapture {
 public:
  VideoCapture();

  /**
   * @brief CaptureLoop infinit loop of frames handling
   */
  void CaptureLoop();

  /**
   * @brief Stops stops capture loop
   */
  void Stop();

  /**
   * @brief Stops stops capture loop and wait while it stops
   */
  void StopAndWait();


  /**
   * @brief set_frame_processor
   * @param frame_processor frame Processor setter
   */
  void set_frame_processor(FrameProcessor* frame_processor);

 private:
  FrameProcessor* frame_processor_;
  std::atomic<bool> stop_flag_;
  cv::VideoCapture video_input_;

  std::mutex mtx_;
  std::condition_variable cv_;
};

#endif  // VIDEOCAPTURE_H
