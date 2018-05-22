#include <FileSelector.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "MVC_model/ImageElaborator.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    //FIXME istanzio il controller ed il modello nella mainwindow, è corretto? O è preferibile istanziarli nel main?
    ui->setupUi(this);

    //PROVA DI VISUALIZZAZIONE DI UN'IMMAGINE
    /*ImageElaborator elaborator("/home/edoardo/Documents/Prim_project/image1.jpg");
    this->elab = &elaborator;*/


    elab = new ImageElaborator("/home/edoardo/Pictures/immagineDiProva.jpg"); //ISTANZIO QUI IL MODELLO
    //elab->setImage("/home/edoardo/Documents/PRIM_GUI__20180215/duomo.jpg");
    controller = new MvcController(elab);
    elab->addObserver(this); //AGGIUNGO L'OBSERVER

    ui->imgLabel->setPixmap(QPixmap::fromImage(elab->getQTimage()));



}

void MainWindow::update() {
    ui->imgLabel->setPixmap(QPixmap::fromImage(elab->getQTimage()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


//Convenzioni per nome dei pulsanti: nomePulsanteBtn
void MainWindow::on_pippoButton_clicked(){
    ui->pippoButton->setText("Mi hai cliccato");
    elab->undoPtr->undo();
    ui->imgLabel->setPixmap(QPixmap::fromImage(elab->getQTimage()));
} //Questo era un esempio di implementazione senza mvc

void MainWindow::on_gaussBlurBtn_clicked(){
    //ui->gaussBlurBtn->setText("Mi hai cliccato");
    controller->gaussianBlur();
}


void MainWindow::on_edgeDetectionBtn_clicked(){
    controller->edgeDetection();
}

void MainWindow::on_undoBtn_clicked(){
    controller->undo();
}

void MainWindow::on_redoBtn_clicked(){
    controller->redo();
}

void MainWindow::on_sharpenBtn_clicked(){
    controller->sharpen();
}

void MainWindow::on_embossBtn_clicked(){
    controller->emboss();
}

void MainWindow::on_loadBtn_clicked() {
    controller->openNewImage();
}

void MainWindow::on_exportBtn_clicked() {
    controller->saveImage();
}