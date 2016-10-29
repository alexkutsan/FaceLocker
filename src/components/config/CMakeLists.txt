include_directories(
    ${COMPONENTS_DIR}/config/include
    ${COMPONENTS_DIR}/config/impl/include
)


set(SOURCES
    impl/src/config_impl.cc
)


add_library(config ${SOURCES})

add_subdirectory(test)
