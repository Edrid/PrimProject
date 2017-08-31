//
// Created by edoardo on 30/08/17.
//

#include "EdgeDetection.h"

void EdgeDetection::applyFilter() {
    *reds_ = convolute(reds_, false);
    *greens_ = convolute(greens_, false);
    *blues_ = convolute(blues_, false);
    *alphas_ = convolute(alphas_, false);

}