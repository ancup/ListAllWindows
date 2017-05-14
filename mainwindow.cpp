#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>


QString handle_1; //дескриптор целевого окна
DWORD dwPID=0; //ID процесса
DWORD address=0;
DWORD size=0;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

// Инициализируем второе окно
workWindow = new WorkWindow();





// подключаем к слоту запуска главного окна по кнопке во втором окне
  connect(workWindow, &WorkWindow::open_firstWindow, this, &MainWindow::window_top);






//_____Регистрируем HotKey "F3"____________________________________________________________

RegisterHotKey((HWND)MainWindow::winId(),   // Устанавливаем системный идентификатор окна виджета, который будет обрабатывать HotKey
              100,                         // Устанавливаем идентификатор HotKey
                0 /*MOD_ALT | MOD_SHIFT*/,         // Устанавливаем модификаторы
             VK_F3);                        // Определяем Горячую Клавишу для HotKey
//__________________________________________________________________________________________________
}

MainWindow::~MainWindow()
{
    delete ui;
}

//_____Функции

void MainWindow::on_pushButton_2_pressed()  //кнопка обновить
{
    ui->comboBox->clear();
    EnumWindows(StaticEnumWindowsProc, reinterpret_cast<LPARAM>(this));
}

BOOL MainWindow::StaticEnumWindowsProc(HWND hwnd, LPARAM lParam)
{
    MainWindow *pThis = reinterpret_cast<MainWindow*>(lParam);
    return pThis->EnumWindowsProc(hwnd);
}

BOOL MainWindow::EnumWindowsProc(HWND hwnd)
{
    WCHAR title[255];

    if ((GetWindowLongPtr(hwnd, GWL_STYLE) & (WS_VISIBLE | WS_CAPTION)) == (WS_VISIBLE | WS_CAPTION))
        {
             if ((GetWindowText(hwnd, title, 255)) > 0)
             {
                 ui->comboBox->addItem(QString::fromWCharArray(title));

             }
        }

    return TRUE;
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    QString itemStr = ui->comboBox->itemText (index);
    bool ok;
    int value = itemStr.toInt(&ok);
    if (!ok) return;
    int result =value;
    ui->label->setText( QString::number( result ) );

}

 void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)//сохранить заголовок нужного окна
{
     handle_1 = arg1;

}

void MainWindow::on_pushButton_pressed()//соединение
{
    LPCWSTR handle_2 = (const wchar_t*) handle_1.utf16(); //приведение типа заголовка
    HWND win = FindWindow(0, handle_2 ); //получение дескриптора окна
    GetWindowThreadProcessId( win,  &dwPID); // получение ID процесса


   // statusBar()->addWidget(p);
    //statusBar()->addPermanentWidget(p);
    statusBar()->clearMessage();
    statusBar()->showMessage("ID: "+QString().setNum(dwPID));
qDebug()<< dwPID;




}




//SetForegroundWindow(win);
//qDebug()<< handle_1;
// qDebug()<< win;


void MainWindow::on_pushButton_3_pressed()
{
    workWindow->showNormal();  // Показываем второе окно
    this->hide();    // Скрываем основное окно

}
// Установка окна видимым и верхним
void MainWindow::window_top()
{
    MainWindow::setWindowFlags(Qt::WindowStaysOnTopHint);
    MainWindow::show();
    MainWindow::activateWindow();
}




bool MainWindow::nativeEvent(const QByteArray &eventType, void *message, long *result)
{
    Q_UNUSED(eventType)
    Q_UNUSED(result)
    // Преобразуем указатель message в MSG WinAPI
    MSG* msg = reinterpret_cast<MSG*>(message);

    // Если сообщение является HotKey, то ...
    if(msg->message == WM_HOTKEY){
        // ... проверяем идентификатор HotKey
        if(msg->wParam == 100){
            // Сообщаем об этом в консоль
            qDebug() << "HotKey worked";
            return true;
        }
    }
    return false;
}





