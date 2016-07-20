#ifndef LOCK_WATCH_DOG_H
#define LOCK_WATCH_DOG_H

namespace locker {
typedef std::function<void()> OnScreenLocked;

class LockWatchDog {
 public:
  virtual void ProcessState(const bool state) = 0;
  virtual void set_on_screen_locked_callback(OnScreenLocked& callback) = 0;
};
}  // namespace locker
#endif  // LOCK_WATCH_DOG_H
