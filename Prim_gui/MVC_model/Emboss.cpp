//
// Created by edoardo on 17/05/18.
//

#include "Emboss.h"

void Emboss::applyFilter() {
    *reds_ = convolute(reds_, true);
    *greens_ = convolute(greens_, true);
    *blues_ = convolute(blues_, true);
    *alphas_ = convolute(alphas_, true);

}