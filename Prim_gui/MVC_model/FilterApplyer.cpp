//
// Created by edoardo on 14/08/17.
//

#include "FilterApplyer.h"
#include "GaussianBlur.h"
#include "EdgeDetection.h"
#include "Sharpen.h"
#include "Emboss.h"

#include <Magick++.h>
#include <vector>
#include <memory>

void FilterApplyer::setKernelStrategy(FilterTypes filterID) {
    if(!strategy_)
       delete strategy_;
    /*if(filterID == FilterTypes::GaussianBlur){
        strategy_ = new GaussianBlur(reds_, greens_, blues_, alphas_);
    }*/

    switch(filterID){
        case FilterTypes::GaussianBlur:
            strategy_ = new GaussianBlur(reds_, greens_, blues_, alphas_);
            break;
        case FilterTypes::EdgeDetection:
            strategy_ = new EdgeDetection(reds_, greens_, blues_, alphas_);
            break;
        case FilterTypes::Sharpen:
            strategy_ = new Sharpen(reds_, greens_, blues_, alphas_);
            break;
        case FilterTypes::Emboss:
            strategy_ = new Emboss(reds_, greens_, blues_, alphas_);
    }

    //so on and so forth for all the filters available

}

void FilterApplyer::notifyUndo(){
    try {
        undoPtr->update();
    }catch(Exception e){
        std::cout << e.what() << "C'è stato un errore nel notifyUndo()" << std::endl;

    }
    }

void FilterApplyer::kernelFilter() {
    notifyUndo();
    strategy_->applyFilter();
}

/*void FilterApplyer::setUndoPtr(UndoManager *undoPtr) {
    FilterApplyer::undoPtr = undoPtr;
}
*/
