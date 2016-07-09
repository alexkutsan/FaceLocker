#include "interactive_face_selector.h"
namespace training {

InteractiveFaceSelector::InteractiveFaceSelector()
    : main_window_name_("MainWindow") {
  on_face_selected_call_back_ = [](cv::Mat, cv::Rect) {
    std::cout << "Default on_face_selected_call_back_" << std::endl;
  };
  cv::namedWindow(main_window_name_.c_str(), 1);
  cvSetMouseCallback(
      main_window_name_.c_str(), InteractiveFaceSelector::on_mouse, this);
}

void InteractiveFaceSelector::set_on_face_selected_call_back(
    const OnFaceSelectedCallback& on_face_selected_call_back) {
  on_face_selected_call_back_ = on_face_selected_call_back;
}

void InteractiveFaceSelector::OnRectSelected(cv::Rect rect) {
  std::cout << rect << "Selected" << std::endl;
  on_face_selected_call_back_(current_frame_, rect);
}

void InteractiveFaceSelector::on_mouse(
    int event, int x, int y, int flags, void* param) {
  InteractiveFaceSelector* selector =
      reinterpret_cast<InteractiveFaceSelector*>(param);
  static int x_start = -1;
  static int y_start = -1;
  if (event == cv::EVENT_LBUTTONDOWN) {
    x_start = x;
    y_start = y;
  }
  if (event == cv::EVENT_LBUTTONUP) {
    int face_x = std::min(x_start, x);
    int face_y = std::min(y_start, y);
    int face_w = std::max(x_start, x) - face_x;
    int face_h = std::max(y_start, y) - face_y;
    cv::Rect selected_rect(face_x, face_y, face_w, face_h);
    if (selected_rect.area() > 10) {
      std::cout << selected_rect.area() << std::endl;
      selector->OnRectSelected(selected_rect);
    }
  }
}

void InteractiveFaceSelector::ProcessFrame(const cv::Mat& frame) {
  current_frame_ = frame;
  cv::imshow(main_window_name_.c_str(), current_frame_);
}
}
