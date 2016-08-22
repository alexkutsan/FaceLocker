#ifndef TIMER_IMPL_H
#define TIMER_IMPL_H
#include <functional>
#include <thread>

#include "utils/timer.h"

namespace utils {
namespace timer {
typedef std::function<void()> CallBack;

class LooperTimerImpl: public Timer {

  void set_timeout_callback(CallBack callback);
//  unsigned int GetTimeLeft() const override;
  void Start() override;
//  void Stop() override;
  void MainThread() override;
  void Terminate() override;
  void Stop();

private:
  std::mutex timer_mutex_;
  std::condition_variable cv_;
  std::thread timer_thread_;
  CallBack call_back_;
  int timeout_;
};

}  // namespace timer
}  // namespace utils
#endif  // TIMER_H
