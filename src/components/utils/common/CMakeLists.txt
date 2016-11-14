include_directories(
    ${COMPONENTS_DIR}/utils/common/include
)

set(SOURCES
    src/notifier_impl.cc
)

add_library(common_utils ${SOURCES})

