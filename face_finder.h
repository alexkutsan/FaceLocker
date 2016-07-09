#ifndef FACE_FINDER_H
#define FACE_FINDER_H
#include <vector>
#include "opencv2/core/core.hpp"


namespace finding {
    class FaceFinder {
        public:
       virtual int FindFaces(const cv::Mat &frame, std::vector<cv::Rect>& faces) = 0;
    };
}
#endif // FACE_FINDER_H
