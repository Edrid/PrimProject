//
// Created by edoardo on 15/05/18.
//

#ifndef PRIM_GUI_MVCCONTROLLER_H
#define PRIM_GUI_MVCCONTROLLER_H


#include <MVC_model/ImageElaborator.h>
#include "FileSelector.h"

class MvcController {
public:
    MvcController(ImageElaborator* ie){
        this->ie = ie;
    }
    void gaussianBlur();
    void edgeDetection();
    void sharpen();
    void emboss();
    void undo();
    void redo();
    void openNewImage();
    void saveImage();

private:
    ImageElaborator* ie;
    FileSelector fileSelector;
};


#endif //PRIM_GUI_MVCCONTROLLER_H
