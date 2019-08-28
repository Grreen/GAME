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
#include "minimap.h"
#include "graphicsview.h"
#include "game.h"

#include <iostream>
#include <QScrollBar>
#include <QTableWidget>

#include "graphicspanel.h"

void Map::drow_map()
{
    MainWindow *win = MainWindow::GetInstance();
    Game *game = Game::GetInstance();

    GraphicsView *Graphics = new GraphicsView(win);
    Graphics->setGeometry(0,0,win->width()-300, win->height()-200);
    win->layout()->addWidget(Graphics);
    Graphics->setScene(scene);
    Graphics->setAlignment( Qt::AlignLeft | Qt::AlignTop );

    GraphicsView *Graphics_2 = new GraphicsView(win);
    Graphics_2->setGeometry(Graphics->width(),100,300,Graphics->height()-100);
//    Graphics_2->setStyleSheet("background-color:black;");
    GraphicsPanel *new_scene = new GraphicsPanel(win);
    Graphics_2->setScene(new_scene);
    Graphics_2->setStyleSheet("background:url(../Game/01.png);"
                              "border:3px solid rgb(64, 64, 64);");
    new_scene->setSceneRect(Graphics_2->rect());

    game->graphicsView = Graphics;
    game->graphicsScene = new_scene;
    win->layout()->addWidget(Graphics_2);

    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->size_items = Graphics->width()/20;
    QFile file("../Game/Map.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream out(&file);
    int count_x, count_y;
    out>>count_x>>count_y;

    const int width_per = count_x;
    const int heigth_per = count_y;

    width = count_x;
    height =count_y;

    QString mass[count_x][count_y];

    map = new int*[count_x];
    for (int i=0;i<count_x;i++)
        map[i] = new int[count_y];

    for (int i=0;i<count_y;i++)
        for (int j=0; j<count_x; j++)
        {
            out>>mass[i][j];
            drow(scene,mass[i][j],j*scene->size_items,i*scene->size_items,scene->size_items);
        }
    file.close();

    for (int i=0;i<count_y;i++)
        for (int j=0; j<count_x; j++)
        {
            if(mass[i][j] == "01")
                map[j][i] = -2;
            else
                map[j][i] = -1;
        }

    MiniMap *minimap = new MiniMap;
    QGraphicsView *view_2 = win->GetInstanceGraphicsView(2);
//    minimap->scene = new QGraphicsScene(view_2);
    view_2->setScene(minimap->scene);
//    minimap->scene->addItem(minimap);
    view_2->setOptimizationFlag(QGraphicsView::DontAdjustForAntialiasing);
    view_2->setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
    view_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}
