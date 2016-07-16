#ifndef FACE_FINDER_H
#define FACE_FINDER_H
#include <vector>
#include "opencv2/core/core.hpp"

namespace cv {
class Mat;
}

typedef std::vector<cv::Rect> Faces;

/**
 * @brief The FaceFinder class provide possibility
 * to find a human faces on the image
 */
class FaceFinder {
 public:
  /**
   * @brief Find faces on image
   */
  virtual Faces FindFaces(const cv::Mat& frame) = 0;
};

#endif  // FACE_FINDER_H
