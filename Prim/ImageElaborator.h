//
// Created by edoardo on 12/08/17.
//

#ifndef PRIM_IMAGEELABORATOR_H
#define PRIM_IMAGEELABORATOR_H

#include <Magick++.h>
#include <vector>
#include <memory>

using namespace Magick;
using namespace std;

class ImageElaborator {
public:
    shared_ptr<Image> img;
    ImageElaborator(std::string path); //TODO same ad below
    ImageElaborator(Image &img); //TODO in this constructor, also fill vectors
    ImageElaborator();
    void setImage(string path);
    void setImage(Image &img);
    void imgToVectors(); //TODO move this into the private sector

private:
    //void imgToVectors(); //In this case the parameter list is empty because I already have access to the image, in fact it's inside of the class
    void renderImage(); //Both return value and parameter list are empty for the same reason as above

    //The following are the quantum containers, a different implementation is certainly possible, though this one is more practical
    vector<vector<int>> reds;
    vector<vector<int>> greens;
    vector<vector<int>> blues;
    vector<vector<int>> alphas;

};


#endif //PRIM_IMAGEELABORATOR_H
