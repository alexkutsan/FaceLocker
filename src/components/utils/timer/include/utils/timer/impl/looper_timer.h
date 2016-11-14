#ifndef LOOPER_TIMER_IMPL_H
#define LOOPER_TIMER_IMPL_H
#include "utils/timer/impl/timer_impl.h"
#include <functional>
#include <thread>

namespace utils {
namespace timer {

class LooperTimerImpl : public TimerImpl {
 public:
  LooperTimerImpl(int timeout, CallBack func);
  void Start() override;

  void Terminate() override;

 private:
  /**
   * @brief MainThread executes timer considering stop flag
   */
  void MainThread() override;

  /**
   * @brief stop_flag_ - detects if timer has to be stopped
   */
  std::atomic<int> stop_flag_;
};

}  // namespace timer
}  // namespace utils
#endif  // LOOPER_TIMER_H
