//
// Created by edoardo on 12/08/17.
//

#ifndef PRIM_IMAGEELABORATOR_H
#define PRIM_IMAGEELABORATOR_H

#include <Magick++.h>
#include <vector>
#include <memory>
#include <QImage>
#include "FilterApplyer.h"
#include "UndoManager.h"
#include "../MVC_interfaces/Subject.h" //vuole che lo metta così

using namespace Magick;
using namespace std;

//typedef shared_ptr<vector<vector<int>>> QuantumPointer;
typedef vector<vector<int>>* QuantumPointer;

//Remember, the ImageElaborator always has to have the quantum vectors updated with the current values.
class ImageElaborator : public virtual Subject{
public:
    ImageElaborator(string path);
    //ImageElaborator(Image &img); // in this constructor, also fill vectors
    //ImageElaborator();
    void setImage(string path);
    //void setImage(Image &img); // implementation
    void saveImage(std::string path);
    void display(){
        renderImage();
        img->display(); }
    QImage getQTimage();
    shared_ptr<FilterApplyer> filterApplyer_;
    UndoManager *undoPtr; //FIXME

    void notify(); //done implementare il notify
    void addObserver(Observer* o){ observers.push_back(o); }
    void removeObserver(Observer* o){ observers.remove(o); }

    const vector<vector<int>> &getReds() const;

private:
    shared_ptr<Image> img;
    void imgToVectors(); //In this case the parameter list is empty because I already have access to the image, in fact it's inside of the class
    void renderImage(); //Both return value and parameter list are empty for the same reason as above
    //The following are the quantum containers, a different implementation is certainly possible, though this one is more practical
    vector<vector<int>> reds;
    vector<vector<int>> greens;
    vector<vector<int>> blues;
    vector<vector<int>> alphas;
    // messi i puntatori
    list<Observer*> observers;
    //DONE fare un reserve dei vectors

};


#endif //PRIM_IMAGEELABORATOR_H
