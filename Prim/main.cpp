#include <iostream>
#include <Magick++.h>
#include "ImageElaborator.h"

using namespace Magick;
int main(int argc,char **argv) {
    InitializeMagick(*argv);
    ImageElaborator elaborator("/home/barti/CLionProjects/PRIMProject/image1.jpg");
    //elaborator.setImage("/home/edoardo/Documents/Prim_project/image1.jpg");
    //elaborator.imgToVectors();
    elaborator.display();
    elaborator.filterApplyer_->setKernelStrategy(FilterTypes::GaussianBlur);
    elaborator.filterApplyer_->kernelFilter();
    elaborator.display();

    elaborator.undoPtr->undo();
    elaborator.display();
    elaborator.undoPtr->redoptr->redo();
    elaborator.display();

    elaborator.filterApplyer_->setKernelStrategy(FilterTypes::EdgeDetection);
    elaborator.filterApplyer_->kernelFilter();
    elaborator.display();
}