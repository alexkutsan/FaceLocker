#ifndef LOOPER_TIMER_IMPL_H
#define LOOPER_TIMER_IMPL_H
#include <functional>
#include <thread>
#include "utils/timer.h"
#include "timer_impl.h"

namespace utils {
namespace timer {

class LooperTimerImpl: public TimerImpl {
public:
  LooperTimerImpl(int timeout, CallBack func);
  void Start() override;
  void Stop();

private:
  void MainThread() override;

  std::mutex timer_mutex_;
  std::condition_variable cv_;
  std::thread timer_thread_;
  std::atomic<int> stop_flag_;
  CallBack call_back_;
  int timeout_;
};

}  // namespace timer
}  // namespace utils
#endif  // LOOPER_TIMER_H
