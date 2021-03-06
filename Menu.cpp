#include "Menu.h"
#include <QBrush>
#include <QGraphicsTextItem>
#include <QDebug>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QDebug>

#include "Control.h"


Menu::Menu(QString name, QGraphicsItem *parent) : QGraphicsRectItem(parent)
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

void Menu::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    emit clicked();
}


void Menu::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);

}


void Menu::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::blue);
    setBrush(brush);

}



