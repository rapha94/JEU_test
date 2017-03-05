#include "Game_over.h"

#include "Menu.h"
#include <QBrush>
#include <QGraphicsTextItem>



Game_over::Game_over(QString name, QGraphicsItem *parent) : QGraphicsRectItem(parent)
{
    setRect(0,0,200,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::blue);
    setBrush(brush);



    QGraphicsTextItem *text = new QGraphicsTextItem(name, this);
    int xPos = rect().width()/2-text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text -> boundingRect().height()/2;
    text->setPos(xPos, yPos);

    setAcceptHoverEvents(true);

}

void Game_over::moussePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}


void Game_over::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);

}

void Game_over::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::blue);
    setBrush(brush);

}
