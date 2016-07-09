#include <functional>

#include "interactive_face_selector.h"
#include "face_model_creator.h"
#include "face_finder_impl.h"
#include "video_capture.h"
#include "model_finder.h"


int main() {
  VideoCapture video_capture;
  training::InteractiveFaceSelector selector;
  video_capture.set_frame_processor(&selector);
  finding::FaceModelPtr trained_model_(nullptr);
  std::unique_ptr<finding::ModelFinderImpl> model_finder(nullptr);

  training::FaceModeCreator model_creator(
      [&](finding::FaceModelPtr model) {
      std::cout << "Model created" << std::endl;
      model_finder.reset(new finding::ModelFinderImpl(std::move(model)));
      video_capture.set_frame_processor(model_finder.get());

  });

  auto on_face_selected_callback =
      [&](const cv::Mat& frame, const cv::Rect& face_rect) {
        model_creator.Init(frame, face_rect);
        video_capture.set_frame_processor(&model_creator);
    };
  selector.set_on_face_selected_call_back(on_face_selected_callback);
  video_capture.CaptureLoop();

  return 0;
}
