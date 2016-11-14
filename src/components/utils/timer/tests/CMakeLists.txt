set (SRC_LIST
    timer_test.cpp
    )

include_directories(
    ${COMPONENTS_DIR}/utils/timer/include
    ${CMAKE_SOURCE_DIR}/3rd-party/limo
)

set (LIBRARIES
    timer
    common_utils
    log4cplus
    pthread
    )


add_executable(timer_test ${SRC_LIST})

target_link_libraries(timer_test  ${LIBRARIES})
