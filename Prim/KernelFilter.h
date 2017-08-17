//
// Created by edoardo on 16/08/17.
//

#ifndef PRIM_KERNELFILTER_H
#define PRIM_KERNELFILTER_H

#include <Magick++.h>
#include <iostream>

//using namespace Magick;
using namespace std;

typedef vector<vector<int>>* QuantumPointer;

//THIS IS AN ABSTRACT CLASS, THE CONVOLUTION METHOD WILL BE IMPLEMENTED.
class KernelFilter {
public:
    KernelFilter(); //Contructor TODO
    virtual void applyFilter(QuantumPointer reds_, QuantumPointer greens_, QuantumPointer blues_, QuantumPointer alphas_) = 0;

private:
    vector<vector<int>> convMatrix;
    vector<vector<int>> convolute(vector<vector<int>> originalVals);

};


#endif //PRIM_KERNELFILTER_H