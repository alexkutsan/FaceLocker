#ifndef TIMER_IMPL_H
#define TIMER_IMPL_H
#include <functional>
#include "utils/timer.h"

namespace utils {
namespace timer {
typedef std::function<void()> TimeOutCallBack;
typedef std::function<void()> StepCallBack;

class TimerImpl: public Timer {
    /**
  /** * @brief set_timeout_callback calls when timeout happens
  /** * @param callback
  /** */
  void set_timeout_callback(TimeOutCallBack callback) override;
  void set_step_callback(StepCallBack callback) override;
  unsigned int get_timeout() const override;
  unsigned int get_step_timeout() const override;
  unsigned int GetTimeLeft() const override;
  void Start(unsigned int timeout, unsigned int step_timeout) override;
  void Stop() override;
};

}  // namespace timer
}  // namespace utils
#endif  // TIMER_H
