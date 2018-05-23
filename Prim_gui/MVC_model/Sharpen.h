//
// Created by edoardo on 15/05/18.
//

#ifndef PRIM_GUI_SHARPEN_H
#define PRIM_GUI_SHARPEN_H

#include "KernelFilter.h"


class Sharpen : public KernelFilter{
public:
    Sharpen(QuantumPointer redsp, QuantumPointer greensp, QuantumPointer bluesp, QuantumPointer alphasp) : KernelFilter(redsp, greensp, bluesp, alphasp) {
        convMatrix = {{0,-1,0},{-1,5,-1},{0,-1,0}};
    }
    void applyFilter();
};

#endif //PRIM_GUI_SHARPEN_H
