include_directories(
    ${COMPONENTS_DIR}/user_interface/include
    ${COMPONENTS_DIR}/user_interface/impl/include
)

set(CMAKE_AUTOMOC ON)

# Find the QtWidgets library
find_package(Qt5Widgets)


set(SOURCES
    impl/src/tray_icon_impl.cc
)


add_library(ui ${SOURCES})

# Use the Widgets module from Qt 5.
target_link_libraries(ui Qt5::Widgets)
