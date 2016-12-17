#pragma once
namespace video_capture {

typedef int Frame;

class VideoCapture {
public:
	virtual Frame GetFrame() = 0;
};
}
