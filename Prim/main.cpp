#include <iostream>
#include <Magick++.h>
#include "ImageElaborator.h"

using namespace Magick;
int main(int argc,char **argv) {
    InitializeMagick(*argv);
    ImageElaborator elaborator;
    elaborator.setImage("/home/edoardo/Documents/Prim_project/image1.jpg");
    elaborator.imgToVectors();

}