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



add_executable(video_test
               test_video.cpp
               facematcher.cpp
               videostreamprocessor.cpp
               faceoverlayhandler.cpp)

target_link_libraries(video_test
    dlib::dlib
    ${OpenCV_LIBS}
    blas
    lapack
    )

file( COPY ${CMAKE_SOURCE_DIR}/dlib_face_recognition_resnet_model_v1.dat
      DESTINATION ${CMAKE_BINARY_DIR}/)


file( COPY ${CMAKE_SOURCE_DIR}/shape_predictor_5_face_landmarks.dat
      DESTINATION ${CMAKE_BINARY_DIR}/)

file( COPY ${CMAKE_SOURCE_DIR}/haarcascade_frontalface_alt.xml
      DESTINATION ${CMAKE_BINARY_DIR}/)




file( COPY ${CMAKE_SOURCE_DIR}/atnt_faces 
      DESTINATION ${CMAKE_BINARY_DIR}/)
