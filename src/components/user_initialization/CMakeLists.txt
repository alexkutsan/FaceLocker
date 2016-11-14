include_directories(
    ${COMPONENTS_DIR}/user_initialization/include
)


set(SOURCES
    src/user_initializator_impl.cc
)


add_library(user_initialization ${SOURCES})
