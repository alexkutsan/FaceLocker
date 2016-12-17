#pragma once
#include <thread>
#include "video_capture/video_capture.h"

namespace video_capture {

class VideoCaptureImpl : public VideoCapture {
public:
 	Frame GetFrame() override;
};

}  // namespace video_capture

