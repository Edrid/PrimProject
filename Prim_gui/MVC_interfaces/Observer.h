//
// Created by edoardo on 15/05/18.
//

#ifndef PRIM_GUI_OBSERVER_H
#define PRIM_GUI_OBSERVER_H


class Observer {

public:
    virtual ~Observer(){};
    virtual void update() = 0;

};


#endif //PRIM_GUI_OBSERVER_H
