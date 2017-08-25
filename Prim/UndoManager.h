//
// Created by barti on 20/08/17.
//

#ifndef PRIM_UNDOMANAGER_H
#define PRIM_UNDOMANAGER_H

#include <stack>
#include <Magick++.h>
#include "RedoManager.h"
#include <vector>

using namespace Magick;
using namespace std;

class UndoManager {
public:
    UndoManager(Image firstImg);
    Image reset();
    Image undo();
    void update(Image img);
    void notifyRedo(){ (*redoptr).update(undoVector.back());}

private:
    Image origImg;
    RedoManager* redoptr;
    vector<Image> undoVector;   // non sono convinto se debba essere uno stack di immagini o di puntatori a immagini fammi sapere cosa ne pensi...
};


#endif //PRIM_UNDOMANAGER_H
