#include "Control.h"
#include "Menu.h"

#include <QDebug>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

#include "Game.h"



extern Game *game;


/*
void Control::afficheMainMenu()
{
    game = new Game();
    game->displayMainMenu();
}
*/

void Control::start()
{
    game = new Game();
}

void Control::afficheGOMenu()
{
    game->displayGOMenu();
}

void Control::quitter()
{
    qApp->quit();
}

void Control::health_decrease()
{
    game->health->decrease();

}


