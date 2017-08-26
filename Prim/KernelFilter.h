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
    KernelFilter(QuantumPointer redsp, QuantumPointer greensp, QuantumPointer bluesp, QuantumPointer alphasp) : reds_(redsp), greens_(greensp), blues_(bluesp), alphas_(alphasp){} //Contructor TODO
    virtual void applyFilter() = 0;

private:
    vector<vector<int>> convMatrix;
protected:
    vector<vector<int>> convolute(vector<vector<int>> *original, bool normalized); //it modifies the variables right below

    QuantumPointer reds_;
    QuantumPointer greens_;
    QuantumPointer blues_;
    QuantumPointer alphas_;

};


#endif //PRIM_KERNELFILTER_H