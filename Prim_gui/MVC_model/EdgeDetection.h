//
// Created by edoardo on 30/08/17.
//

#ifndef PRIM_EDGEDETECTION_H
#define PRIM_EDGEDETECTION_H


#include "KernelFilter.h"

class EdgeDetection : public KernelFilter{
public:
    EdgeDetection(QuantumPointer redsp, QuantumPointer greensp, QuantumPointer bluesp, QuantumPointer alphasp) : KernelFilter(redsp, greensp, bluesp, alphasp) {
        convMatrix = {{-1,-1,-1},{-1,8,-1},{-1,-1,-1}};
    }
    void applyFilter();
};


#endif //PRIM_EDGEDETECTION_H
