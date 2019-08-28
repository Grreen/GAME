#include <QScrollBar>

#include <QAbstractItemView>

#include "graphicspanel.h"
#include "game.h"
//#include "mygraphicsscene.h"

GraphicsPanel::GraphicsPanel(QObject *parent):
    QGraphicsScene (parent)
{
    scene = new QGraphicsScene(parent);
}

void GraphicsPanel::refresh_panel(Player *player)
{
    if(list_objects.length()>0)
    {
        for (int i=0;i<list_objects.length();i++)
            delete list_objects[i];
        list_objects.clear();
    }
    Game *game = Game::GetInstance();

    if(player->castle)
    {
        Castle *new_castle = new Castle(game->map.scene, QPoint(0,0), "21");
        new_castle->health = player->castle->health;
        new_castle->coord = player->castle->coord;
        new_castle->resize(100);

        this->addItem(new_castle);
        new_castle->setPos(this->width()/2-50,20);

        list_objects.append(new_castle);
    }
    if(player->list_units.length()>0)
    {
        int y = 140;
        int x;
        for (int i=0;i<player->list_units.length();i++)
        {
            Unit *new_unit = new Unit(QPoint(0,0), game->map.scene,player->list_units[i]->id_unit);
            new_unit->health = player->list_units[i]->health;
            new_unit->coord = player->list_units[i]->coord;
            new_unit->nomber_unit = player->list_units[i]->nomber_unit;
            new_unit->resize(90);

            this->addItem(new_unit);

            if(i%2 == 0)
                x = 35;
            else
                x += 130;

            new_unit->setPos(x,y);

            if(i%2 == 1)
                y+=130;

            list_objects.append(new_unit);
        }
    }
}

void GraphicsPanel::refresh_data(Unit *unit)
{
    if(unit)
    {
        for (int i=1;i<list_objects.length();i++)
        {
            Unit *unit_panel = dynamic_cast<Unit*>(list_objects[i]);
            if(unit_panel->nomber_unit == unit->nomber_unit)
            {
                unit_panel->coord = unit->coord;
                unit_panel->health = unit->health;
                break;
            }
        }
    }
}

void GraphicsPanel::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if(mouseEvent->button() == Qt::LeftButton &&
       mouseEvent->scenePos().x()>0 && mouseEvent->scenePos().y()>0 &&
       mouseEvent->scenePos().x()<this->width() && mouseEvent->scenePos().y()<this->height())
    {
        Game *game = Game::GetInstance();
        Castle *castle = dynamic_cast<Castle*>(this->itemAt(mouseEvent->scenePos(), QTransform()));

        if(game->map.scene->GetUnitInst())
        {
            QGraphicsDropShadowEffect *bodyShadow = new QGraphicsDropShadowEffect;
            bodyShadow->setBlurRadius(9.0);
            bodyShadow->setColor(QColor(0, 0, 0, 160));
            bodyShadow->setYOffset(-2.0);
            bodyShadow->setXOffset(5.0);

            game->map.scene->GetUnitInst()->setGraphicsEffect(bodyShadow);
            Unit *unit = dynamic_cast<Unit*>(game->map.scene->GetUnitInst());
            unit->choose_unit = false;

            game->map.scene->delete_unit_inst();
            game->map.scene->delete_way();
        }

        if(castle)
        {
            game->graphicsView->horizontalScrollBar()->setSliderPosition(castle->coord.x()+game->map.scene->size_items/2-game->graphicsView->width()/2);
            game->graphicsView->verticalScrollBar()->setSliderPosition(castle->coord.y()+game->map.scene->size_items/2-game->graphicsView->height()/2);
            return;
        }
        Unit *unit = dynamic_cast<Unit*>(this->itemAt(mouseEvent->scenePos(),QTransform()));
        if(unit)
        {
            game->graphicsView->horizontalScrollBar()->setValue(unit->coord.x()+game->map.scene->size_items/2-game->graphicsView->width()/2);
            game->graphicsView->verticalScrollBar()->setValue(unit->coord.y()+game->map.scene->size_items/2-game->graphicsView->height()/2);
            return;
        }
    }
}

void GraphicsPanel::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if(mouseEvent->button() == Qt::LeftButton &&
       mouseEvent->scenePos().x()>0 && mouseEvent->scenePos().y()>0 &&
       mouseEvent->scenePos().x()<this->width() && mouseEvent->scenePos().y()<this->height())
    {
        Game *game = Game::GetInstance();
        Castle *castle = dynamic_cast<Castle*>(this->itemAt(mouseEvent->scenePos(), QTransform()));
        if(castle)
        {
           game->map.scene->chooseCastle();
           return;
        }
        Unit *unit = dynamic_cast<Unit*>(this->itemAt(mouseEvent->scenePos(), QTransform()));
        if(unit)
        {
            game->map.scene->coord_first = unit->coord;
            game->map.scene->chooseUnit();
            return;
        }

        //попробовать сделать выделение юнита
    }

}
