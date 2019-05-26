#include "mainwindow.h"
#include <QApplication>

#include "map.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);



    MainWindow *w = MainWindow::GetInstance();
//    w->showMaximized();
    w->show();
//    w->showFullScreen();

    New_Form form;
    form.create_window(w);

    Map map;
    map.drow_map();





    return a.exec();
}
