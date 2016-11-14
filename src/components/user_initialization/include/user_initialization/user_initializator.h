#ifndef USER_INITIALIZATION_H
#define USER_INITIALIZATION_H

namespace cv {
class Mat;
}

namespace user_initialization {
typedef std::function<void(const cv::Mat&)> OnUserFaceSelected;
class UserInitializator {
  virtual void ProcessFrame(const cv::Mat& frame) = 0;
  virtual void Start() = 0;
  virtual void SetOnFaceSelectedCallback(OnUserFaceSelected& callback) = 0;
};
}

#endif  // USER_INITIALIZATION_H
