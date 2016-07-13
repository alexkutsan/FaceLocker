#include "private/locker_private.h"
#include <iostream>

namespace locker {
void LockerPrivate::Lock() {
    std::cout << "Locked Windows" << std::endl;
}
}
