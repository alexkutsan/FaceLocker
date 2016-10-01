#ifndef TIMER_IMPL_H
#define TIMER_IMPL_H
#include <functional>
#include <thread>
#include "utils/timer.h"

namespace utils {
namespace timer {

/**
 * @brief The TimerImpl class implements timer
 */
class TimerImpl: public Timer {

public:
  TimerImpl(int timeout, CallBack func);
  ~TimerImpl() {
       timer_thread_.join();
  }
  void Start() override;
  void Terminate() override;

protected:
  /**
   * @brief MainThread starts timer work
   */
  virtual void MainThread();

  /**
   * @brief DelayedCall will call CallBack after timeout
   * @param timeout time in seconds by the end of which callback will be called
   * @param func - callback function
   */
  void DelayedCall(int timeout,CallBack func);

  std::thread timer_thread_;
  std::mutex timer_mutex_;
  std::condition_variable cv_;
  CallBack timer_callback_;
  int timeout_;
};

}  // namespace timer
}  // namespace utils
#endif  // TIMER_H
