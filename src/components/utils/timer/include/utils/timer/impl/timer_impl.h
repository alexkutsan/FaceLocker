#ifndef TIMER_IMPL_H
#define TIMER_IMPL_H
#include <functional>
#include <thread>
#include "utils/timer/timer.h"

namespace utils {
namespace timer {

/**
 * @brief The TimerImpl class implements timer
 */
class TimerImpl : public Timer {
 public:
  TimerImpl(int timeout, CallBack func);
  ~TimerImpl() {
    timer_thread_.join();
  }
  void Start() override;
  void Terminate() override;

  bool WaitShots(int shots_count, int timeout);

protected:
  /**
   * @brief DelayedCall will call CallBack after timeout
   * @param timeout time in seconds by the end of which callback will be called
   * @param func - callback function
   */
  void DelayedCall(int timeout, CallBack func);
  /**
   * @brief MainThread starts timer work
   */
  virtual void MainThread();


  /**
   * @brief timer_thread_ - additional thread for timer
   */
  std::thread timer_thread_;
  /**
   * @brief timer_mutex_ - preventing other threads with the same protection from executing concurrently
   */
  std::mutex timer_mutex_;
  /**
   * @brief cv_ -  block the calling thread until notified to resume
   */
  std::condition_variable cv_;
  /**
   * @brief timer_callback_ - function that is executed
   */
  CallBack timer_callback_;
  int timeout_;
};

}  // namespace timer
}  // namespace utils
#endif  // TIMER_H
