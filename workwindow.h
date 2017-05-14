#ifndef WORKWINDOW_H
#define WORKWINDOW_H

#include <QtGui>
#include <QMainWindow>
#include "windows.h" // Подключаем библиотеку WinAPI

namespace Ui {
class WorkWindow;
}

class WorkWindow :  public QMainWindow
{
    Q_OBJECT

public:
    explicit WorkWindow(QMainWindow *parent = 0);
    ~WorkWindow();

protected:


signals:
    void open_firstWindow();  // Сигнал для первого окна на открытие

private slots:


    void on_close_pressed(); // Слот-обработчик нажатия кнопки


private:
    Ui::WorkWindow *ui;


};

#endif // WORKWINDOW_H
