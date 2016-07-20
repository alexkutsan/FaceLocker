project(FaceRecognizer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

cmake_minimum_required(VERSION 2.8)

set (COMPONENTS_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/src/components
)


set (SRC_LIST
    main.cpp
    )

add_subdirectory(src/components)



include_directories(
    ${COMPONENTS_DIR}/common/include
    ${COMPONENTS_DIR}/locker/include
    ${COMPONENTS_DIR}/locker/impl/include
    ${COMPONENTS_DIR}/face_finder/include
    ${COMPONENTS_DIR}/face_finder/impl/include
)

set (LIBRARIES
    log4cplus
    locker
    face_finder
    config
    )


add_executable(${PROJECT_NAME} ${SRC_LIST})
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})

file(COPY "log4cplus.properties" DESTINATION ${CMAKE_BINARY_DIR})
