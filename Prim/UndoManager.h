//
// Created by barti on 20/08/17.
//

#ifndef PRIM_UNDOMANAGER_H
#define PRIM_UNDOMANAGER_H

#include <stack>
#include <Magick++.h>
#include "RedoManager.h"

using namespace Magick;
using namespace std;

class UndoManager {
public:
    void undo();
    void update(Image img){undoStack.push(img);}
    void notifyRedo(){ (*redoptr).update(undoStack.top());}

private:
    stack<Image> undoStack;  // non sono convinto se debba essere uno stack di immagini o di puntatori a immagini fammi sapere cosa ne pensi...
    RedoManager* redoptr;

};


#endif //PRIM_UNDOMANAGER_H
