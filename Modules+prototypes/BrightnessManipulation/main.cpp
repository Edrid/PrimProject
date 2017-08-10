#include <iostream>
#include <Magick++.h>

using namespace Magick;
Image changeRed(Image img, int changeValue);
Image changeGreen(Image img, int changeValue);
Image changeBlue(Image img, int changeValue);
Image changeAlpha(Image img, int changeValue);
Image changeValue(Image img, int changeValue);
Image permuteBRG(Image img);
Image permuteGRB(Image img);
Image permuteBGR(Image img);


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

    //myImg = changeBlue(myImg, 255);
    //myImg = changeGreen(myImg, 255);
    Image newImage("640x480", "white");
    newImage = permuteBRG(myImg);
    newImage.display();

    newImage = permuteGRB(myImg);
    newImage.display();

    newImage = permuteBGR(myImg);
    newImage.display();

    myImg = changeRed(myImg, 255);
    myImg.display();



    //TODO  PER SBAGLIO SUCCEDE IL SEGUENTE: SE METTO IL RED AL MASSIMO, POI FACCIO ESEGUIRE IL SOTTOSTANTE CICLO, L'IMMAGINE VIENE DECOLORIZZATA IN TUTTI I COLORI TRANNE CHE ROSSO

    for(int i = 0; i < newImage.rows(); i++){
        for(int j = 0; j < newImage.columns(); j++){
            newImage.pixelColor(j,i,Color(reds.at(i).at(j), myImg.pixelColor(j,i).quantumGreen(), myImg.pixelColor(j,i).quantumBlue(),myImg.pixelColor(j,i).quantumAlpha())); //TODO OPTIMIZE, EVITA DI RICHIAMARE OGNI VOLTA PIXELCOLOR FACENDO UNA VARIABILE
        }
    }

    newImage.display();



    return 0;
}
/*
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
}*/
//TODO implement color changes modularities
Image changeRed(Image img, int changeValue){
    std::vector<std::vector<int>> reds(img.rows(), std::vector<int>(img.columns()));
    int value = 0;
    Image newImage(Geometry(img.size().width(), img.size().height()), "white");
    for(int i = 0; i < img.rows(); i++){
        for(int j = 0; j < img.columns(); j++){
            value = img.pixelColor(j,i).quantumRed();
            value+=changeValue;
            if(value > 255){
                value = 255;
            } else if(value < 0){
                value = 0;
            }
            //alternatively I could only modify the image pixel.. though I then wouldn't have a copy for the undo/redo stack
            newImage.pixelColor(j,i,Color(value, img.pixelColor(j,i).quantumGreen(), img.pixelColor(j,i).quantumGreen(),img.pixelColor(j,i).quantumBlue(),img.pixelColor(j,i).quantumAlpha()));
        }
    }
    return newImage;
}


Image changeGreen(Image img, int changeValue){
    std::vector<std::vector<int>> green(img.rows(), std::vector<int>(img.columns()));
    int value = 0;
    Image newImage(Geometry(img.size().width(), img.size().height()), "white");
    for(int i = 0; i < img.rows(); i++){
        for(int j = 0; j < img.columns(); j++){
            value = img.pixelColor(j,i).quantumGreen();
            value+=changeValue;
            if(value > 255){
                value = 255;
            } else if(value < 0){
                value = 0;
            }
            //alternatively I could only modify the image pixel.. though I then wouldn't have a copy for the undo/redo stack
            newImage.pixelColor(j,i,Color(img.pixelColor(j,i).quantumRed(), value, img.pixelColor(j,i).quantumGreen(),img.pixelColor(j,i).quantumBlue(),img.pixelColor(j,i).quantumAlpha()));
        }
    }
    return newImage;
}
Image changeBlue(Image img, int changeValue){
    std::vector<std::vector<int>> blues(img.rows(), std::vector<int>(img.columns()));
    int value = 0;
    Image newImage(Geometry(img.size().width(), img.size().height()), "white");
    for(int i = 0; i < img.rows(); i++){
        for(int j = 0; j < img.columns(); j++){
            value = img.pixelColor(j,i).quantumGreen();
            value+=changeValue;
            if(value > 255){
                value = 255;
            } else if(value < 0){
                value = 0;
            }
            //alternatively I could only modify the image pixel.. though I then wouldn't have a copy for the undo/redo stack
            newImage.pixelColor(j,i,Color(img.pixelColor(j,i).quantumRed(), img.pixelColor(j,i).quantumGreen(), value, img.pixelColor(j,i).quantumAlpha()));
        }
    }
    return newImage;
}
Image changeAlpha(Image img, int changeValue){
    std::vector<std::vector<int>> alphas(img.rows(), std::vector<int>(img.columns()));
    int value = 0;
    Image newImage(Geometry(img.size().width(), img.size().height()), "white");
    for(int i = 0; i < img.rows(); i++){
        for(int j = 0; j < img.columns(); j++){
            value = img.pixelColor(j,i).quantumGreen();
            value+=changeValue;
            if(value > 255){
                value = 255;
            } else if(value < 0){
                value = 0;
            }
            //alternatively I could only modify the image pixel.. though I then wouldn't have a copy for the undo/redo stack
            newImage.pixelColor(j,i,Color(img.pixelColor(j,i).quantumRed(), img.pixelColor(j,i).quantumGreen(), img.pixelColor(j,i).quantumBlue(), value));
        }
    }
    return newImage;
}

Image permuteBRG(Image img){
    //Provo a vedere cosa succede permutando i valori RGB
    for(int i = 0; i < img.rows(); i++) {
        for (int j = 0; j < img.columns(); j++) {
            img.pixelColor(j, i, Color(img.pixelColor(j, i).quantumBlue(), img.pixelColor(j, i).quantumRed(),
                                       img.pixelColor(j, i).quantumGreen(), img.pixelColor(j, i).quantumAlpha()));
        }
    }
    return img;
}

Image permuteGRB(Image img){
    //Provo a vedere cosa succede permutando i valori RGB
    for(int i = 0; i < img.rows(); i++) {
        for (int j = 0; j < img.columns(); j++) {
            img.pixelColor(j, i, Color(img.pixelColor(j, i).quantumGreen(), img.pixelColor(j, i).quantumBlue(), img.pixelColor(j, i).quantumRed(),
                                        img.pixelColor(j, i).quantumAlpha()));
        }
    }
    return img;
}

Image permuteBGR(Image img){
    for(int i = 0; i < img.rows(); i++) {
        for (int j = 0; j < img.columns(); j++) {
            img.pixelColor(j, i, Color(img.pixelColor(j, i).quantumBlue(), img.pixelColor(j, i).quantumGreen(), img.pixelColor(j, i).quantumRed(),
                                       img.pixelColor(j, i).quantumAlpha()));
        }
    }
    return img;
}

/*std::vector<std::vector<int>> changeValue(std::vector<std::vector<int>> vals, int changeValue){
    int width = vals.at(0).size(), height = vals.size();
    std::vector<std::vector<int>> vals(height, std::vector<int>(width));

    Image newImage(Geometry(width, height), "white");
    int newVal = 0;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            newVal = vals.at(i).at(j);
            newVal+=changeValue;
            if(newVal > 255)
                newVal = 255;
        }
    }
    return vals;

}*/

/* -----------THOUGHT SPACE-------------- */

/*  Figure out a way to avoid code repetition.. maybe preprocessing or generic programming?
 * */