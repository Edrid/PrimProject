//
// Created by edoardo on 12/08/17.
//

#include <iostream>
#include "ImageElaborator.h"


ImageElaborator::ImageElaborator(string path) {
    setImage(path);
    imgToVectors();
} //Order: OK, compilier knows 'setImage()' exists
ImageElaborator::ImageElaborator() {}

void ImageElaborator::setImage(string path) {
    shared_ptr<Image> p(new Image(path)); //I need to use this temporary shared ptr, for some reason if i do img = new Image(path) it doesn't work. It doesn't work if I do Image i(path); img = &i; either
    img = p;
    imgToVectors();
}



void ImageElaborator::imgToVectors() {
    reds.resize(img->rows());


    //cout << "The vector height is:    " << reds.size() << "\tAnd width is: " << reds.at(0).size() << endl;
    //same for greens, blues and alphas
    greens.resize(img->rows());

    blues.resize(img->rows());

    alphas.resize(img->rows());

    //cout << "The image height is: " << img.size().height() << " The image width is: " << img.size().width();

    Color pixColor;
    for(unsigned int i = 0; i < img->rows(); i++){
        reds.at(i).resize(img->columns());
        alphas.at(i).resize(img->columns());
        blues.at(i).resize(img->columns());
        greens.at(i).resize(img->columns());
        for(unsigned int j = 0; j < img->columns(); j++){
            pixColor = img->pixelColor(j,i);
            alphas.at(i).at(j) = (int)pixColor.quantumAlpha();
            reds.at(i).at(j) = (int)pixColor.quantumRed();
            greens.at(i).at(j) = (int)pixColor.quantumGreen();
            blues.at(i).at(j) = (int)pixColor.quantumBlue();
            //cout << "  " << (int)pixColor.quantumGreen();
        }
        //cout << endl;
    }
}

//TODO renderImage()
void ImageElaborator::renderImage() {}