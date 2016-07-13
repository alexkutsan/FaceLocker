#include "locker/locker.h"

namespace locker {
    class LockerPrivate : public Locker {
        // Locker interface
    public:
        void Lock() override;
    };
}
