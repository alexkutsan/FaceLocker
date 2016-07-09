#ifndef FACEFINDERIMPL_H
#define FACEFINDERIMPL_H
#include "face_finder.h"
#include <opencv2/objdetect/objdetect.hpp>

namespace finding {
class FaceFinderImpl : public FaceFinder
{
public:
    FaceFinderImpl();

public:
    int FindFaces(const cv::Mat &frame, std::vector<cv::Rect>& faces) override;
    cv::CascadeClassifier face_cascade;
};

}
#endif // FACEFINDERIMPL_H
