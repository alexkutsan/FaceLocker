#include <opencv2/highgui/highgui.hpp>
#include "facematcher.h"
#include <iostream>
#include "videostreamprocessor.h"
#include <functional>


void CallBackFunc(int event, int x, int y,
                  int flags, void* userdata) {

     if  ( event == cv::EVENT_LBUTTONDOWN ){
             std::function<void(int,int)>* on_mouse = reinterpret_cast<std::function<void(int,int)>*>(userdata);
            (*on_mouse)(x,y);
     }
}


void startvidestream() {

    VideoStreamProcessor processor;
    auto key_process = [&](cv::Mat temp) {
        auto key = cv::waitKey(30);
        if (key >= 0) {
            throw std::runtime_error("Exit");
        }
    };

    std::function<void(int,int)> on_mouse =  [&](int x, int y) {
        std::cout << x << " " << y << std::endl;
        processor.onClick(x, y);
    };

    cv::VideoCapture cap(0);
    if (!cap.isOpened())
    {
        std::cerr << "Unable to connect to camera" << std::endl;

    }

    cv::namedWindow("cam", 1);
    cv::setMouseCallback("cam", CallBackFunc, &on_mouse);

    while(true)
    {
        // Grab a frame
        cv::Mat temp;
        cap >> temp;
        if (temp.empty()) {
            throw std::runtime_error("Unable to read from cam");
        }
        processor.process(temp);
        cv::imshow("cam", temp);
        key_process(temp);
    }
}

int main() try {
    startvidestream();
} catch (std::exception ex) {
    std::cout << "Exception " << ex.what() << std::endl;
}
