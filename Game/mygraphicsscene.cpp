#include "mygraphicsscene.h"
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
#include <iostream>
#include <QTransform>
#include <QObject>

#include <QGraphicsEffect>

#include <QFile>
#include <QTextStream>
#include <QPainter>
#include "unit.h"
#include "castle.h"

#include <QGraphicsItem>

#include "mainwindow.h"
#include "buy_units.h"
#include "game.h"



void MyGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        coord_first = event->scenePos();
        if(!chooseUnit())
        {
            if(unit_inst)
            {
                Unit *unit = dynamic_cast<Unit*>(unit_inst);
                if(unit)
                {
                    delete  unit->graphicsEffect();
                    QGraphicsDropShadowEffect *bodyShadow = new QGraphicsDropShadowEffect;
                    bodyShadow->setBlurRadius(9.0);
                    bodyShadow->setColor(QColor(0, 0, 0, 160));
                    bodyShadow->setOffset(4.0);
                    unit->setGraphicsEffect(bodyShadow);

//                    unit->choose = false;
//                    if(this->group_line!=NULL)
                    if(this->line_group.length()!=0)
                    {
//                        delete  this->group_line;
                        for (int i=0;i<line_group.length();i++)
                            delete this->line_group[i];
                        this->line_group.clear();
                    }
//                    delete this->unit_inst;
                    this->unit_inst = NULL;
                    this->way_drow = false;
                    this->update(0,0,this->width(),this->height());
                }
            }

        }
    }
    else if  (event->button() == Qt::RightButton && event->scenePos().x()>0 &&
              event->scenePos().y() > 0 && event->scenePos().x() < this->width() && event->scenePos().y()<this->height())
    {
        coord_second = event->scenePos();
        if(coord_second.x() < this->width() && coord_second.y() < this->height())
        {
            Unit *new_unit = dynamic_cast<Unit*>(this->itemAt(coord_second,QTransform()));
            Game *game = Game::GetInstance();
            if(unit_inst!=NULL)
            {
                Unit *unit = dynamic_cast<Unit*>(unit_inst);
                if(this->way_drow)
                {
                    for (int i=0;i<line_group.length();i++)
                        delete this->line_group[i];
                    this->line_group.clear();
                    this->way_drow = false;
                }
                unit->next_cell(this,QPoint(coord_first.x(),coord_first.y()), QPoint(coord_second.x(),coord_second.y()),
                                game->map.width,game->map.height, unit->array_map, unit->count_steps);
            }
        }
    }
    this->update(0,0,width(), height());
}
void MyGraphicsScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if(mouseEvent->button() == Qt::RightButton && this->way_drow)
    {
        Unit *unit = dynamic_cast<Unit*>(unit_inst);
        MainWindow *win = MainWindow::GetInstance();
        QGraphicsView *viev = win->GetInstanceGraphicsView();
        viev->setEnabled(false);
        if(unit->count_steps>0)
        {
            Game *game = Game::GetInstance();
            Unit *attack_unit = dynamic_cast<Unit*>(this->itemAt(mouseEvent->scenePos(), QTransform()));
            if (attack_unit)
            {
                unit->movement(this, unit->count_steps, "attack");
            }
            else
                unit->movement(this, unit->count_steps);
        }
        else
            viev->setEnabled(true);
    }
}

bool MyGraphicsScene::chooseUnit()
{
    Unit *unit = dynamic_cast<Unit*>(scene->itemAt(coord_first,QTransform()));
    Game *game = Game::GetInstance();
    bool index = false;
    for (int i=0;i<game->list_players.length();i++)
    {
        if(game->list_players[i]->list_units.indexOf(unit)>=0)
            if(game->list_players[i]->move)
                index = true;
    }
    if(unit && index)
    {
        if(unit!=unit_inst && unit_inst)
        {
            if(this->way_drow)
            {
                for (int i=0;i<line_group.length();i++)
                    delete this->line_group[i];
                this->line_group.clear();
                this->way_drow = false;
            }
            int index_player;
            for (int i=0;i<game->list_players.length();i++)
                if(game->list_players[i]->move)
                    index_player = i;
            QGraphicsDropShadowEffect *bodyShadow = new QGraphicsDropShadowEffect;
            bodyShadow->setBlurRadius(9.0);
            bodyShadow->setColor(QColor(0, 0, 0, 160));
            bodyShadow->setOffset(4.0);
            for (int i=0; i<game->list_players[index_player]->list_units.length();i++)
                if(game->list_players[index_player]->list_units[i]->graphicsEffect())
                {
                    delete game->list_players[index_player]->list_units[i]->graphicsEffect();
                    game->list_players[index_player]->list_units[i]->setGraphicsEffect(bodyShadow);
                }
//            Unit *old_unit = dynamic_cast<Unit*>(unit_inst);
//            delete old_unit->graphicsEffect();

        }
        QGraphicsDropShadowEffect *bodyShadow = new QGraphicsDropShadowEffect;
        bodyShadow->setBlurRadius(10.0);
        bodyShadow->setColor(Qt::yellow);
        bodyShadow->setOffset(0.0);
        unit->setGraphicsEffect(bodyShadow);
//        unit->choose = true;
        unit_inst = unit;
        return true;
    }
    Castle *castle = dynamic_cast<Castle*>(scene->itemAt(coord_first, QTransform()));
    if(castle)
    {
        chooseCastle(castle);
        return true;
    }
    else return false;
}
bool MyGraphicsScene::chooseCastle(QGraphicsObject *castle)
{
    Castle *new_castle = static_cast<Castle*>(castle);
    if(this->way_drow)
    {
        for (int i=0;i<line_group.length();i++)
            delete this->line_group[i];
        this->line_group.clear();
        this->way_drow = false;
    }

    Buy_units *nol = new Buy_units();

}

void MyGraphicsScene::delete_first_line()
{
    delete line_group[0];
    line_group.removeAt(0);
}

void MyGraphicsScene::delete_all_line()
{
    if(line_group.length()!=0)
    {
        for(int i=0;i<line_group.length();i++)
            delete line_group[i];
        line_group.clear();
    }
}

void MyGraphicsScene::enable_scene()
{
    MainWindow *win = MainWindow::GetInstance();
    QGraphicsView *viev = win->GetInstanceGraphicsView();
    viev->setEnabled(true);
}


