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
    KernelFilter(QuantumPointer redsp, QuantumPointer greensp, QuantumPointer bluesp, QuantumPointer alphasp) : reds_(redsp), greens_(greensp), blues_(bluesp), alphas_(alphasp){}
    virtual void applyFilter() = 0;


protected:
    vector<vector<int>> convolute(vector<vector<int>> *original, bool normalized); //it modifies the variables right below
    vector<vector<int>> convMatrix;
    QuantumPointer reds_;
    QuantumPointer greens_;
    QuantumPointer blues_;
    QuantumPointer alphas_;

};


#endif //PRIM_KERNELFILTER_H