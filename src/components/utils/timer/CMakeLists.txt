include_directories(
    ${COMPONENTS_DIR}/utils/timer/include
    ${COMPONENTS_DIR}/utils/common/include
    ${CMAKE_SOURCE_DIR}/tools/limo/
)

set(SOURCES
    src/timer_impl.cc
    src/looper_timer_impl.cc
)

add_library(timer ${SOURCES})

add_subdirectory(tests)
