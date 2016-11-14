#ifndef TIMER_H
#define TIMER_H
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <functional>
#include <mutex>
#include <thread>

namespace utils {
namespace timer {
typedef std::function<void()> CallBack;
// typedef std::function<void()> StepCallBack;
/**
 * @brief The Timer class is an interface class for timers
 */
class Timer {
  /**
 * @brief Start starts timer countdown
 */
  virtual void Start() = 0;
  /**
 * @brief Terminate allows to terminate timer
 */
  virtual void Terminate() = 0;
};

}  // namespace timer
}  // namespace utils
#endif  // TIMER_H
