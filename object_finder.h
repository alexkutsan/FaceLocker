#ifndef OBJECT_FINDER_H
#define OBJECT_FINDER_H

namespace cv {
class Mat;
}

namespace training {

class ObjectFinder {
  virtual cv::Rect findObject(cv::Mat& frame) = 0;
};
}

#endif  // OBJECT_FINDER_H
