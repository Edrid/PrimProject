#include <iostream>
#include <Magick++.h>

using namespace Magick;

std::vector<std::vector<int>> changeRed(std::vector<std::vector<int>> &originalReds, int changeValue);


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

    reds = changeRed(reds, 255);

    Image newImage("640x480", "white");

    for(int i = 0; i < newImage.rows(); i++){
        for(int j = 0; j < newImage.columns(); j++){
            newImage.pixelColor(j,i,Color(reds.at(i).at(j), myImg.pixelColor(j,i).quantumGreen(), myImg.pixelColor(j,i).quantumBlue(),myImg.pixelColor(j,i).quantumAlpha())); //TODO OPTIMIZE, EVITA DI RICHIAMARE OGNI VOLTA PIXELCOLOR FACENDO UNA VARIABILE
        }
    }
    newImage.display();


    return 0;
}

std::vector<std::vector<int>> changeRed(std::vector<std::vector<int>> &originalReds, int changeValue){
    std::vector<std::vector<int>> newReds(originalReds.size(), std::vector<int>(originalReds.at(0).size()));
    int redValue = 0;
    for(int i = 0; i < originalReds.size(); i++){
        for(int j = 0; j < originalReds.at(0).size(); j++){
            redValue = originalReds.at(i).at(j);
            //TODO generalize this whole thing for the QuantumBlue and QuantumGreen
            redValue = redValue + changeValue;
            if(redValue > 255){
                redValue = 255;
            } else if(redValue < 0){
                redValue = 0;
            }
            newReds.at(i).at(j) = redValue;
        }
    }

    return newReds;

}
