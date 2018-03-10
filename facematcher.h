#ifndef FACEMATCHER_H
#define FACEMATCHER_H
#include "opencv2/opencv.hpp"
#include "static_models.h"



class FaceMatcher
{
public:
    FaceMatcher();
    double MatchFaces(std::string& path_to_face1, std::string& path_to_face2);



    template<typename image_type>
    double MatchFaces(image_type& face1,
                      image_type& face2) {
        std::vector<image_type> faces = {face1,face2};
        auto face_descriptors = models_.network()(faces);
        return dlib::length(face_descriptors[0] - face_descriptors[1]);
    }

    bool ExtractFace(cv::Mat frame, dlib::matrix<dlib::rgb_pixel>* face);
    std::vector <cv::Rect> ExtractFacesRect(cv::Mat frame);
    StaticModels models_;
};




#endif // FACEMATCHER_H
