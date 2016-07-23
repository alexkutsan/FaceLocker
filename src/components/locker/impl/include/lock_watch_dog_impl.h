#ifndef LOCK_WATCH_DOG_IMPL_H
#define LOCK_WATCH_DOG_IMPL_H
#include <memory>
#include "config/config.h"
#include "locker/lock_watch_dog.h"
#include "utils/timer.h"

namespace locker {
class LockWatchDogImpl : public LockWatchDog {
 public:
  LockWatchDogImpl(OnScreenLocked& callback, config::Config& config);
  void ProcessState(const bool state);
  void set_on_screen_locked_callback(OnScreenLocked& callback);

 private:
  bool last_state_;
  std::unique_ptr<timer::Timer> timer_;
  config::Config& config_;
  OnScreenLocked callback_;
};
}
#endif  // LOCK_WATCH_DOG_IMPL_H
