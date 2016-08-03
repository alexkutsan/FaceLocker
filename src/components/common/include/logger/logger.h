#include <log4cplus/configurator.h>
#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>

#define CREATE_LOGGER(logger) \
  static log4cplus::Logger logger_ = log4cplus::Logger::getInstance(logger);

#define LOG_FATAL(logEvent) LOG4CPLUS_FATAL(logger_, logEvent)

#define LOG_ERROR(logEvent) LOG4CPLUS_ERROR(logger_, logEvent)

#define LOG_WARN(logEvent) LOG4CPLUS_WARN(logger_, logEvent)

#define LOG_INFO(logEvent) LOG4CPLUS_INFO(logger_, logEvent)

#define LOG_DEBUG(logEvent) LOG4CPLUS_DEBUG(logger_, logEvent)

#define LOG_TRACE(logEvent) LOG4CPLUS_TRACE(logger_, logEvent)
