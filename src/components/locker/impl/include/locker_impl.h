#ifndef SRC_COMPONENTS_LOCKER_IMPL_INCLUDE_LOCKER_IMPL_H_
#define SRC_COMPONENTS_LOCKER_IMPL_INCLUDE_LOCKER_IMPL_H_

#include "locker/locker.h"

namespace locker {

class LockerImpl : public Locker {
 public:
    void Lock() override;
};



}  //  namespace locker
#endif  // SRC_COMPONENTS_LOCKER_IMPL_INCLUDE_LOCKER_IMPL_H_
