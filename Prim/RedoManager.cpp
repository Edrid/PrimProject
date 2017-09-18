//
// Created by barti on 20/08/17.
//

#include "RedoManager.h"

void RedoManager::redo() {
    if (!redsRedoVector.empty()) {
        *origReds = redsRedoVector.back();
        redsRedoVector.pop_back();
        *origGreens = greensRedoVector.back();
        greensRedoVector.pop_back();
        *origBlues = bluesRedoVector.back();
        bluesRedoVector.pop_back();
        *origAlphas = alphasRedoVector.back();
        alphasRedoVector.pop_back();
    }
} //non so cosa mettere nel caso redoVector sia vuoto...

void RedoManager::update() {
    if(redsRedoVector.size() < 5 ){
        redsRedoVector.push_back(*origReds);
        greensRedoVector.push_back(*origGreens);
        bluesRedoVector.push_back(*origBlues);
        alphasRedoVector.push_back(*origAlphas);
    }
    else {
        redsRedoVector.erase(redsRedoVector.begin());
        redsRedoVector.push_back(*origReds);
        greensRedoVector.erase(greensRedoVector.begin());
        greensRedoVector.push_back(*origGreens);
        bluesRedoVector.erase(bluesRedoVector.begin());
        bluesRedoVector.push_back(*origBlues);
        alphasRedoVector.erase(alphasRedoVector.begin());
        alphasRedoVector.push_back(*origAlphas);
    }
}