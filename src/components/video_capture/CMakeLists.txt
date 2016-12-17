include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include/
)


set(SOURCES
    src/video_capture_impl.cc
)


add_library(video_capture ${SOURCES})
