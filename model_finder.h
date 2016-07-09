#ifndef MODELFINDERIMPL_H
#define MODELFINDERIMPL_H
#include "face_model.h"
#include "frame_processor.h"

namespace finding {
class ModelFinderImpl : public FrameProcessor {
public:
    ModelFinderImpl(FaceModelPtr&& face_model);

    FaceModelPtr face_model_;

    // FrameProcessor interface
public:
    void ProcessFrame(const cv::Mat &frame);
};
}

#endif // MODELFINDERIMPL_H
