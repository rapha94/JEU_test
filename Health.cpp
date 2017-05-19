#include "Health.h"
#include "Game.h"

#include <QFont>
#include <QApplication>
#include "Control.h"

extern Control *control;

Health::Health(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    health = 3;
    setPlainText("Health: " + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));

}


void Health::decrease()
{

    if (health<=0)
        control->afficheGOMenu();

    else
        health--;
        setPlainText("Health: " + QString::number(health));
}


int Health::getHealth()
{
    return health;
}


void Health::razHealth()
{
    delete this;
}




