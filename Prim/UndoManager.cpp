//
// Created by barti on 20/08/17.
//

#include "UndoManager.h"

UndoManager::UndoManager(Image firstImg) {
    undoVector.push_back(firstImg);
    origImg = firstImg;
}

void UndoManager::update(Image img) {
    if(undoVector.size() < 5)
        undoVector.push_back(img);
    else{
        undoVector.erase(undoVector.begin());
        undoVector.push_back(img);
    }
}

Image UndoManager::undo() {
    if(!undoVector.empty()){
        notifyRedo();
        undoVector.pop_back();
        return undoVector.back();
    }
} //non so cosa mettere nel caso undoVector sia vuoto...

Image UndoManager::reset() {
    undoVector.clear();
    (*redoptr).reset();
    return origImg;
}