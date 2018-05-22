#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <MVC_interfaces/Observer.h>
#include <MvcController.h>
#include "MVC_model/ImageElaborator.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public virtual Observer
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();
    //virtual ~Observer(){};
    void update(); //TODO implement MVC update (observer design pattern)

private:
    Ui::MainWindow *ui;
    ImageElaborator *elab;
    MvcController *controller;

private slots:
    void on_pippoButton_clicked();
    void on_gaussBlurBtn_clicked();
    void on_edgeDetectionBtn_clicked();
    void on_undoBtn_clicked();
    void on_redoBtn_clicked();
    void on_sharpenBtn_clicked();
    void on_embossBtn_clicked();
    void on_loadBtn_clicked();
    void on_exportBtn_clicked();

    };

#endif // MAINWINDOW_H
