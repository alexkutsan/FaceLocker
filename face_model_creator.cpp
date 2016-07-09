#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "face_model_creator.h"
#include "object_tracker_impl.h"
#include "face_model_impl.h"
#include <utility>
namespace training {

FaceModeCreator::FaceModeCreator(ModelCreatedCallBack model_created_callback)
    : object_tracker_(new ObjectTrackerImpl())
    , on_model_created_(model_created_callback)
    , face_model_(new finding::FaceModelImpl) {
  object_tracker_->set_object_view_detected_callback(
      [&](cv::Mat new_face_view) { this->AddView(new_face_view); });
}

void FaceModeCreator::ProcessFrame(const cv::Mat& frame) {
  object_tracker_->ProcessFrame(frame);
}
void FaceModeCreator::Init(const cv::Mat& frame, const cv::Rect& face_rect) {
  object_tracker_->InitTracking(frame, face_rect);
}

void FaceModeCreator::FinishModelCreation() {
  on_model_created_(std::move(face_model_));
  face_model_.reset(new finding::FaceModelImpl);
}

void FaceModeCreator::AddView(cv::Mat view) {
  static long long index = 0;
  const std::string pattern = "/tmp/FaceModel/face_%i.jpg";
  char buffer[100];
  sprintf(buffer, pattern.c_str(), index++);
  cv::imwrite(buffer, view);
  face_model_->AddFaceView(view);
  if (face_model_->IsTrained()) {
    FinishModelCreation();
  }
}
}
