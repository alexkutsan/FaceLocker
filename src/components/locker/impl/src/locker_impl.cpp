#include "locker_impl.h"
#include "private/locker_private.h"

namespace locker {

LockerImpl::LockerImpl() : impl_(new LockerPrivate()) {}

void LockerImpl::Lock() {
  impl_->Lock();
}

}  // namespace locker
