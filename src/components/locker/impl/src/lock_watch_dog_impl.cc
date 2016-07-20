
static const std::string kLockerSection = "Locker";
static const std::string kLockTimeOut = "LockTimeOut";
static const std::string kLockStepTimeOut = "LockStepTimeOut";

locker::LockWatchDogImpl::LockWatchDogImpl(locker::OnScreenLocked& callback,
                                           config::Config& config)
    : callback_(callback), config_(config) {}

void locker::LockWatchDogImpl::ProcessState(const bool state) {
  if (state != last_state_) {
    if (state == true) {
      timer_->Stop();
    } else {
      unsigned int timer_callback =
          config.GetInValue(kLockerSection, kLockTimeOut);
      unsigned int timer_step_callback =
          config.GetInValue(kLockerSection, kLockStepTimeOut);
      timer_->Start(timer_callback, timer_step_callback);
    }
  }
}

void locker::LockWatchDogImpl::ProcessState(const bool state) {
  if (state == last_state_) {
    return;
  }
  if (state == true) {
    timer_->Stop();
    return;
  }
  unsigned int timer_callback = config.GetInValue(kLockerSection, kLockTimeOut);
  unsigned int timer_step_callback =
      config.GetInValue(kLockerSection, kLockStepTimeOut);
  timer_->Start(timer_callback, timer_step_callback);

  void locker::LockWatchDogImpl::set_on_screen_locked_callback(
      locker::OnScreenLocked & callback) {
    callback_ = callback;
  }
}

#include "lock_watch_dog_impl.h"
