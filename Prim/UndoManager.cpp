//
// Created by barti on 20/08/17.
//

#include "UndoManager.h"

UndoManager::UndoManager(QuantumPointer reds, QuantumPointer greens, QuantumPointer blues, QuantumPointer alphas) {
    origReds = reds;
    origGreens = greens;
    origBlues = blues;
    origAlphas = alphas;
    redoptr = new RedoManager(origReds, origGreens, origBlues, origAlphas);
    firstReds = *reds;
    firstGreens = *greens;
    firstBlues = *blues;
    firstAlphas = *alphas;
}

void UndoManager::update() {
    int size = static_cast<int>(redsUndoVector.size());
    if(size < 5 ){
        redsUndoVector.push_back(*origReds);
        greensUndoVector.push_back(*origGreens);
        bluesUndoVector.push_back(*origBlues);
        alphasUndoVector.push_back(*origAlphas);
    }
    else{
        redsUndoVector.erase(redsUndoVector.begin());
        redsUndoVector.push_back(*origReds);
        greensUndoVector.erase(greensUndoVector.begin());
        greensUndoVector.push_back(*origGreens);
        bluesUndoVector.erase(bluesUndoVector.begin());
        bluesUndoVector.push_back(*origBlues);
        alphasUndoVector.erase(alphasUndoVector.begin());
        alphasUndoVector.push_back(*origAlphas);
    }
}

void UndoManager::undo() {
    if(!redsUndoVector.empty()){
        notifyRedo();
        *origReds = redsUndoVector.back();
        redsUndoVector.pop_back();
        *origGreens = greensUndoVector.back();
        greensUndoVector.pop_back();
        *origBlues = bluesUndoVector.back();
        bluesUndoVector.pop_back();
        *origAlphas = alphasUndoVector.back();
        alphasUndoVector.pop_back();
    }
}

void UndoManager::reset() {
    redsUndoVector.clear();
    greensUndoVector.clear();
    bluesUndoVector.clear();
    alphasUndoVector.clear();
    (*redoptr).reset();
    *origReds = firstReds;
    *origGreens = firstGreens;
    *origBlues = firstBlues;
    *origAlphas = firstAlphas;
}