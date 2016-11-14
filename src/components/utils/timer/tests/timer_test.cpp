#include "utils/timer/impl/timer_impl.h"
#include "utils/timer/impl/looper_timer.h"
#include "utils/common/impl/notifier_impl.h"

#include "limo/test.hpp"

int main() {
    LTEST(SimpleTimerTest) {
        utils::NotifierImpl notifier_;
        utils::timer::TimerImpl timer_(1, [&notifier_]{
            notifier_.Notify();
        }
    );
      timer_.Start();
      EXPECT_TRUE(notifier_.Wait(1, 2));
    };

    LTEST(LooperTimerTest) {
        utils::NotifierImpl notifier_;
        utils::timer::LooperTimerImpl timer_(1, [&notifier_]{
            notifier_.Notify();
        }
    );
      timer_.Start();
      EXPECT_TRUE(notifier_.Wait(4, 2));
      timer_.Terminate();
    };

    get_ltest_context()->run();
    return 0;
}

//------------------------------------------------------------------------------






