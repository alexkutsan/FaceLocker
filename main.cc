#include <dlib/dnn.h>
#include <dlib/gui_widgets.h>
#include <dlib/clustering.h>
#include <dlib/string.h>
#include <dlib/image_io.h>
#include <dlib/image_processing/frontal_face_detector.h>
#include "static_models.h"

using namespace dlib;

StaticModels models;

std::vector<matrix<rgb_pixel>> get_faces(const std::string image_path) {
    auto& detector = models.face_detector();
    
    std::vector<matrix<rgb_pixel>> faces;
    dlib::matrix<rgb_pixel> img;
    dlib::load_image(img, image_path);
    auto detected_faces = detector(img);
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

std::vector<matrix<rgb_pixel>> get_faces(const std::vector<std::string>& images) {
    std::vector<matrix<rgb_pixel>> faces;
    for(const auto& image_path: images) {
        auto image_faces = get_faces(image_path);
        faces.insert(faces.end(), image_faces.begin(),image_faces.end());
    }
    return faces;
}

int main(int argc, char** argv) {
    try {
        if (argc == 1) {
            throw std::invalid_argument("No arguments provided");
        }
        std::vector<std::string> input_data(argv + 1, argv + argc);
        auto faces = get_faces(input_data);
        std::vector<dlib::matrix<float,0,1>> face_descriptors = models.network()(faces);
        for(const auto& face1 : face_descriptors) {
         for(const auto& face2 : face_descriptors) {
            std::cout << dlib::length(face1 - face2) << " ";
         }
         std::cout << std::endl;
        }
    }
    catch(dlib::serialization_error& e) {
        using namespace std;
        cout << "You need dlib's default face landmarking model file to run this example." << endl;
        cout << "You can get it from the following URL: " << endl;
        cout << "   http://dlib.net/files/shape_predictor_68_face_landmarks.dat.bz2" << endl;
        cout << endl << e.what() << endl;
    }
    catch(std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}


