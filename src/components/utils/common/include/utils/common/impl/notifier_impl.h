#ifndef NOTIFIER_IMPL_H
#define NOTIFIER_IMPL_H
#include "utils/common/notifier.h"

namespace utils {
    class NotifierImpl : public Notifier {
    public:
        void Notify() override;
        bool Wait(int count, int timeout) override;

    private:
        std::mutex mutex_;
        std::condition_variable cv_;
    };
}

#endif
