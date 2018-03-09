cmake_minimum_required(VERSION 2.8.12)

project(face_recognition)
set (CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED )
find_package(dlib REQUIRED)


add_executable(face_recognition main.cc)
target_link_libraries(face_recognition 
    dlib::dlib
    ${OpenCV_LIBS}
    blas
    lapack
    )



add_executable(example example.cc)
target_link_libraries(example 
    dlib::dlib
    ${OpenCV_LIBS}
    blas
    lapack
    )

file( COPY ${CMAKE_SOURCE_DIR}/shape_predictor_68_face_landmarks.dat
      DESTINATION ${CMAKE_BINARY_DIR}/shape_predictor_68_face_landmarks.dat)

file( COPY ${CMAKE_SOURCE_DIR}/atnt_faces 
      DESTINATION ${CMAKE_BINARY_DIR}/atnt_faces)
