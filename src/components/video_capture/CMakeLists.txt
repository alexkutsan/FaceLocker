include_directories(
    ${COMPONENTS_DIR}/video_capture/include
)


set(SOURCES
    src/video_capture_impl.cc
)


add_library(video_capture ${SOURCES})
