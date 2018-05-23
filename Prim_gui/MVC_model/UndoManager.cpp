//
// Created by barti on 20/08/17.
//

#include "UndoManager.h"

//FIXME fa un undo di troppo
UndoManager::UndoManager(QuantumPointer reds, QuantumPointer greens, QuantumPointer blues, QuantumPointer alphas) {
    origReds = reds;
    origGreens = greens;
    origBlues = blues;
    origAlphas = alphas;
    redsUndoArrayPointer = new QuantumValues[5];
    redsRedoArrayPointer = new QuantumValues[5];
    greensUndoArrayPointer = new QuantumValues[5];
    greensRedoArrayPointer = new QuantumValues[5];
    bluesUndoArrayPointer = new QuantumValues[5];
    bluesRedoArrayPointer = new QuantumValues[5];
    alphasUndoArrayPointer = new QuantumValues[5];
    alphasRedoArrayPointer = new QuantumValues[5];
}

void UndoManager::update() {
    if(nUndoElements < 6 ){                               // è un valore scelto da noi
        redsUndoArrayPointer[lastUndo] = *origReds;
        greensUndoArrayPointer[lastUndo] = *origGreens;
        bluesUndoArrayPointer[lastUndo] = *origBlues;
        alphasUndoArrayPointer[lastUndo] = *origAlphas;
        nUndoAvailable++;
        nUndoElements++;
        lastUndo = (lastUndo + 1) % 5;
    }
    else{
        redsUndoArrayPointer[firstUndo] = *origReds;
        greensUndoArrayPointer[firstUndo] = *origGreens;
        bluesUndoArrayPointer[firstUndo] = *origBlues;
        alphasUndoArrayPointer[firstUndo] = *origAlphas;
        lastUndo = (lastUndo + 1) % 5;
        firstUndo = (firstUndo + 1) % 5;
    }
}

void UndoManager::updateRedo() {
    if(nUndoElements < 6 ){
        redsRedoArrayPointer[lastRedo] = *origReds;
        greensRedoArrayPointer[lastRedo] = *origGreens;
        bluesRedoArrayPointer[lastRedo] = *origBlues;
        alphasRedoArrayPointer[lastRedo] = *origAlphas;
        nRedoElements++;
        nRedoAvailable++;
        lastRedo = (lastRedo + 1) % 5;
    }
    else{
        redsRedoArrayPointer[firstRedo] = *origReds;
        greensRedoArrayPointer[firstRedo] = *origGreens;
        bluesRedoArrayPointer[firstRedo] = *origBlues;
        alphasRedoArrayPointer[firstRedo] = *origAlphas;
        lastRedo = (lastRedo + 1) % 5;
        firstRedo = (firstRedo + 1) % 5;
    }
}

void UndoManager::undo() {
    if(nUndoElements < 1 && nUndoAvailable < 1)
        return;  //TODO eccezione
    updateRedo();
    *origReds = redsUndoArrayPointer[lastUndo-1];
    *origGreens = greensUndoArrayPointer[lastUndo-1];
    *origBlues = bluesUndoArrayPointer[lastUndo-1];
    *origAlphas = alphasUndoArrayPointer[lastUndo-1];
    lastUndo = (lastUndo - 1) % 5;
    nUndoAvailable = nUndoAvailable - 1;
}

void UndoManager::redo() {
    if(nRedoElements < 1 && nRedoAvailable < 1)
        return; //TODO eccezione
    update();
    *origReds = redsRedoArrayPointer[lastRedo-1];
    *origGreens = greensRedoArrayPointer[lastRedo-1];
    *origBlues = bluesRedoArrayPointer[lastRedo-1];
    *origAlphas = alphasRedoArrayPointer[lastRedo-1];
    lastRedo = (lastRedo - 1) % 5;
    nRedoAvailable = nRedoAvailable - 1;
}