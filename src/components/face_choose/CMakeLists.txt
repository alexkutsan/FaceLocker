include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include/
    ${COMPONENTS_DIR}/video_capture/include/
)


set(SOURCES
    src/face_choose_activity_impl.cc
)

add_library(face_choose ${SOURCES})
