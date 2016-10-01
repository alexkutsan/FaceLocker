#include "timer_impl.h"
#include <iostream>
#include <ctime>

namespace utils {
namespace timer {
TimerImpl::TimerImpl(int timeout, CallBack func) : timeout_ (timeout), timer_callback_ (func) {}

void TimerImpl::DelayedCall(int timeout, CallBack func) {
    std::unique_lock<std::mutex> lock_(timer_mutex_);
//    unsigned int start_ = clock();
    std::cv_status status = cv_.wait_for(lock_, std::chrono::seconds(timeout));
    std::cout << "timeout = " << timeout << std::endl;
    if (status == std::cv_status::timeout) {
        func();
    }
//    unsigned int stop_ = clock();
//    unsigned int duration_ = stop_ - start_;
//    std::cout << "Duration = " << duration_ << std::endl;
    //std::cout << "End of DelayedCall" << std::endl;
}

void TimerImpl::MainThread() {
    DelayedCall(timeout_, timer_callback_);
    std::cout << "Exit MainThread" << std::endl;
}

void TimerImpl::Start(){
    std::thread temp([&] {MainThread();});
    timer_thread_.swap(temp);
}

void TimerImpl::Terminate() {
    std::unique_lock<std::mutex> lock_(timer_mutex_);
    cv_.notify_one();
}
}
}
