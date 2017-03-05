#include "Health.h"
#include "Game.h"

#include <QFont>
#include <QApplication>
#include "Game.h"

extern Game *game;


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
        game->displayGOMenu();
    else
        health--;
        setPlainText("Health: " + QString::number(health));

}


int Health::getHealth()
{
    return health;
}




