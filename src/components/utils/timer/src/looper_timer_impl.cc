#include "utils/timer/impl/looper_timer.h"

namespace utils {
namespace timer {
LooperTimerImpl::LooperTimerImpl(int timeout, CallBack func)
    : TimerImpl(timeout, func), stop_flag_(false) {}

void LooperTimerImpl::Start() {
  stop_flag_ = false;
  TimerImpl::Start();
}

void LooperTimerImpl::Terminate() {
    stop_flag_ = true;
        TimerImpl::Terminate();
}

void LooperTimerImpl::MainThread() {
  while (!stop_flag_) {
    DelayedCall(timeout_, timer_callback_);
  }
}
}
}
