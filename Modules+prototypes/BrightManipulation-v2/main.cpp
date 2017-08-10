#include <iostream>
#include <Magick++.h>

using namespace Magick;

std::vector<std::vector<int>> changeValue(std::vector<std::vector<int>> channelLevel, int value);

int main(int argc,char **argv) {
    InitializeMagick(*argv);

    Image img("/home/edoardo/Pictures/LalaMagick.jpg");
    img.display();

    std::vector<std::vector<int>> reds(img.size().height(), std::vector<int>((int)img.size().width()));
    std::vector<std::vector<int>> greens(img.size().height(), std::vector<int>((int)img.size().width()));
    std::vector<std::vector<int>> blues(img.size().height(), std::vector<int>((int)img.size().width()));
    std::vector<std::vector<int>> alphas(img.size().height(), std::vector<int>((int)img.size().width()));

    Color pixColor;
    for(unsigned int i = 0; i < img.rows(); i++){
        for(unsigned int j = 0; j < img.columns(); j++){
            pixColor = img.pixelColor(j,i);
            alphas.at(i).at(j) = (int)pixColor.quantumAlpha();
            reds.at(i).at(j) = (int)pixColor.quantumRed();
            greens.at(i).at(j) = (int)pixColor.quantumGreen();
            blues.at(i).at(j) = (int)pixColor.quantumBlue();
        }
    }

    Image elaboratedImage(Geometry(img.size().width(),img.size().height()), Color(QuantumRange, QuantumRange, QuantumRange, 200));
    elaboratedImage.display();

    reds = changeValue(reds, -255);
    greens = changeValue(greens, -255);

    for(unsigned int i = 0; i < elaboratedImage.size().height(); i++){
        for(unsigned int j = 0; j < elaboratedImage.size().width(); j++){
            elaboratedImage.pixelColor(j,i, Color(reds.at(i).at(j), greens.at(i).at(j), blues.at(i).at(j), 255));
            //std::cout << "i = " << i << "\tj = " << j << std::endl;
        }
    }
    elaboratedImage.display();

}

std::vector<std::vector<int>> changeValue(std::vector<std::vector<int>> channelLevel, int value){
    int newVal = 0;
    for(int i = 0; i < channelLevel.size(); i++){
        for(int j = 0; j < channelLevel.at(0).size(); j++){
            newVal = channelLevel.at(i).at(j) + value;
            if(newVal > 255)
                channelLevel.at(i).at(j) = 255;
            else if(newVal < 0)
                channelLevel.at(i).at(j) = 0;
        }
    }
    //non faccio un vettore di appoggio perchè non ne necessito, a meno che non usi una referenza o puntatore, la variabile di argomento è solo una copia della variabile originale
    return channelLevel;

}
