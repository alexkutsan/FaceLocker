include_directories(
    ${COMPONENTS_DIR}/user_initialization/include
    ${COMPONENTS_DIR}/user_initialization/impl/include
)


set(SOURCES
    impl/src/user_initializator_impl.cc
)


add_library(user_initialization ${SOURCES})
