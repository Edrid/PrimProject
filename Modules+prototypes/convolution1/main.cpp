#include <iostream>

int main() {
    int image[6][5] = {{8,1,3,2,2},{1,2,1,0,3},{2,0,1,0,2},{3,1,2,0,1},{2,1,3,2,1},{2,0,1,0,0}};
    //TODO vedere quando si deve normalizzare i pixel e quando non si deve
    int elaboratedImage[6][5] = {{0}}; //Deve essere delle stesse dimensioni dell'immagine originale
    int convMatrix[3][3] = {{-1,-1,-1},{-1,8,-1},{-1,-1,-1}};
    int convSum = 0;

    //Calcola la somma degli elementi della matrice di convoluzione (nel caso serva la normalizzazione: non in questo caso)
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            convSum = convSum + convMatrix[i][j];
        }
    }

    std::cout << "The convolution matrix sum is: " << convSum << std::endl;

    //Stampa la matrice di convoluzione
    std::cout << "Here's the convolution matrix: " << std::endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            std::cout << " " << convMatrix[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    //Stampa i "pixel" dell'immagine
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 5; j++){
            std::cout << " " << image[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;std::cout << std::endl;
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 5; j++){
            std::cout << " " << elaboratedImage[i][j];
        }
        std::cout << std::endl;
    }


    int sum = 0;
    int it1 = -1, it2 = -1;
    for(int k = 1; k < 5; k++){ //6-1
        for(int s = 1; s < 4; s++){ //5-1
            sum = 0;
            it1 = -1;
            for(int i = 0; i < 3; i++){ //3 perchè ho scelto, in questo esempio, una matrice di convoluzione 3x3
                it2 = -1;
                for(int j = 0; j < 3; j++){
                    //TODO fare tutta la logica i.e. somma dei valori e divisione per totale della matrice di convoluzione, aggiungere matrice di convoluzione
                    //std::cout << "Image pixel at k+it1,s+it2 is: " << image[k+it1][s+it2] << std::endl << "convMatrix value is: \t\t" << convMatrix[i][j] << std::endl;
                    sum = sum + image[k+it1][s+it2]*convMatrix[i][j];
                    it2++;
                }
                it1++;
            }
            elaboratedImage[k][s] = sum;
        }
    }

    std::cout << "\nHere's the convoluted matrix:" << std::endl;
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 5; j++){
            std::cout << "\t" << elaboratedImage[i][j];
        }
        std::cout << std::endl;
    }

}
