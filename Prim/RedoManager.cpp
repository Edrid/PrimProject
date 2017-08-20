//
// Created by barti on 20/08/17.
//

#include "RedoManager.h"

void RedoManager::redo() {
    redoStack.top().display();
    redoStack.pop();
}