#include "locker/impl/locker_impl.h"
#include "locker/impl/private/locker_private.h"

namespace locker {

LockerImpl::LockerImpl() : impl_(new LockerPrivate()) {}

void LockerImpl::Lock() {
  impl_->Lock();
}

}  // namespace locker
