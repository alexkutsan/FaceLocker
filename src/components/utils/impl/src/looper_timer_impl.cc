#include <looper_timer.h>
#include <iostream>

namespace utils{
namespace timer {
LooperTimerImpl::LooperTimerImpl(int timeout, CallBack func): TimerImpl(timeout, func), stop_flag_(false){}

void LooperTimerImpl::Start() {
    std::cout << "Looper timeout = " << timeout_ <<std::endl;
    stop_flag_ = false;
    TimerImpl::Start();

}

void LooperTimerImpl::Stop() {
    stop_flag_ = true;
    Terminate();
}

void LooperTimerImpl::MainThread() {
    while(!stop_flag_) {
        DelayedCall(timeout_, timer_callback_);
        std::cout << "In Looper Main Thread" << std::endl;
    }
}

}
}
