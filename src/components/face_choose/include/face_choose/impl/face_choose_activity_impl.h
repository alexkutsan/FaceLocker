#pragma once
#include <memory>
#include "face_choose/face_choose_activity.h"

namespace face_choose {

class FaceChooseActivityImpl : public FaceChooseActivity {
public:
	void ProcessFrame(const Frame& frame) override;
        void SetOnFaceChoosed(OnFaceChoosedCallback&& on_face_found_call_back) override;
        void SetOnExit(OnExitCallback&& on_exit_call_back) override;
	
private:
	OnFaceChoosedCallback on_face_choosed_callback_;
	OnExitCallback on_exit_call_back_;
	void OnFaceChoosed();
	void OnExit();
};

}
