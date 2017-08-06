#include <iostream>
#include <Magick++.h>

using namespace Magick;
std::vector<std::vector<int>> changeRed(Image& img, int changeValue);
std::vector<std::vector<int>> changeGreen(Image& img, int changeValue);
std::vector<std::vector<int>> changeBlue(Image& img, int changeValue);
std::vector<std::vector<int>> changeAlpha(Image& img, int changeValue);
std::vector<std::vector<int>> changeValue(std::vector<std::vector<int>> &originalVal, int changeValue);


int main(int argc,char **argv) {
    InitializeMagick(*argv);

    Image myImg("/home/edoardo/Pictures/LalaMagick.jpg");
    myImg.display();

    std::vector<std::vector<int>> reds(myImg.rows(), std::vector<int>(myImg.columns()));

    for(int i = 0; i < myImg.rows(); i++){
        for(int j = 0; j < myImg.columns(); j++){
            reds.at(i).at(j) = (int) myImg.pixelColor(j,i).quantumRed(); //Attenzione: prima x e poi y
        }
    }

    reds = changeValue(myImg, 255);

    Image newImage("640x480", "white");

    for(int i = 0; i < newImage.rows(); i++){
        for(int j = 0; j < newImage.columns(); j++){
            newImage.pixelColor(j,i,Color(reds.at(i).at(j), myImg.pixelColor(j,i).quantumGreen(), myImg.pixelColor(j,i).quantumBlue(),myImg.pixelColor(j,i).quantumAlpha())); //TODO OPTIMIZE, EVITA DI RICHIAMARE OGNI VOLTA PIXELCOLOR FACENDO UNA VARIABILE
        }
    }
    newImage.display();


    return 0;
}

std::vector<std::vector<int>> changeValue(std::vector<std::vector<int>> &originalVal, int changeValue){
    std::vector<std::vector<int>> newVal(originalVal.size(), std::vector<int>(originalVal.at(0).size()));
    int value = 0;
    for(int i = 0; i < originalVal.size(); i++){
        for(int j = 0; j < originalVal.at(0).size(); j++){
            value = originalVal.at(i).at(j);
            //TODO generalize this whole thing for the QuantumBlue and QuantumGreen
            value = value + changeValue;
            if(value > 255){
                value = 255;
            } else if(value < 0){
                value = 0;
            }
            newVal.at(i).at(j) = value;
        }
    }

    return newVal;
}
//TODO implement color changes modularities
Image changeRed(Image& img, int changeValue){
    std::vector<std::vector<int>> reds(img.rows(), std::vector<int>(img.columns()));
    reds = changeValue(&reds, changeValue);

}
Image changeGreen(Image& img, int changeValue){}
Image changeBlue(Image& img, int changeValue){}
Image changeAlpha(Image& img, int changeValue){}


