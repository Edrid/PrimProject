//
// Created by edoardo on 15/05/18.
//

#ifndef PRIM_GUI_SUBJECT_H
#define PRIM_GUI_SUBJECT_H


#include "Observer.h"

class Subject {
public:
    virtual ~Subject(){};
    virtual void notify() = 0; //notifies that the UI needs to change the displayed image
    virtual void addObserver(Observer* o) = 0;
    virtual void removeObserver(Observer* o) = 0;
};


#endif //PRIM_GUI_SUBJECT_H
