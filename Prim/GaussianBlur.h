//
// Created by edoardo on 17/08/17.
//

#ifndef PRIM_GAUSSIANBLUR_H
#define PRIM_GAUSSIANBLUR_H


#include "KernelFilter.h"

class GaussianBlur : public KernelFilter{
public:
    GaussianBlur(QuantumPointer redsp, QuantumPointer greensp, QuantumPointer bluesp, QuantumPointer alphasp) : KernelFilter(redsp, greensp, bluesp, alphasp) {
        convMatrix = {{1,2,1},{2,4,2},{1,2,1}};
    }
    void applyFilter();
};


#endif //PRIM_GAUSSIANBLUR_H
