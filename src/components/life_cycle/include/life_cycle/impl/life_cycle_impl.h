#pragma once
#include <atomic>
#include <memory>

#include "life_cycle/life_cycle.h"
#include "video_capture/video_capture.h"
#include "face_choose/face_choose_activity.h"

namespace life_cycle {

class LifeCycleImpl : public LifeCycle{
public:
	void Run() override;
	void Exit() override;
private:
	void InitConnections();
	void LifeCycleLoop();

	void LifeCycleStep();
	std::function<void (video_capture::Frame)> process_;
	std::unique_ptr<video_capture::VideoCapture> capture_;
	std::unique_ptr<face_choose::FaceChooseActivity> face_choose_activity_;
	std::atomic<bool> stop_flag_;
        void InitFaceChooseActivity();
};

}  // namaspace life_cycle


