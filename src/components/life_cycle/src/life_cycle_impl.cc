#include "life_cycle/impl/life_cycle_impl.h"

#include <future>
#include <iostream>

#include "video_capture/impl/video_capture_impl.h"
#include "face_choose/impl/face_choose_activity_impl.h"
#include "logger/logger.h"

namespace life_cycle {

void LifeCycleImpl::Run() {
    // CREATE_LOGGER("life_cycle");
    // LOG_DEBUG("Enter");
    std::cout << "Run" << std::endl;
    // Read config
    // Load model
    // Video capture initialisation
    // if model availabel start activities
    InitConnections();
    LifeCycleLoop();
}

void LifeCycleImpl::LifeCycleLoop() {
    std::cout << "LifeCycleLoop" << std::endl;
    while (!stop_flag_) {
        LifeCycleStep();
    }
}

void LifeCycleImpl::LifeCycleStep() {
    std::cout << "LifeCycleStep" << std::endl;
    auto future(std::async([this]() {
        return  this->capture_->GetFrame();
    }));
    process_(future.get());
}

void LifeCycleImpl::Exit() {
    process_ = [this](video_capture::Frame frame) {
        this->stop_flag_ = true;
        std::cout << "exit" << std::endl;
    };
}


void LifeCycleImpl::InitFaceChooseActivity()
{
    face_choose_activity_.reset(new face_choose::FaceChooseActivityImpl());
    face_choose_activity_->SetOnFaceChoosed([this]() {
        std::cout << "Face found" << std::endl;
        this->Exit();
    }
    );
    face_choose_activity_->SetOnExit([this]() {
        std::cout << "Exit triggered" << std::endl;
        this->Exit();
    }
    );
}

void LifeCycleImpl::InitConnections() {
    std::cout << "InitConnections" << std::endl;
    capture_.reset(new video_capture::VideoCaptureImpl());


    InitFaceChooseActivity();


    process_ = [this](video_capture::Frame frame) {
        this->face_choose_activity_->ProcessFrame(frame);
    };
    // VideoCaptureImpl video_cap;
    // FaceCooseActivity face_choose;
    // ModelCreatingActivity mode_creating;
    // FaceRecognitionActivity recognition_activity;
    // UserWatchDog user_watch_dog;
    // Locker loker;

    // auto exit = [&]() { Exit(); };
    // auto back_to_choose_face = [&]() {
    // 		face_choose.Reset();
    // 		// Switch activity to face_choose
    // }
    // face_choose.SetOnExit(exit);
    // mode_creating.SetOnExit(exit);
    // recognition_activity.SetOnExit(exit);

    // mode_creating.SetOnReset(back_to_choose_face);
    // recognition_activity.SetOnReset(back_to_choose_face);

    // face_choose.SetOnFaceChoosedCallback(
    // 		[&](FaceOnFrame face) {
    // 			mode_creating.Init(face);
    // 			// Switch activity
    // 		}
    // );
    // mode_creating.SetOnModelCreatedCallBack(
    // 		[&](Model model) {
    // 			recognition_activity.Init(model);
    // 			// Switch activity
    // 		}
    // );
    // mode_creating.SetOnReset(back_to_choose_face);

    // recognition_activity.OnUserStatus(
    // 		[&](bool is_available) {
    // 			user_watch_dog.NotifyUserStatus(is_available);
    // 		}
    // );

    // user_watch_dog.OnUserUnavalible(
    // 		[&]() {
    // 			loker.Lock();
    // 		}
    // );
}
}   // namaspace life_cycle


