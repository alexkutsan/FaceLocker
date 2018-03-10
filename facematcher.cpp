#include "facematcher.h"
#include "dlib/opencv.h"

FaceMatcher::FaceMatcher() {

}

template <typename image_type>
std::vector<matrix<rgb_pixel>> get_faces(image_type img,
                                         StaticModels& models) {
    std::vector<matrix<rgb_pixel>> faces;
    auto detected_faces = models.detector_(img);
    for (auto& face : detected_faces) {
        auto shape = models.shape_predictor()(img, face);
        dlib::matrix<rgb_pixel> face_chip;
        dlib::extract_image_chip(img,
                                 dlib::get_face_chip_details(shape,150,0.25),
                                 face_chip);
        faces.push_back(std::move(face_chip));
    }
    return faces;
}

std::vector<matrix<rgb_pixel>> get_faces(const std::string image_path,
                                         StaticModels& models) {
    dlib::matrix<rgb_pixel> img;
    dlib::load_image(img, image_path);
    return get_faces(img, models);
}

double FaceMatcher::MatchFaces(std::string &path_to_face1,
                               std::string &path_to_face2) {
    auto faces1 = get_faces(path_to_face1, models_);
    auto faces2 = get_faces(path_to_face2, models_);
    assert(faces1.size() == 1);
    assert(faces2.size() == 2);
    return MatchFaces(faces1[0], faces2[0]);
}

bool FaceMatcher::ExtractFace(cv::Mat frame, dlib::matrix<rgb_pixel>* face) {
    dlib::cv_image<dlib::bgr_pixel> cimg(frame);
    auto face_on_frame = get_faces(cimg, models_);
    if (face_on_frame.size() > 0) {
        *face =  face_on_frame[0];
        return true;
    }
    return false;
}

std::vector<cv::Rect>
FaceMatcher::ExtractFacesRect(cv::Mat frame) {
    std::vector<cv::Rect> faces;
    cv::Mat frame_gray;
    cv::cvtColor(frame, frame_gray, cv::COLOR_BGR2GRAY);
    models_.face_cascade().detectMultiScale(
                frame_gray, faces,
                1.1, 2, 0 | cv::CASCADE_SCALE_IMAGE, cv::Size(30, 30));

    return faces;
}
