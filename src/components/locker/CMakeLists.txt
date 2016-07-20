include_directories(

    ${COMPONENTS_DIR}/utils/include
    ${COMPONENTS_DIR}/config/include
    ${COMPONENTS_DIR}/locker/include
    ${COMPONENTS_DIR}/locker/impl/include
)


set(SOURCES
    impl/src/locker_impl.cpp
)

if (${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    set (PLATFORM_SPECIFIC
        impl/src/private/locker_private_linux.cc
    )
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Win")
    set (PLATFORM_SPECIFIC
        impl/src/private/locker_private_win.cc
    )
endif()


add_library(locker ${SOURCES} ${PLATFORM_SPECIFIC})
