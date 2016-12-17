 #include <thread>
 #include "logger/logger.h"
 #include "life_cycle/impl/life_cycle_impl.h"
#include <future>
#include <memory>
#include <functional>
#include <iostream>

int main(int argc, char* argv[]) {
	std::cout << "enter" << std::endl; 
     life_cycle::LifeCycleImpl life_cycle_;
     life_cycle_.Run();

	std::cout << "exit" << std::endl; 
    return 0;
}
