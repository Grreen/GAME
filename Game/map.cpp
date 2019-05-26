#include "map.h"
#include "cell.h"
#include "mainwindow.h"

#include <QGraphicsView>
#include <QFile>
#include <QTextStream>
#include <QPixmap>
#include <QGraphicsPixmapItem>

#include<QList>


void Map::drow_map()
{
    MainWindow *win = MainWindow::GetInstance();
    QGraphicsView *GraphicsView = win->GetInstanceGraphicsView();

    GraphicsView->setScene(scene);
    GraphicsView->setAlignment( Qt::AlignLeft | Qt::AlignTop );

    QFile file("Map.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream out(&file);
    int count_x, count_y;
    out>>count_x>>count_y;

    QString mass[count_x][count_y];

    for (int i=0;i<count_x;i++)
        for (int j=0; j<count_y; j++)
            out>>mass[i][j];
    file.close();

    for (int x=0;x<1000;x+=100) {
        for (int y=0;y<1000;y+=100) {
            QString str = mass[x/100][y/100];
            Cell cell;
            cell.drow(scene, str, x, y);
            cell.x_center = x;
            cell.y_center = y;
            cell.width = 100;

            list_cells << cell;
        }

    }




    for (int x=0; x<=1000; x+=100)
        scene->addLine(x,0,x,1000, QPen(Qt::black));

    for (int y=0; y<=1000; y+=100)
        scene->addLine(0,y,1000,y, QPen(Qt::black));
}
