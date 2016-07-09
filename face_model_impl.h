#ifndef FACEMODELIMPL_H
#define FACEMODELIMPL_H
#include  <vector>
#include "face_model.h"
#include "face_finder.h"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/contrib/contrib.hpp"
#include <memory>

namespace finding {

class FaceModelImpl : public FaceModel {
public:
    FaceModelImpl();

    // FaceModel interface
public:
    double FaceOnFrameProbability(const cv::Mat &frame,
                                  std::vector<cv::Rect> &faces) override;

    void AddFaceView(const cv::Mat &view) override;

    bool IsTrained() override;

private:

    void Retrain();
    double MatchFace(cv::Mat& face);
    /**
     * @brief object_views_ collection of known face views
     */
    std::vector<cv::Mat> object_views_;
    std::unique_ptr<FaceFinder> face_finder_;
    cv::Ptr<cv::FaceRecognizer> model_;
    cv::Size faceSize_;

};

}  //namespace finding
#endif // FACEMODELIMPL_H
