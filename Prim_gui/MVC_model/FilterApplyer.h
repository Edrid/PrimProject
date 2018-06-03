//
// Created by edoardo on 14/08/17.
//

#ifndef PRIM_FILTERAPPLYER_H
#define PRIM_FILTERAPPLYER_H

#include <Magick++.h>
#include <vector>
#include <memory>
#include "KernelFilter.h"
#include "UndoManager.h"

using namespace std;
typedef shared_ptr<vector<vector<int>>> QuantumPointer; //Here I use 'raw' pointers for ease of the implementation. Later maybe change them with smart pointers, but after all 'Premature optimization is the root of all evil'

//NOTE: some filters need normalizzation, others don't
enum class FilterTypes{GaussianBlur, EdgeDetection, Sharpen, Emboss};



class FilterApplyer {
public:
    FilterApplyer(QuantumPointer reds, QuantumPointer greens, QuantumPointer blues, QuantumPointer alphas, shared_ptr<UndoManager> undoPtr) : reds_(reds), greens_(greens), blues_(blues), alphas_(alphas), undoPtr(undoPtr){}
    //FilterApplyer();
    void kernelFilter(); //this method has all the necessary information to elaborate the quantums.
    void setKernelStrategy(FilterTypes filterID);

 //   void setUndoPtr(UndoManager *undoPtr);

private:
    void notifyUndo();
    //A questo punto cambio i valori dei vettori e faccio renderizzare l'immagine all'ImageElaborator. DONE prima di chiamare qualunque metodo nell'ImageElaborator, assicurarsi che ci sia una chiamata all'undo manager
    QuantumPointer reds_;
    QuantumPointer greens_;
    QuantumPointer blues_;
    QuantumPointer alphas_;
    KernelFilter *strategy_; //STRATEGY FIXME nota: il puntatore dello strategy è ben gestito dal delete
    shared_ptr<UndoManager> undoPtr;

};


#endif //PRIM_FILTERAPPLYER_H
