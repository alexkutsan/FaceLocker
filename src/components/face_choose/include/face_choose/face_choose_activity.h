#pragma once
#include <functional>
#include "video_capture/video_capture.h"

namespace face_choose {
	
typedef std::function<void ()> OnFaceChoosedCallback;
typedef std::function<void ()> OnExitCallback;
typedef video_capture::Frame Frame;
class FaceChooseActivity {
public:
	virtual void ProcessFrame(const Frame& frame) = 0;
        virtual void SetOnFaceChoosed(OnFaceChoosedCallback&& on_face_found_call_back) = 0;
        virtual void SetOnExit(OnExitCallback&& on_exit_call_back) = 0;
};

}

