#ifndef TIMER_H
#define TIMER_H
#include <functional>
#include <condition_variable>
#include <chrono>
#include <mutex>
#include <atomic>
#include <thread>

namespace utils {
namespace timer {
typedef std::function<void()> CallBack;
//typedef std::function<void()> StepCallBack;

class Timer {
    /**
  /** * @brief set_timeout_callback calls when timeout happens
  /** * @param callback
  /** */
//  virtual void set_timeout_callback(TimeOutCallBack callback) = 0;
 // virtual void set_callback(CallBack callback) = 0;

  //virtual void Start(unsigned int timeout) = 0;
  virtual void Start() = 0;
  virtual void Terminate() = 0;
//  virtual unsigned int GetTimeLeft() const = 0;
  //virtual void Stop() = 0;
private:
  virtual void MainThread() = 0;

};

}  // namespace timer
}  // namespace utils
#endif  // TIMER_H
