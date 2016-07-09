#ifndef FACEMODEL_H
#define FACEMODEL_H
#include <memory>
#include <vector>
#include "opencv2/core/core.hpp"

namespace cv {
class Mat;
}

namespace finding {
/**
 * @brief The FaceModel class handle model of face and able to recognize face on frame
 */
class FaceModel {
public:
     /**
     * @brief FaceOnFrameProbability return probability (0..1)  that face is on Frame
     * @return
     */
    virtual double FaceOnFrameProbability(const cv::Mat& frame,
                                          std::vector<cv::Rect> &faces) = 0;

    /**
     * @brief AddFaceView adds new face view to model
     * @param view face view
     */
    virtual void AddFaceView(const cv::Mat& view) = 0;

    virtual bool IsTrained() = 0;
};

typedef std::unique_ptr<finding::FaceModel> FaceModelPtr;

}  //  namespace training
#endif // FACEMODEL_H
