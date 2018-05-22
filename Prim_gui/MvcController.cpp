//
// Created by edoardo on 15/05/18.
//

#include "MvcController.h"

void MvcController::gaussianBlur() {
    ie->filterApplyer_->setKernelStrategy(FilterTypes::GaussianBlur);
    ie->filterApplyer_->kernelFilter();
    ie->notify();
}

void MvcController::edgeDetection(){
    ie->filterApplyer_->setKernelStrategy(FilterTypes::EdgeDetection);
    ie->filterApplyer_->kernelFilter();
    ie->notify();
}

void MvcController::undo() {
    ie->undoPtr->undo();
    ie->notify();
}

void MvcController::redo() {
    ie->undoPtr->redo();
    ie->notify();
}

void MvcController::sharpen() {
    ie->filterApplyer_->setKernelStrategy(FilterTypes::Sharpen);
    ie->filterApplyer_->kernelFilter();
    ie->notify();
}

void MvcController::emboss() {
    ie->filterApplyer_->setKernelStrategy(FilterTypes::Emboss);
    ie->filterApplyer_->kernelFilter();
    ie->notify();
}

void MvcController::openNewImage() {
    fileSelector.openFile();
    if(!fileSelector.getFilePath().empty()) {
        ie->setImage(fileSelector.getFilePath());
        ie->notify();
    }
}

void MvcController::saveImage() {
    fileSelector.saveFile();
    if(!fileSelector.getFilePath().empty()){
        ie->saveImage(fileSelector.getFilePath());
    }

}