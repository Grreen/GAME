#include "map.h"
#include "cell.h"
#include "mainwindow.h"

#include <QGraphicsView>
#include <QFile>
#include <QTextStream>
#include <QPixmap>
#include <QGraphicsPixmapItem>

#include <QGraphicsSceneMouseEvent>

//#include<QList>

#include <QGraphicsProxyWidget>
#include <QProgressBar>

#include <iostream>

void Map::drow_map()
{
    MainWindow *win = MainWindow::GetInstance();
    QGraphicsView *GraphicsView = win->GetInstanceGraphicsView();

    GraphicsView->setScene(scene);
    GraphicsView->setAlignment( Qt::AlignLeft | Qt::AlignTop );

//15 в длину
    scene->size_items = GraphicsView->width()/13;
    QFile file("Map.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream out(&file);
    int count_x, count_y;
    out>>count_x>>count_y;

    const int width_per = count_x;
    const int heigth_per = count_y;

    width = count_x;
    height =count_y;

    QString mass[count_x][count_y];

    map  =new int*[count_x];
    for (int i=0;i<count_x;i++)
        map[i] = new int[count_y];

    for (int i=0;i<count_x;i++)
        for (int j=0; j<count_y; j++)
            out>>mass[i][j];
    file.close();

    for (int x=0;x<count_x*scene->size_items;x+=scene->size_items) {
        for (int y=0;y<count_y*scene->size_items;y+=scene->size_items) {
            Cell cell;
            cell.drow(scene, mass[x/scene->size_items][y/scene->size_items], x, y, scene->size_items);
            if(mass[x/scene->size_items][y/scene->size_items].toInt() == 1 &&
               (QPoint(x/scene->size_items,y/scene->size_items)!=QPoint(0,0)) &&
               (QPoint(x/scene->size_items,y/scene->size_items)!=QPoint(0,height-1)) &&
               (QPoint(x/scene->size_items,y/scene->size_items)!=QPoint(width-1,0)) &&
               (QPoint(x/scene->size_items,y/scene->size_items)!=QPoint(width-1,height-1)))
                map[y/scene->size_items][x/scene->size_items] = -2;
            else
                map[y/scene->size_items][x/scene->size_items] = -1;
            cell.x_center = x+50;
            cell.y_center = y+50;
            cell.width = scene->size_items;

            list_cells << cell;
        }
    }
}
