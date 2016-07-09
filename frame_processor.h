#ifndef FRAME_PROCESSOR_H
#define FRAME_PROCESSOR_H
namespace cv {
class Mat;
}
/**
 * @brief The FrameProcessor interface that provide possibility
 * to process frames from VideoCapture
 */
class FrameProcessor {
 public:
    /**
   * @brief ProcessFrame callback called on each frame from vide capture
   * @param frame
   */
  virtual void ProcessFrame(const cv::Mat& frame) = 0;
};

#endif  // FRAME_PROCESSOR_H
