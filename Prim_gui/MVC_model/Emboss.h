//
// Created by edoardo on 17/05/18.
//

#ifndef PRIM_GUI_EMBOSS_H
#define PRIM_GUI_EMBOSS_H


#include "KernelFilter.h"

class Emboss : public KernelFilter{
public:
    Emboss(QuantumPointer redsp, QuantumPointer greensp, QuantumPointer bluesp, QuantumPointer alphasp) : KernelFilter(redsp, greensp, bluesp, alphasp) {
        convMatrix = {{-2,-1-0},{-1,1,1},{0,1,2}};
    }
    void applyFilter();
};


#endif //PRIM_GUI_EMBOSS_H
