//
// Created by edoardo on 12/08/17.
//

#include <iostream>
#include "ImageElaborator.h"

//typedef shared_ptr<vector<vector<int>>> QuantumPointer;

ImageElaborator::ImageElaborator(string path) {
    setImage(path);
    // TODO undoPtr = new UndoManager(); ... deve passare i 4 puntatori ai vettori (*reds *greens *blues *alphas) ... metterlo in tutti i costruttori
} //Order: OK, compilier knows 'setImage()' exists
ImageElaborator::ImageElaborator() {}

void ImageElaborator::setImage(string path) {
    shared_ptr<Image> p(new Image(path)); //I need to use this temporary shared ptr, for some reason if i do img = new Image(path) it doesn't work. It doesn't work if I do Image i(path); img = &i; either
    img = p;
    imgToVectors();
    if(!undoPtr)
        delete undoPtr;
    undoPtr = new UndoManager(&reds, &greens, &blues, &alphas);
    if(!filterApplyer_)
        filterApplyer_ = NULL;
    filterApplyer_ = make_shared<FilterApplyer>(&reds, &greens, &blues, &alphas, undoPtr);
}

void ImageElaborator::imgToVectors() {
    reds.resize(img->rows());
    reds.reserve(img->rows());
    //cout << "The vector height is:    " << reds.size() << "\tAnd width is: " << reds.at(0).size() << endl;
    //same for greens, blues and alphas
    greens.resize(img->rows());
    greens.reserve(img->rows());

    blues.resize(img->rows());
    blues.reserve(img->rows());

    alphas.resize(img->rows());
    alphas.reserve(img->rows());

    //cout << "The image height is: " << img.size().height() << " The image width is: " << img.size().width();

    Color pixColor;
    for(unsigned int i = 0; i < img->rows(); i++){
        reds.at(i).resize(img->columns());
        reds.at(i).reserve(img->columns());
        alphas.at(i).resize(img->columns());
        alphas.at(i).reserve(img->columns());
        blues.at(i).resize(img->columns());
        blues.at(i).reserve(img->columns());
        greens.at(i).resize(img->columns());
        greens.at(i).reserve(img->columns());
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
void ImageElaborator::renderImage() {
    Image elaboratedImage(Geometry(img->size().width(),img->size().height()), Color(QuantumRange, QuantumRange, QuantumRange, QuantumRange));
    for(unsigned int i = 0; i < elaboratedImage.size().height(); i++){
        for(unsigned int j = 0; j < elaboratedImage.size().width(); j++){
            elaboratedImage.pixelColor(j,i, Color(reds.at(i).at(j), greens.at(i).at(j), blues.at(i).at(j), 255));
            //std::cout << "i = " << i << "\tj = " << j << std::endl;
        }
    }
    *img = elaboratedImage;
}

QImage ImageElaborator::getQTimage() {
    QImage immagineQT(img->size().width(), img->size().height(), QImage::Format_RGB16);
    immagineQT.fill(0);
    for(unsigned int i = 0; i < immagineQT.height(); i++){
        for(unsigned int j = 0; j < immagineQT.width(); j++){
            immagineQT.setPixelColor(j,i,QColor(reds.at(i).at(j), greens.at(i).at(j), blues.at(i).at(j), alphas.at(i).at(j)));
            //std::cout << "i = " << i << "\tj = " << j << std::endl;
        }
    }
    return immagineQT;
}


void ImageElaborator::notify(){
    for(Observer* observer : observers){
        observer->update();
    }
}

void ImageElaborator::saveImage(std::string path) {
    //FIXME prima di fare il write è necessario (e sufficente) modificare l'immagine stessa
    renderImage();
    img->write(path);
}