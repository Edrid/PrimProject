//
// Created by barti on 20/08/17.
//

#ifndef PRIM_REDOMANAGER_H
#define PRIM_REDOMANAGER_H

#include <Magick++.h>
#include <stack>

using namespace Magick;
using namespace std;

class RedoManager {
public:
    void update(Image* img){ redoVector.push_back(img);}
    Image* redo();
    void reset(){redoVector.clear();}

private:
    vector<Image*> redoVector;
};


#endif //PRIM_REDOMANAGER_H
