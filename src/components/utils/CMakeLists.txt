include_directories(
    ${COMPONENTS_DIR}/utils/include
    ${COMPONENTS_DIR}/utils/impl/include
)

set(SOURCES
    impl/src/timer_impl.cc
    impl/src/looper_timer_impl.cc
)

add_library(utils ${SOURCES})
