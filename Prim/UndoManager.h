//
// Created by barti on 20/08/17.
//

#ifndef PRIM_UNDOMANAGER_H
#define PRIM_UNDOMANAGER_H

#include <stack>
#include <Magick++.h>
#include "RedoManager.h"
#include <vector>

using namespace Magick;
using namespace std;
typedef vector<vector<int>>* QuantumPointer;
typedef vector<vector<int>> QuantumValues;

class UndoManager {
public:
    UndoManager(QuantumPointer reds, QuantumPointer greens, QuantumPointer blues, QuantumPointer alphas);
    void reset();
    void undo();
    void update();
    RedoManager* redoptr;

private:
    void notifyRedo(){redoptr->update();}
    QuantumValues firstReds;
    QuantumValues firstGreens; // valori dell'immagine di partenza
    QuantumValues firstBlues;
    QuantumValues firstAlphas;
    QuantumPointer origReds;
    QuantumPointer origBlues;
    QuantumPointer origGreens; // questi sono gli stessi puntatori che usa l'ImageElaborator
    QuantumPointer origAlphas;
    vector<QuantumValues> redsUndoVector;
    vector<QuantumValues> greensUndoVector; // questi sono i valori
    vector<QuantumValues> bluesUndoVector;
    vector<QuantumValues> alphasUndoVector;
};
//TODO usare 4 vector di quantum pointers
//TODO creare il costruttore di copia

#endif //PRIM_UNDOMANAGER_H
