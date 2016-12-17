#include "video_capture/impl/video_capture_impl.h"
namespace video_capture {

  Frame VideoCaptureImpl::GetFrame() {
    static Frame x(1);
  	return x++;
  }
 
}  //  namespace video_capture

