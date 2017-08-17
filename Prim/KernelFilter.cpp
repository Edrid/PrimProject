//
// Created by edoardo on 16/08/17.
//

#include "KernelFilter.h"

#include <Magick++.h>
#include <vector>
#include <memory>

vector<vector<int>> KernelFilter::convolute(vector<vector<int>> originalVals) { //TODO
    unsigned int height = originalVals.size();
    unsigned int width = originalVals.at(0).size();
}
    int it1 = -1, it2 = -1; //TODO fix it1 and it2: they work only if the convolution matrix is 3x3
    for(unsigned long k = 1; k < height-1; k++){ //6-1
        for(unsigned long s = 1; s < length-1; s++) { //5-1
            sum = 0;
            it1 = -1;
            for (int i = 0;
                 i < convMatHeight; i++) { //3 perchè ho scelto, in questo esempio, una matrice di convoluzione 3x3
                it2 = -1;
                for (int j = 0; j < convMatLength; j++) {
                    //TODO fare tutta la logica i.e. somma dei valori e divisione per totale della matrice di convoluzione, aggiungere matrice di convoluzione
                    //std::cout << "Image pixel at k+it1,s+it2 is: " << image[k+it1][s+it2] << std::endl << "convMat value is: \t\t" << convMat[i][j] << std::endl;
                    sum = sum + original.at(k + it1).at(s + it2) * convMat.at(i).at(j);
                    it2++;
                }
                it1++;
            }
        }

} //TODO
