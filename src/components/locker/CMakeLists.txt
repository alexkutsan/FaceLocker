include_directories(
    ${COMPONENTS_DIR}/locker/include
    ${COMPONENTS_DIR}/locker/impl/include
)


set(SOURCES
    impl/src/locker_impl.cpp
)

add_library(locker ${SOURCES})
