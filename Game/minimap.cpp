#include "minimap.h"
#include <QFile>
#include <QTextStream>
#include <QPainter>


MiniMap::MiniMap(QObject *parent)
{

    scene = new QGraphicsScene;
    QFile file("../Game/Map.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream out(&file);
    int count_x, count_y;
    out>>count_x>>count_y;

    width = count_x;
    height = count_y;

    map_array = new int*[count_x];
    for (int i=0; i<count_x;i++)
        map_array[i] = new int[count_y];

    for (int i=0;i<count_x;i++)
        for (int j=0; j<count_y; j++)
            out>>map_array[i][j];

    for(int i=0;i<width;i++)
        for(int j=0;j<height;j++)
        {
            this->drow(this->scene, QString::number(map_array[j][i]),i*2, j*2,2);
        }
    file.close();
}

