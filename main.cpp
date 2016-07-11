#include <iostream>

#include "locker_impl.h"

int main(int argc, char* argv[]) {
    locker::LockerImpl l;
    l.Lock();
    return 0;
}
