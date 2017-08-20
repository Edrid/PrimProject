//
// Created by barti on 20/08/17.
//

#include "UndoManager.h"

void UndoManager::undo() {
    notifyRedo();
    undoStack.top().display();
    undoStack.pop();
}