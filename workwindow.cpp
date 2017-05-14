#include "workwindow.h"
#include "ui_workwindow.h"
#include <QDebug>

WorkWindow::WorkWindow(QMainWindow *parent) :
    QMainWindow(parent),
    ui(new Ui::WorkWindow)
{
    ui->setupUi(this);
//###############################################################################








//################################################################################

}

WorkWindow::~WorkWindow()
{
    delete ui;
}

//################################################################################


void WorkWindow::on_close_pressed()
{
    this->close();      // Закрываем окно
    emit open_firstWindow(); // И вызываем сигнал на открытие главного окна
}











