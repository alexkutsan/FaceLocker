#ifndef NOTIFIER_H
#define NOTIFIER_H
#include <condition_variable>
#include <mutex>

namespace utils {

    class Notifier {
        virtual void Notify() = 0;
        virtual bool Wait(int, int) = 0;
    };
}
#endif
