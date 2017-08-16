//
// Created by edoardo on 14/08/17.
//

#include "FilterApplyer.h"

void FilterApplyer::setKernelStrategy(FilterType filterID) {
    delete strategy_;
    if(filterID == FilterType::GaussianBlur){
        strategy_ = new GaussianBlur();
    }

    switch(filterID){
        case FilterType::GaussianBlur:
            strategy_ = new GaussianBlur(); //TODO to be implemented
            break;
        case FilterType::EdgeDetection:
            strategy_ = new EdgeDetection(); //TODO to be implemented
        }

    //TODO so on and so forth for all the filters available

}