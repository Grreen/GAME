#include <QPainter>
#include <QFontDatabase>

#include "datagraphicsscene.h"
#include "game.h"

DataGraphicsScene::DataGraphicsScene(QObject *parent):
    QGraphicsScene (parent)
{
    scene = new QGraphicsScene(parent);
//    this->setOptimizationFlag(QGraphicsView::DontAdjustForAntialiasing);
//    this->setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
    int id = QFontDatabase::addApplicationFont("../Game/second.ttf");
    font = new QFont(QFontDatabase::applicationFontFamilies(id).first());
    border_pixmap = QPixmap("../Game/border.png").scaled(200,200, Qt::IgnoreAspectRatio);
    attack_pixmap = QPixmap("../Game/attack.png").scaled(100,100,Qt::IgnoreAspectRatio);
    heart_pixmap = QPixmap("../Game/heart.png").scaled(50,50,Qt::IgnoreAspectRatio);
    money_pixmap = QPixmap("../Game/money.png").scaled(60,60,Qt::IgnoreAspectRatio);
    steps_pixmap = QPixmap("../Game/steps.png").scaled(60,60,Qt::IgnoreAspectRatio);
}

void DataGraphicsScene::refresh_scene(Player *player, QString type_object)
{
    if(type_object == "unit")
        this->player = player;
    if(type_object == "castle")
        this->castle = player->castle;
    update(0,0,this->width(),this->height());
}

void DataGraphicsScene::drawBackground(QPainter *painter, const QRectF &rect)
{   
    for (int x=0;x<this->width();x+=100)
    {
        for (int y=0;y<2;y++)
            painter->drawPixmap(x,y*100,QPixmap("../Game/background-2.png").scaled(100,100,Qt::IgnoreAspectRatio));
    }
    painter->setPen(Qt::white);
    painter->drawPixmap(0,0,border_pixmap);
    painter->drawPixmap(430,60,attack_pixmap);
    painter->drawPixmap(430,135,heart_pixmap);
    painter->drawPixmap(650,130,money_pixmap);
    painter->drawPixmap(650,70,steps_pixmap);

    font->setPixelSize(30);
    painter->setFont(*font);
    painter->drawText(420,30,"Имя игрока:");
    painter->drawText(420,70,"Тип выбранного юнита:");

    if(!player)
    {
        font->setPixelSize(15);
        painter->setFont(*font);
        painter->drawText(30,100,"Изображение");
        painter->drawText(30,120,"отсутствует");
        return;
    }
    else
    {
        font->setPixelSize(40);
        painter->setFont(*font);
        painter->drawText(50,100,QString::number(player->nomber_player));
        painter->drawText(640,30,player->Name);


        painter->drawText(710,175,"X "+QString::number(player->count_money));
        Game *game = Game::GetInstance();

        if(!player->move_unit())
        {
            if(castle)
            {
                font->setPixelSize(40);
                painter->setFont(*font);
                painter->drawText(50,100,QString::number(player->nomber_player));
                painter->drawText(640,30,player->Name);

                painter->drawPixmap(200,0,QPixmap("../Game/21.png").scaled(200,200,Qt::IgnoreAspectRatio));
                font->setPixelSize(50);
                painter->setFont(*font);
                painter->drawText(535,120,"0");
                painter->drawText(485,175,QString::number(castle->health));
                font->setPixelSize(30);
                painter->setFont(*font);
                painter->drawText(875,70,"Замок");

                return;
            }
            else
            {
                font->setPixelSize(20);
                painter->setFont(*font);
                painter->drawText(230, 30, "Юнит");
                painter->drawText(230, 50, "Не выбран");
                font->setPixelSize(50);
                painter->setFont(*font);
                painter->drawText(535,120,"0");
                painter->drawText(485,175,"0");

                return;
            }
        }
        else
        {
            Unit *unit = player->move_unit();
            painter->drawPixmap(200,0,QPixmap("../Game/"+QString::number(unit->id_unit)+".png").scaled(200,200,Qt::IgnoreAspectRatio));
            font->setPixelSize(50);
            painter->setFont(*font);
            painter->drawText(535,120,QString::number(unit->demage));
            painter->drawText(485,175,QString::number(unit->health));
            painter->drawText(730,120,QString::number(unit->count_steps));
            font->setPixelSize(30);
            painter->setFont(*font);
            painter->drawText(875,70,"Юнит");
            return;
        }
    }
}


