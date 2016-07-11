#include "locker_impl.h"
#include <iostream>

namespace locker {

void LockerImpl::Lock() {
    std::cout << "Locked" << std::endl;
}

}  // namespace locker
