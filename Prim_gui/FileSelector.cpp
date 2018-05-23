//
// Created by edoardo on 17/05/18.
//

#include "FileSelector.h"
#include <QApplication>
#include <QFileDialog>
#include <QDebug>
#include <iostream>


void FileSelector::openFile()
    {
        //FIXME quando annullo la selezione del file si frizza tutto
        try {
            QString filename = QFileDialog::getOpenFileName(
                    this,
                    "Open image",
                    QDir::currentPath(),
                    "All files (*.*);; JPEG files (*.jpeg);; JPG files (*.jpg);; PNG files (*.png)");


        if( !filename.isNull() || !filename.isEmpty()){
            filePath = (filename.toUtf8().constData());
            std::cout << "File path -" << filename.toUtf8().constData() << std::endl;
        }

        }catch (const std::runtime_error& error)
        {}
    }

void FileSelector::saveFile() {
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Salva l'immagine"), "",
                                                    tr("JPEG files (.jpeg);; JPG files (.jpg);;All Files (*)"));
    if(!fileName.isEmpty() || !fileName.isNull()){
        filePath = (fileName.toUtf8().constData());
        std::cout << "File path -" << fileName.toUtf8().constData() << std::endl;

    }

}