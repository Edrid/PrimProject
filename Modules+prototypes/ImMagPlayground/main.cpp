#include <iostream>
#include <Magick++.h>

using namespace Magick;

std::vector<std::vector<int>> convolute(std::vector<std::vector<int>> &original, std::vector<std::vector<int>> &convMat){

    //std::cout << "\nCalled convolution function" << std::endl;

    //TODO controllare di, eventualmente, non aver invertito length e height
    unsigned long  length = original.at(0).size();
    unsigned long height = original.size();

    int convMatLength = (int)convMat.at(0).size();
    int convMatHeight= (int)convMat.size();
    //std::vector<std::vector<int>> mat(rows, std::vector<int>(cols,0));
    std::vector<std::vector<int>> convoluted(original.size(), std::vector<int>(original.at(0).size()));


    std::vector<std::vector<int>> convolutedMat(height, std::vector<int>(5));

    int convSum = 0;
    //Calcola la somma degli elementi della matrice di convoluzione (nel caso serva la normalizzazione: non in questo caso)
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            convSum = convSum + convMat[i][j];
        }
    }
    std::cout << "ConvSum is " << convSum << std::endl;
    //LA LOGICA È DA QUI IN POI
    float sum = 0;
    int it1 = -1, it2 = -1; //TODO fix it1 and it2: they work only if the convolution matrix is 3x3
    for(unsigned long k = 1; k < height-1; k++){ //6-1
        for(unsigned long s = 1; s < length-1; s++){ //5-1
            sum = 0;
            it1 = -1;
            for(int i = 0; i < convMatHeight; i++){ //3 perchè ho scelto, in questo esempio, una matrice di convoluzione 3x3
                it2 = -1;
                for(int j = 0; j < convMatLength; j++){
                    //TODO fare tutta la logica i.e. somma dei valori e divisione per totale della matrice di convoluzione, aggiungere matrice di convoluzione
                    //std::cout << "Image pixel at k+it1,s+it2 is: " << image[k+it1][s+it2] << std::endl << "convMat value is: \t\t" << convMat[i][j] << std::endl;
                    sum = sum + original.at(k+it1).at(s+it2)*convMat.at(i).at(j);
                    it2++;
                }
                it1++;
            }
            //std::cout << "Sum = " << sum << std::endl;
            //QUICKFIX for the case of pixels <256 or pixels < 0
            //sum = sum/convSum; //divide only if the sum has to be normalised e.g. gaussian

            if(sum < 0)
                sum = -sum;
            //std::cout << "Sum = " << sum%256 << std::endl;
            convoluted.at(k).at(s) = sum;
        }
    }

    return convoluted;

}


int main(int argc,char **argv) {
    InitializeMagick(*argv);
    std::cout << "The quantum range is: " << (int)QuantumRange << std::endl;

    Image img("/home/edoardo/Pictures/LalaMagick.jpg");
    /*img.display();

    Quantum r = 255, g = 255, b = 255;

    int a = r;
    std::cout << "a = " << r << std::endl;

    Color colore;
    //this block transforms sets the entire image to white
    for(int i = 0; i < 640; i++){
        for(int j = 0; j < 480; j++){
            colore.quantumBlue(b);
            colore.quantumRed(r);
            colore.quantumGreen(g);
            img.pixelColor(i,j,colore);
        }
    }

    img.display();*/
    std::vector<std::vector<int>> reds(img.size().height(), std::vector<int>((int)img.size().width()));
    std::vector<std::vector<int>> greens(img.size().height(), std::vector<int>((int)img.size().width()));
    std::vector<std::vector<int>> blues(img.size().height(), std::vector<int>((int)img.size().width()));
    std::vector<std::vector<Quantum>> alphas(img.size().height(), std::vector<Quantum>((int)img.size().width()));

    std::cout << "The image height is: " << img.size().height() << " The image width is: " << img.size().width();

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
    //elaboratedImage.display();
    //std::vector<std::vector<int>> convMatrix = {{1,2,1},{2,4,2},{1,2,1}}; //This is the gaussian blur kernel
    std::vector<std::vector<int>> convMatrix = {{-1,-1,-1},{-1,8,-1},{-1,-1,-1}}; //This is the gaussian blur kernel

    //Apply the convolution
    reds = convolute(reds, convMatrix);
    greens = convolute(greens, convMatrix);
    blues = convolute(blues, convMatrix);

    std::cout << "Reds height is: " << reds.size() << "\t and the width is: " << reds.at(0).size() << std::endl;
    std::cout << "Greens height is: " << greens.size() << "\t and the width is: " << greens.at(0).size() << std::endl;
    std::cout << "Blues height is: " << blues.size() << "\t and the width is: " << blues.at(0).size() << std::endl;

    std::cout << "Reds at 250, 500 is " << reds.at(250).at(500) << std::endl;
    std::cout << "Greens at 250, 500 is " << greens.at(250).at(500) << std::endl;
    std::cout << "Blues at 250, 500 is " << blues.at(250).at(500) << std::endl;


    //elaboratedImage.display();

    //TODO E' possibile che i pixel vadano out of range, tofix

    /*for(int i = 0; i < reds.size(); i++){
        for(int j = 0; j < reds.at(0).size(); j++){
            std::cout << " " << reds.at(i).at(j);
        }
        std::cout << std::endl;
    }*/


    for(unsigned int i = 0; i < elaboratedImage.size().height(); i++){
        for(unsigned int j = 0; j < elaboratedImage.size().width(); j++){
            elaboratedImage.pixelColor(j,i, Color(reds.at(i).at(j), greens.at(i).at(j), blues.at(i).at(j), 255));
            //std::cout << "i = " << i << "\tj = " << j << std::endl;
        }
    }
    img.display();
    elaboratedImage.display();

    return 0;
}