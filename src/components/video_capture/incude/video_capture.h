#ifndef VIDEO_CAPTURE_H
#define VIDEO_CAPTURE_H

namespace video_capture {

typedef std::function<void(const cv::Mat& frame)> VideoCaptureCallback;

class VideoCapture {
  virtual void StartVideoCapturing() = 0;
  virtual void StopVideoCapturing() = 0;
  virtual void set_call_back(VideoCaptureCallback& call_back) = 0;
};
}
#endif  // VIDEO_CAPTURE_H
