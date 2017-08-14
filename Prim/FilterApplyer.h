//
// Created by edoardo on 14/08/17.
//

#ifndef PRIM_FILTERAPPLYER_H
#define PRIM_FILTERAPPLYER_H

#include <iostream>
#include <vector>
#include <memory>

using namespace std;
typedef shared_ptr<vector<vector<int>>> QuantumPointer; //Careful, this definition needs to be after the 'using namespace', otherwise the compiler doesn't know the definition for std::vector or std::shared_ptr

//TODO some filters need normalizzation, others don't
enum class filterType{GaussianBlur, EdgeDetection, Sharpen, BoxBlur};



class FilterApplyer {
public:
    FilterApplyer(QuantumPointer reds, QuantumPointer greens, QuantumPointer blues, QuantumPointer alphas) : redsp(reds), greensp(greens), bluesp(blues), alphasp(alphas){}
    FilterApplyer();
    void applyFilter(); //this method has all the necessary information to elaborate the quantums. TODO make sure that the quantum information is always updated (though they should be.. they're pointers after all)
    void setFilter();
private:
    //A questo punto cambio i valori dei vettori e faccio renderizzare l'immagine all'ImageElaborator. TODO prima di chiamare qualunque metodo nell'ImageElaborator, assicurarsi che ci sia una chiamata all'undo manager
    QuantumPointer redsp;
    QuantumPointer greensp;
    QuantumPointer bluesp;
    QuantumPointer alphasp;

};


#endif //PRIM_FILTERAPPLYER_H
