#include "logger/logger.h"

CREATE_LOGGER("Main")

int main(int argc, char* argv[]) {
    log4cplus::initialize();
    log4cplus::PropertyConfigurator::doConfigure("log4cplus.properties");
    LOG_FATAL("Hello, fatal!");
    LOG_WARN("Hello, warn!");
    LOG_ERROR("Hello, error!");
    LOG_INFO("Hello, info!");
    LOG_DEBUG("Hello, debug!");
    LOG_TRACE("Hello, trace!");
    return 0;
}
