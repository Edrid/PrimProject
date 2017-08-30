//
// Created by edoardo on 14/08/17.
//

#include "FilterApplyer.h"
#include "GaussianBlur.h"
#include "EdgeDetection.h"

#include <Magick++.h>
#include <vector>
#include <memory>

void FilterApplyer::setKernelStrategy(FilterType filterID) {
    if(!strategy_)
       delete strategy_;
    /*if(filterID == FilterType::GaussianBlur){
        strategy_ = new GaussianBlur(reds_, greens_, blues_, alphas_);
    }*/

    switch(filterID){
        case FilterType::GaussianBlur:
            strategy_ = new GaussianBlur(reds_, greens_, blues_, alphas_);
            break;
        case FilterType::EdgeDetection:
            strategy_ = new EdgeDetection(reds_, greens_, blues_, alphas_); //TODO to be implemented
            break;
        }

    //TODO so on and so forth for all the filters available

}

void FilterApplyer::kernelFilter() {
    strategy_->applyFilter();
}