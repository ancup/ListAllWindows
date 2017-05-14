#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtGui>
#include <QMainWindow>
#include <QSystemTrayIcon>
#include "Windows.h"
#include <workwindow.h>


namespace Ui {
class MainWindow;
}

class MainWindow :  public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    static BOOL CALLBACK StaticEnumWindowsProc(HWND hwnd, LPARAM lParam);
    BOOL EnumWindowsProc(HWND hwnd);




protected:
    // Метод для обработки native событий от ОС в Qt
    bool nativeEvent(const QByteArray &eventType, void *message, long *result);



public slots:

private slots:
    // Слоты от кнопок главного окна
    void on_pushButton_pressed();
    void on_pushButton_2_pressed();
    void on_comboBox_currentIndexChanged(int index);
    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_pushButton_3_pressed();//запуск

    void window_top();




private:
    Ui::MainWindow *ui;

   // второе и третье окна
    WorkWindow *workWindow;



};

#endif // MAINWINDOW_H
