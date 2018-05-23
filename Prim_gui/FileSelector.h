//
// Created by edoardo on 17/05/18.
//

#ifndef PRIM_GUI_FILESELECTOR_H
#define PRIM_GUI_FILESELECTOR_H


#include <QtWidgets/QWidget>

class FileSelector : public QWidget{
public:
    void openFile();
    void saveFile();
    std::string getFilePath(){ return filePath; }
private:
    std::string filePath = "";

};


#endif //PRIM_GUI_FILESELECTOR_H
