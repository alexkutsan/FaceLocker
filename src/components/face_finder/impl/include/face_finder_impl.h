#ifndef SCR_COMPONENTS_FACE_FINDER_INCLUDE_FACE_FINDER_IMPL_H
#define SCR_COMPONENTS_FACE_FINDER_INCLUDE_FACE_FINDER_IMPL_H

#include "face_finder/face_finder.h"


namespace face_finder {

class FaceFinderImpl : public FaceFinder {
 public:
    Faces FindFaces(const cv::Mat& frame) override;
};



} //  namespace face_finder
#endif  // SCR_COMPONENTS_FACE_FINDER_INCLUDE_FACE_FINDER_IMPL_H
