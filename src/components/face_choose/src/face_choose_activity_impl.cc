#include "face_choose/impl/face_choose_activity_impl.h"
#include <functional>
#include <iostream>

namespace face_choose {

void FaceChooseActivityImpl::ProcessFrame(const Frame& frame) {

	// std::cout << "ProcessFrame " << x << std::endl;
	if ((frame % 5) == 0) {
		OnFaceChoosed();
	}
	/**
	member faces = findFacesOnFrame();
	for face in faces {
		drawface();
	}
	act = GetAct();
	act();
	
	Available acts:
		Exit();
		ChooseFace();
	**/
}

void FaceChooseActivityImpl::SetOnFaceChoosed(OnFaceChoosedCallback&& on_face_found_call_back){
   on_face_choosed_callback_ = on_face_found_call_back;
}

void FaceChooseActivityImpl::SetOnExit(OnExitCallback&& on_exit_call_back){
on_exit_call_back_ = on_exit_call_back;
}

void FaceChooseActivityImpl::OnFaceChoosed() {
	std::cout << "OnFaceChoosed"  << std::endl;
	// Close windiows unsubscribe callbacks
	on_face_choosed_callback_();
}


void FaceChooseActivityImpl::OnExit() {
	// Close windiows unsubscribe callbacks
	on_exit_call_back_();
}


}  // namespace face_choose 


