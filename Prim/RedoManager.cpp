//
// Created by barti on 20/08/17.
//

#include "RedoManager.h"

Image RedoManager::redo() {
    if (!redoVector.empty()) {
     redoVector.pop_back();
     return redoVector.back();
    }
} //non so cosa mettere nel caso redoVector sia vuoto...
