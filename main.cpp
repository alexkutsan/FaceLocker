#include <thread>
#include "logger/logger.h"
#include "timer_impl.h"
#include <iostream>
#include <chrono>

int main(int argc, char* argv[]) {


    utils::timer::TimerImpl timer_(1, []{
        for(char letter='a'; letter < 'z' ; ++letter)
        {
          std::cout<<letter<<" ";
        }
    });

    timer_.Start();
    for (int i = 0; i < 100; i++){
        std::cout << i << " ";
    }

    std::this_thread::sleep_for(std::chrono::seconds(10));

    return 0;
}
