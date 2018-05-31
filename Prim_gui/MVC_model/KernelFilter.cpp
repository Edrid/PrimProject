//
// Created by edoardo on 16/08/17.
//

#include "KernelFilter.h"

#include <Magick++.h>
#include <vector>
#include <memory>

vector<vector<int>> KernelFilter::convolute(vector<vector<int>> *original, bool normalized) {

    unsigned long height = original->size();
    unsigned long width = original->at(0).size();

    const int maxQRange = 255;

    int convMatLength = (int) convMatrix.at(0).size();
    int convMatHeight = (int) convMatrix.size(); //in realtà la matrice di convoluzione è QUADRATA, dunque è sufficiente sapere una sola dimensine

    std::vector<std::vector<int>> convoluted(original->size(), std::vector<int>(original->at(0).size()));

    int convSum = 0;
    //Calcola la somma degli elementi della matrice di convoluzione (nel caso serva la normalizzazione: non in questo caso)
    //We usually know the sum, but for the time being I let the program calculate it every time
    for(int i = 0; i < convMatHeight; i++){
        for(int j = 0; j < convMatLength; j++){
            convSum = convSum + convMatrix[i][j];
        }
    }

    float sum = 0;
    int it1 = -1, it2 = -1;
    //I primi due cicli sono definiti per tutta l'immagine
    for (unsigned long k = 1; k < height - 1; k++) { //6-1
        for (unsigned long s = 1; s < width - 1; s++) { //5-1
            sum = 0;
            it1 = -1;
            //I due cicli seguenti definiscono il comportamento per ogni pixel
            for (int i = 0; i < convMatHeight; i++) { //3 perchè ho scelto, in questo esempio, una matrice di convoluzione 3x3
                it2 = -1;
                for (int j = 0; j < convMatLength; j++) {
                    //std::cout << "Image pixel at k+it1,s+it2 is: " << image[k+it1][s+it2] << std::endl << "convMat value is: \t\t" << convMat[i][j] << std::endl;
                    sum = sum + original->at(k + it1).at(s + it2) * convMatrix.at(i).at(j);
                    it2++;
                }
                it1++;
            }
            if(normalized)
                sum = sum/convSum; //divide only if the sum has to be normalised e.g. gaussian NOTE: if I don't normalize the values
            if(sum < 0)
                sum = 0;
            if(sum > maxQRange)
                sum = maxQRange;
            //std::cout << "Sum = " << sum%256 << std::endl;
            convoluted.at(k).at(s) = sum;
           //std::cout << "convoluted =" << convoluted.at(k).at(s) <<std::endl;
            //std::cout << "" << k;
            // std::cout << "" << s;
        }
    }
    return convoluted;
}