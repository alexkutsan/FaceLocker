#include "timer_impl.h"

utils::timer::TimerImpl::TimerImpl(int timeout, CallBack func) : timeout_ (timeout), timer_callback_ (func) {}

/*void utils::timer::TimerImpl::set_timeout_callback(utils::timer::TimeOutCallBack callback)
{
    timer_callback_ = callback;
}*/

void utils::timer::TimerImpl::DelayedCall(int timeout, CallBack func) {        // do we need parameters here? if we have them as classes fields
    std::unique_lock<std::mutex> lock_(timer_mutex_);
    std::cv_status status = cv_.wait_for(lock_, std::chrono::seconds(timeout));
    if (status == std::cv_status::timeout) {
        func();
    }
}

void utils::timer::TimerImpl::MainThread() {
    DelayedCall(timeout_, timer_callback_);
}

void utils::timer::TimerImpl::Start(){
    std::thread temp([&] {MainThread();});
    timer_thread_.swap(temp);
}


void utils::timer::TimerImpl::Terminate() {
    std::unique_lock<std::mutex> lock_(timer_mutex_);
    cv_.notify_one();
}

