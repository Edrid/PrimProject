//
// Created by edoardo on 14/08/17.
//

#ifndef PRIM_FILTERAPPLYER_H
#define PRIM_FILTERAPPLYER_H

#include <iostream>
#include <vector>
#include <memory>

using namespace std;
typedef vector<vector<int>>* QuantumPointer; //Here I use 'raw' pointers for ease of the implementation. Later maybe change them with smart pointers, but after all 'Premature optimization is the root of all evil'

//TODO some filters need normalizzation, others don't
enum class filterType{GaussianBlur, EdgeDetection, Sharpen, BoxBlur};



class FilterApplyer {
public:
    FilterApplyer(QuantumPointer reds, QuantumPointer greens, QuantumPointer blues, QuantumPointer alphas) : reds_(reds), greens_(greens), blues_(blues), alphas_(alphas){}
    FilterApplyer();
    void applyFilter(); //this method has all the necessary information to elaborate the quantums. TODO make sure that the quantum information is always updated (though they should be.. they're pointers after all)
    void setFilter();
private:
    //A questo punto cambio i valori dei vettori e faccio renderizzare l'immagine all'ImageElaborator. TODO prima di chiamare qualunque metodo nell'ImageElaborator, assicurarsi che ci sia una chiamata all'undo manager
    /*QuantumPointer redsp;
    QuantumPointer greensp;
    QuantumPointer bluesp;
    QuantumPointer alphasp;*/
    QuantumPointer reds_;
    QuantumPointer greens_;
    QuantumPointer blues_;
    QuantumPointer alphas_;



};


#endif //PRIM_FILTERAPPLYER_H
