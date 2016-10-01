#include <thread>
#include "logger/logger.h"
#include "timer_impl.h"
#include "looper_timer.h"
#include <iostream>
#include <chrono>

int main(int argc, char* argv[]) {


    utils::timer::LooperTimerImpl looper_timer_(2, []{
        for(char letter='a'; letter < 'z' ; ++letter)
        {
          std::cout<<letter<<" ";
        }
        std::cout << std::endl;
    });

    for (int i = 0; i < 10; i++){
        std::cout << i << " " << std::endl;
    }

    looper_timer_.Start();
    std::this_thread::sleep_for(std::chrono::seconds(5));
    looper_timer_.Stop();
    std::cout << "Exit program" << std::endl;
    return 0;
}
