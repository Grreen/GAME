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
#include "datagraphicsscene.h"



void MyGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Game *game = Game::GetInstance();
    if(game->game_play)
    {
        if (event->button() == Qt::LeftButton)
        {
            coord_first = event->scenePos();
            if(!chooseUnit())
            {
                if(unit_inst)
                {
                    QGraphicsDropShadowEffect *bodyShadow = new QGraphicsDropShadowEffect;
                    bodyShadow->setBlurRadius(9.0);
                    bodyShadow->setColor(QColor(0, 0, 0, 160));
                    bodyShadow->setYOffset(-2.0);
                    bodyShadow->setXOffset(5.0);

                    unit_inst->setGraphicsEffect(bodyShadow);
                }
                delete_unit_inst();
                delete_way();

                DataGraphicsScene *scene = dynamic_cast<DataGraphicsScene*>(MainWindow::GetInstance()->GetInstanceGraphicsView(1)->scene());
                scene->refresh_scene(game->move_player());
            }
        }
        else if  (event->button() == Qt::RightButton && event->scenePos().x()>0 &&
                  event->scenePos().y() > 0 && event->scenePos().x() < this->width() && event->scenePos().y()<this->height())
        {
            coord_second = event->scenePos();
            if(coord_second.x() < this->width() && coord_second.y() < this->height())
            {
                if(unit_inst)
                {
                    Unit *unit = dynamic_cast<Unit*>(unit_inst);

                    delete_way();

                    unit->next_cell(this,QPoint(coord_first.x(),coord_first.y()), QPoint(coord_second.x(),coord_second.y()),
                                    game->map.width,game->map.height, unit->count_steps);
                }
            }
        }
    }
}
void MyGraphicsScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    Game *game = Game::GetInstance();
    if(game->game_play)
    {
        if(mouseEvent->button() == Qt::RightButton && way_drow)
        {
            Unit *unit = dynamic_cast<Unit*>(unit_inst);
            if(unit->count_steps>0)
            {
                if(game->map.map[(int)mouseEvent->scenePos().x()/game->map.scene->size_items]
                                [(int)mouseEvent->scenePos().y()/game->map.scene->size_items] != -3)
                {
                    unit->movement(game->map.scene, unit->count_steps);
                }
                else
                {
                    int index_player = index_move_player();

                    Castle *attack_castle = dynamic_cast<Castle*>(game->map.scene->itemAt(mouseEvent->scenePos(), QTransform()));
                    if(attack_castle)
                    {
                        if(game->list_players[index_player]->castle == attack_castle)
                            unit->movement(game->map.scene, unit->count_steps, "ally");
                        else
                            unit->movement(game->map.scene, unit->count_steps, "attack castle");
                        return;
                    }
                    Unit *attack_unit = dynamic_cast<Unit*>(game->map.scene->itemAt(mouseEvent->scenePos(), QTransform()));
                    if(attack_unit && attack_unit!=unit)
                    {
                        if(game->list_players[index_player]->list_units.indexOf(attack_unit)>=0)
                            unit->movement(game->map.scene, unit->count_steps, "ally");
                        else
                            unit->movement(game->map.scene, unit->count_steps, "attack unit");
                        return;
                    }
                }


            }
        }
    }
}

bool MyGraphicsScene::chooseUnit()
{
    Game *game = Game::GetInstance();

    if(game->map.map[(int)coord_first.x()/game->map.scene->size_items][(int)coord_first.y()/game->map.scene->size_items] != -3)
        return false;

    Unit *unit = dynamic_cast<Unit*>(scene->itemAt(coord_first,QTransform()));

    bool index = false;
    int index_player;
    for (int i=0;i<game->list_players.length();i++)
    {
        if(game->list_players[i]->list_units.indexOf(unit)>=0)
        {
            index_player = i;
            if(game->list_players[i]->move)
            {
                index = true;
                break;
            }
        }
    }
    if(unit && index)
    {
        DataGraphicsScene *scene = dynamic_cast<DataGraphicsScene*>(MainWindow::GetInstance()->GetInstanceGraphicsView(1)->scene());
        scene->refresh_scene(game->list_players[index_player]);

        if(unit!=unit_inst && unit_inst)
        {
            delete_way();

            QGraphicsDropShadowEffect *bodyShadow = new QGraphicsDropShadowEffect;
            bodyShadow->setBlurRadius(9.0);
            bodyShadow->setColor(QColor(0, 0, 0, 160));
            bodyShadow->setYOffset(-2.0);
            bodyShadow->setXOffset(5.0);

            Unit *old_unit = dynamic_cast<Unit*>(unit_inst);
            old_unit->choose_unit = false;
            delete old_unit->graphicsEffect();
            old_unit->setGraphicsEffect(bodyShadow);
        }
        QGraphicsDropShadowEffect *bodyShadow = new QGraphicsDropShadowEffect;
        bodyShadow->setBlurRadius(10.0);
        bodyShadow->setColor(Qt::yellow);
        bodyShadow->setOffset(0.0);
        unit->setGraphicsEffect(bodyShadow);
        unit->choose_unit = true;
        unit_inst = unit;
        return true;
    }
    Castle *castle = dynamic_cast<Castle*>(scene->itemAt(coord_first, QTransform()));
    if(castle)
    {
        delete_way();

        int index_player = index_move_player();

        if(game->list_players[index_player]->castle == castle)
        {
            game->list_players[index_player]->refreshUnits();
            DataGraphicsScene *scene = dynamic_cast<DataGraphicsScene*>(MainWindow::GetInstance()->GetInstanceGraphicsView(1)->scene());
            scene->refresh_scene(game->move_player(),"castle");
            chooseCastle();
            return true;
        }
        else return false;
    }
    else return false;
}
void MyGraphicsScene::chooseCastle()
{
    delete_unit_inst();
    delete_way();
    Buy_units *nol = new Buy_units();
}

void MyGraphicsScene::delete_first_line()
{
    delete line_group.first();
    line_group.removeFirst();
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
    QGraphicsView *viev = win->GetInstanceGraphicsView(1);
    viev->setEnabled(true);
}

void MyGraphicsScene::delete_unit_inst()
{
    if(unit_inst)
    {
        Unit *old_unit = dynamic_cast<Unit*>(unit_inst);
        old_unit->choose_unit = false;

        QGraphicsDropShadowEffect *bodyShadow = new QGraphicsDropShadowEffect;
        bodyShadow->setBlurRadius(9.0);
        bodyShadow->setColor(QColor(0, 0, 0, 160));
        bodyShadow->setYOffset(-2.0);
        bodyShadow->setXOffset(5.0);

        old_unit->setGraphicsEffect(bodyShadow);
        unit_inst = 0;
    }
}

void MyGraphicsScene::delete_way()
{
    if(this->way_drow)
    {
        for (int i=0;i<line_group.length();i++)
            delete this->line_group[i];
        this->line_group.clear();
        this->way_drow = false;
    }
}

int MyGraphicsScene::index_move_player()
{
    Game *game = Game::GetInstance();
    for (int i=0;i<game->list_players.length();i++)
        if(game->list_players[i]->move)
            return  i;
}

QGraphicsObject* MyGraphicsScene::GetUnitInst()
{
    return unit_inst;
}
