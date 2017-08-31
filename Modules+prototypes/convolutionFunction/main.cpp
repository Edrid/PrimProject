#include <iostream>
#include <memory>
#include <vector>

//TODO VEDI COME FUNZIONA SIA REFERENZA CHE PASSAGGIO PER VALORE, REFERENZA È PERÒ PIÙ 'LEGGERA'!
void myFunction(std::vector<std::vector<int>> &myVec){
    std::cout << std::endl;
    std::cout << std::endl;

    for(int i = 0; i < (int)myVec.size(); i++){
        for(int j = 0; j < (int)myVec.at(i).size(); j++){
            std::cout << myVec.at(i).at(j);
        }
        std::cout << std::endl;
    }
}

std::vector<std::vector<int>> convolute(std::vector<std::vector<int>> &original, std::vector<std::vector<int>> &convMat){

    std::cout << "Called convolution function" << std::endl;

    //TODO controllare di, eventualmente, non aver invertito length e height
    unsigned long length = original.at(0).size();
    unsigned long height = original.size();

    int convMatLength = (int)convMat.at(0).size();
    int convMatHeight= (int)convMat.size();
    //std::vector<std::vector<int>> mat(rows, std::vector<int>(cols,0));
    std::vector<std::vector<int>> convoluted(original.size(), std::vector<int>(original.at(0).size()));


    std::vector<std::vector<int>> convolutedMat(height, std::vector<int>(5));

    /*int convSum = 0;
    //Calcola la somma degli elementi della matrice di convoluzione (nel caso serva la normalizzazione: non in questo caso)
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            convSum = convSum + convMat[i][j];
        }
    }*/

    //LA LOGICA È DA QUI IN POI
    int sum = 0;
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
            convoluted.at(k).at(s) = sum;
        }
    }

    return convoluted;

}

int main() {
    /*int myMat[5][4] = {{1,2,3,4},{1,2,3,4},{2,3,4,5},{3,4,5,6},{4,5,6,7}};

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 4; j++){
            std::cout << " " << myMat[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    myFunction(myMat);*/

    //NOTE TO MYSELF: quando si inizializza un vector, tutti gli elementi sono pari a zero se non altrimenti specificato
    std::vector<std::vector<int>> pippo(20, std::vector<int>(4));

    int size = pippo.size();
    std::cout << "Size of pippo is: " << size << std::endl;
    std::cout << "Size of elements of pippo is: " << pippo.at(0).size() << std::endl;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < pippo.at(0).size(); j++){
            std::cout << "\t" << pippo.at(i).at(j);
        }
        std::cout << std::endl;
    }

    int rows = 5, cols = 4;

    std::vector<std::vector<int>> mat(rows, std::vector<int>(cols,0));
    mat[3][1] = 3; //FUNZIONA ANCHE QUESTA SINTASSI!!!!
    /*for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            std::cout << mat.at(i).at(j);
        }
        std::cout << std::endl;
    }
*/
    myFunction(mat);

    //sia wins una matrice 8x3
    /*int wins[8][3] = {{1,2,3},{4,5,6},{7,8,9},{10,11,12},{13,14,15},{16,17,18},{19,20,21},{22,23,24}};
    int* start = &wins[0][0];
    std::vector<int> vwins(start, start+(8*3));

    for(int i = 0; i < vwins.size(); i++){
        std::cout << "\n\t" << vwins.at(i);
    }

    std::cout << "This is the element at position [3][2]" << vwins[3];
*/

    ///--------------------------------------///
    std::vector<std::vector<int>> image = {{8,1,3,2,2},{1,2,1,0,3},{2,0,1,0,2},{3,1,2,0,1},{2,1,3,2,1},{2,0,1,0,0}};
    std::vector<std::vector<int>> convMatrix = {{-1,-1,-1},{-1,8,-1},{-1,-1,-1}};

    for(int i = 0; i < image.size(); i++){
        for(int j = 0; j < image.at(0).size(); j++){
            std::cout << "\t" << image.at(i).at(j);
        }
        std::cout << "\n";
    }


    std::vector<std::vector<int>> convImage = convolute(image, convMatrix);

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 5; j++){
            std::cout << "\t" << convImage[i][j];
        }
        std::cout << std::endl;
    }

}

