#include <iostream>
#include <Magick++.h>
#include "ImageElaborator.h"

using namespace Magick;
int main(int argc,char **argv) {
    InitializeMagick(*argv);
    ImageElaborator elaborator("/home/edoardo/Documents/Prim_project/image1.jpg");
    //elaborator.setImage("/home/edoardo/Documents/Prim_project/image1.jpg");
    //elaborator.imgToVectors();
    elaborator.display();
    elaborator.filterApplyer_->setKernelStrategy(::FilterType::GaussianBlur);
    elaborator.filterApplyer_->kernelFilter();
    elaborator.display();

    elaborator.filterApplyer_->setKernelStrategy(::FilterType::EdgeDetection);
    elaborator.filterApplyer_->kernelFilter();
    elaborator.display();

}