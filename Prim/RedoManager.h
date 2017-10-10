//
// Created by barti on 20/08/17.
//

#ifndef PRIM_REDOMANAGER_H
#define PRIM_REDOMANAGER_H

#include <Magick++.h>
#include <stack>

using namespace Magick;
using namespace std;
typedef vector<vector<int>>* QuantumPointer;
typedef vector<vector<int>> QuantumValues;

class RedoManager {
public:
    RedoManager(QuantumPointer reds, QuantumPointer greens, QuantumPointer blues, QuantumPointer alphas) : origReds(reds), origGreens(greens), origBlues(blues), origAlphas(alphas){}
    void update();
    void redo();
    void reset(){redsRedoVector.clear(); greensRedoVector.clear(); bluesRedoVector.clear(); alphasRedoVector.clear();}

private:
    QuantumPointer origReds;
    QuantumPointer origBlues;
    QuantumPointer origGreens;
    QuantumPointer origAlphas;
    vector<QuantumValues> redsRedoVector;
    vector<QuantumValues> greensRedoVector;
    vector<QuantumValues> bluesRedoVector;
    vector<QuantumValues> alphasRedoVector;
};


#endif //PRIM_REDOMANAGER_H
