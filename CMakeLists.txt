project(FaceRecognizer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11 -pthread")

cmake_minimum_required(VERSION 2.8)

set (COMPONENTS_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/src/components
)

add_subdirectory(src/components)



include_directories(
    ${COMPONENTS_DIR}/locker/include
    ${COMPONENTS_DIR}/life_cycle/include
    ${COMPONENTS_DIR}/video_capture/include
    ${COMPONENTS_DIR}/face_choose/include
    ${COMPONENTS_DIR}/utils/logger/include
)

set (LIBRARIES
    life_cycle
    log4cplus
    face_choose
    video_capture
    )



set (SRC_LIST
    main.cpp
    )

add_executable(${PROJECT_NAME} ${SRC_LIST})
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})

file(COPY "log4cplus.properties" DESTINATION ${CMAKE_BINARY_DIR})
