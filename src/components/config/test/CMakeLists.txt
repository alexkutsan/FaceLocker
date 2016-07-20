include_directories(
    ${COMPONENTS_DIR}/config/include
    ${COMPONENTS_DIR}/config/impl/include
${CMAKE_SOURCE_DIR}/3rd-party/limo/
)


set(SOURCES
    config_test.cc
)

set (LIBRARIES
     config
    )

add_executable(config_test ${SOURCES})

target_link_libraries(config_test ${LIBRARIES})

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/config.ini DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/   )
