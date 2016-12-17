include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include/
    ${COMPONENTS_DIR}/video_capture/include/
    ${COMPONENTS_DIR}/face_choose/include/
	${COMPONENTS_DIR}/utils/logger/include

)


set(SOURCES
    src/life_cycle_impl.cc
)

add_library(life_cycle ${SOURCES})
