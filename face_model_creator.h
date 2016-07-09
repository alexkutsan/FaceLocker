#ifndef FACE_MODEL_CREATOR_H
#define FACE_MODEL_CREATOR_H
#include <memory>

#include "frame_processor.h"
#include "face_model.h"
#include "object_tracker.h"
#include "opencv2/core/core.hpp"

namespace training {
typedef std::function<void(finding::FaceModelPtr model)> ModelCreatedCallBack;
class FaceModeCreator : public FrameProcessor {
 public:
  FaceModeCreator(ModelCreatedCallBack model_created_callback);

  /**
   * @brief ProcessFrame try to find face on frame and supplement face model
   * @param frame frame with or without face
   */
  void ProcessFrame(const cv::Mat& frame) override;

  /**
   * @brief Init initialize Face model with initial face view
   * @param frame frame with face
   * @param face_rect face rectangle on frame
   */
  void Init(const cv::Mat& frame, const cv::Rect& face_rect);

 private:
  /**
   * @brief FinishModelCreation stop model creation
   */
  void FinishModelCreation();

  /**
   * @brief AddView add another one view of face
   * @param view - view of face
   */
  void AddView(cv::Mat view);

  /**
   * @brief object_tracker_ class that provide trackinf face
   */
  std::unique_ptr<ObjectTracker> object_tracker_;

  /**
   * @brief object_views_ collection of known face views
   */

  finding::FaceModelPtr face_model_;

  /**
   * @brief on_model_created_ callback for finishing model creation
   */
  ModelCreatedCallBack on_model_created_;
};
}
#endif  // FACE_MODEL_CREATOR_H
