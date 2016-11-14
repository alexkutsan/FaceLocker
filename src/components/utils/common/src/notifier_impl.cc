#include "utils/common/impl/notifier_impl.h"

namespace utils {

void NotifierImpl::Notify() {
    std::unique_lock<std::mutex> lock_(mutex_);
    cv_.notify_one();
}

bool NotifierImpl::Wait(int count, int timeout){
    std::unique_lock<std::mutex> lock_(mutex_);
    while(count-- > 0) {
        std::cv_status status = cv_.wait_for(lock_, std::chrono::seconds(timeout));
        if (status == std::cv_status::timeout) {
          return false;
        }
    }
    return true;
}

}
