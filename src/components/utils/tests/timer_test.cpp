#include "limo/test_main.hpp"
#include "timer_impl.h"
#include "looper_timer.h"
#include "notifier_impl.h"

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
