include_directories(
    ${COMPONENTS_DIR}/video_capture/include
    ${COMPONENTS_DIR}/video_capture/impl/include
)


set(SOURCES
    impl/src/video_capture_impl.cc
)


add_library(video_capture ${SOURCES})
