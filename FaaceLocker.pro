#-------------------------------------------------
#
# Project created by QtCreator 2013-06-12T22:10:13
#
#-------------------------------------------------
CONFIG += qt
TEMPLATE = app
QT       += gui core
INCLUDEPATH += opencv_install/include

LIBS += -L/opencv_install/lib -lopencv_core -lopencv_imgproc -lopencv_calib3d -lopencv_video \
                                    -lopencv_features2d -lopencv_ml -lopencv_highgui -lopencv_objdetect\
                                   -lopencv_contrib -lopencv_legacy -lopencv_flann
QMAKE_CXXFLAGS += -std=c++11

QMAKE_LFLAGS += -fopenmp -pg -g
QMAKE_CXXFLAGS += -fopenmp -pg -g

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtCamTest
TEMPLATE = app


SOURCES += \
    main.cpp \
    object_tracker_impl.cpp \
    optical_flow_detector_impl.cpp \
    interactive_face_selector.cpp \
    video_capture.cpp \
    key_points_extractor.cpp \
    face_model_creator.cpp \
    face_model_impl.cpp \
    face_finder_impl.cpp \
    model_finder.cpp

HEADERS  += \
    object_tracker.h \
    object_tracker_impl.h \
    optical_flow_detector.h \
    optical_flow_detector_impl.h \
    object_finder.h \
    face_model_creator.h \
    interactive_face_selector.h \
    video_capture.h \
    frame_processor.h \
    key_points_extractor.h \
    face_model.h \
    face_model_impl.h \
    face_finder_impl.h \
    face_finder.h \
    model_finder.h
