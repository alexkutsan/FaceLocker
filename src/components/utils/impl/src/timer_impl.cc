#include "timer_impl.h"
#include <ctime>

namespace utils {
namespace timer {
TimerImpl::TimerImpl(int timeout, CallBack func)
    : timeout_(timeout), timer_callback_(func) {}

void TimerImpl::DelayedCall(int timeout, CallBack func) {
  std::unique_lock<std::mutex> lock_(timer_mutex_);
  std::cv_status status = cv_.wait_for(lock_, std::chrono::seconds(timeout));
  if (status == std::cv_status::timeout) {
    func();
  }
}

void TimerImpl::MainThread() {
  DelayedCall(timeout_, timer_callback_);
}

void TimerImpl::Start() {
  std::thread temp([&] { MainThread(); });
  timer_thread_.swap(temp);
}

void TimerImpl::Terminate() {
  std::unique_lock<std::mutex> lock_(timer_mutex_);
  cv_.notify_one();
}

bool TimerImpl::WaitShots(int shots_count, int timeout) {

}
}
}
