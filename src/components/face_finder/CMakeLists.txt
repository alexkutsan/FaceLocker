include_directories(
    ${COMPONENTS_DIR}/face_finder/include
)


set(SOURCES
    src/face_finder_impl.cpp
)

add_library(face_finder ${SOURCES})
