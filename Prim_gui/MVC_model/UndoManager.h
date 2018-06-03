//
// Created by barti on 20/08/17.
//

#ifndef PRIM_UNDOMANAGER_H
#define PRIM_UNDOMANAGER_H

#include <stack>
#include <Magick++.h>
#include <vector>
#include <memory>

using namespace Magick;
using namespace std;
typedef vector<vector<int>> QuantumValues;
typedef shared_ptr<vector<vector<int>>> QuantumPointer;

class UndoManager {
public:
    UndoManager(QuantumPointer reds, QuantumPointer greens, QuantumPointer blues, QuantumPointer alphas);
    void undo();
    void redo();
    void update();
    void updateRedo();
    virtual ~UndoManager() = default;

private:
    int nUndoAvailable = 0;
    int nUndoElements = 0;
    int firstUndo = 0;
    int lastUndo = -1;
    int nRedoAvailable = 0;
    int nRedoElements = 0;
    int firstRedo = 0;
    int lastRedo = -1;
    const int maxOps = 5;
    unique_ptr<QuantumValues[]> redsUndoArrayPointer{new QuantumValues[maxOps]};
    unique_ptr<QuantumValues[]> greensUndoArrayPointer{new QuantumValues[maxOps]};
    unique_ptr<QuantumValues[]> bluesUndoArrayPointer{new QuantumValues[maxOps]};
    unique_ptr<QuantumValues[]> alphasUndoArrayPointer{new QuantumValues[maxOps]};

    unique_ptr<QuantumValues[]> redsRedoArrayPointer{new QuantumValues[maxOps]};
    unique_ptr<QuantumValues[]> greensRedoArrayPointer{new QuantumValues[maxOps]};
    unique_ptr<QuantumValues[]> bluesRedoArrayPointer{new QuantumValues[maxOps]};
    unique_ptr<QuantumValues[]> alphasRedoArrayPointer{new QuantumValues[maxOps]};

    QuantumPointer origReds;
    QuantumPointer origBlues;
    QuantumPointer origGreens; // questi sono gli stessi puntatori che usa l'ImageElaborator
    QuantumPointer origAlphas;

};


#endif //PRIM_UNDOMANAGER_H
