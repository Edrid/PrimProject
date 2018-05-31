//
// Created by barti on 20/08/17.
//

#include "UndoManager.h"

//FIXed fa un undo di troppo
UndoManager::UndoManager(QuantumPointer reds, QuantumPointer greens, QuantumPointer blues, QuantumPointer alphas) {
    origReds = reds;
    origGreens = greens;
    origBlues = blues;
    origAlphas = alphas;
    redsUndoArrayPointer = new QuantumValues[maxOps];
    redsRedoArrayPointer = new QuantumValues[maxOps];
    greensUndoArrayPointer = new QuantumValues[maxOps];
    greensRedoArrayPointer = new QuantumValues[maxOps];
    bluesUndoArrayPointer = new QuantumValues[maxOps];
    bluesRedoArrayPointer = new QuantumValues[maxOps];
    alphasUndoArrayPointer = new QuantumValues[maxOps];
    alphasRedoArrayPointer = new QuantumValues[maxOps];
}

void UndoManager::update() {
    if(nUndoElements < maxOps ){ // è un valore scelto da noi
        lastUndo = (lastUndo + 1) % maxOps;
        redsUndoArrayPointer[lastUndo] = *origReds;
        greensUndoArrayPointer[lastUndo] = *origGreens;
        bluesUndoArrayPointer[lastUndo] = *origBlues;
        alphasUndoArrayPointer[lastUndo] = *origAlphas;
        nUndoAvailable++;
        nUndoElements++;
    }
    else{
        redsUndoArrayPointer[firstUndo] = *origReds;
        greensUndoArrayPointer[firstUndo] = *origGreens;
        bluesUndoArrayPointer[firstUndo] = *origBlues;
        alphasUndoArrayPointer[firstUndo] = *origAlphas;
        lastUndo = (lastUndo + 1) % maxOps;
        firstUndo = (firstUndo + 1) % maxOps;
    }
    //FIXME rimuovere costante 5
}

void UndoManager::updateRedo() {
    if(nRedoElements < maxOps ){
        lastRedo = (lastRedo + 1) % maxOps;
        redsRedoArrayPointer[lastRedo] = *origReds;
        greensRedoArrayPointer[lastRedo] = *origGreens;
        bluesRedoArrayPointer[lastRedo] = *origBlues;
        alphasRedoArrayPointer[lastRedo] = *origAlphas;
        nRedoElements++;
        nRedoAvailable++;
    }
    else{
        redsRedoArrayPointer[firstRedo] = *origReds;
        greensRedoArrayPointer[firstRedo] = *origGreens;
        bluesRedoArrayPointer[firstRedo] = *origBlues;
        alphasRedoArrayPointer[firstRedo] = *origAlphas;
        lastRedo = (lastRedo + 1) % maxOps;
        firstRedo = (firstRedo + 1) % maxOps;
    }
}

void UndoManager::undo() {
    if(nUndoElements < 1 || nUndoAvailable < 1)
        return;  //TODO eccezione
    updateRedo();
    *origReds = redsUndoArrayPointer[lastUndo];
    *origGreens = greensUndoArrayPointer[lastUndo];
    *origBlues = bluesUndoArrayPointer[lastUndo];
    *origAlphas = alphasUndoArrayPointer[lastUndo];
    lastUndo = (lastUndo - 1);
    //lastUndo = lastUndo % 5;
    if(lastUndo == -1)
        lastUndo = 4;
    nUndoAvailable -= 1;
    nUndoElements -= 1;
}

void UndoManager::redo() {
    if(nRedoElements < 1 || nRedoAvailable < 1)
        return; //TODO eccezione
    update();
    *origReds = redsRedoArrayPointer[lastRedo];
    *origGreens = greensRedoArrayPointer[lastRedo];
    *origBlues = bluesRedoArrayPointer[lastRedo];
    *origAlphas = alphasRedoArrayPointer[lastRedo];
    //lastRedo = (lastRedo - 1) % 5;
    lastRedo -= 1;
    if(lastRedo == -1)
        lastRedo = 4;
    nRedoAvailable -= 1;
    nRedoElements -= 1;
}

UndoManager::~UndoManager() {
    delete redsUndoArrayPointer;
    delete redsRedoArrayPointer;
    delete greensUndoArrayPointer;
    delete greensRedoArrayPointer;
    delete bluesUndoArrayPointer;
    delete bluesRedoArrayPointer;
    delete alphasUndoArrayPointer;
    delete alphasRedoArrayPointer;

}
