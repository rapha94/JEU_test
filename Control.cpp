#include "Control.h"
#include "Menu.h"

#include <QDebug>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QWidget>
#include <QMediaPlayer>



#include "Game.h"
#include "Menu.h"



Control::Control()
{
    score = new Score;
}

void Control::afficheMainMenu()
{
    game = new Game();
    //game->displayMainMenu();
    game->setScore(score->getScore());
}


void Control::start()
{
    game = new Game();
    game->setScore(score->getScore());

}

void Control::afficheGOMenu()
{

    //son qd il y a le game over
    QMediaPlayer * son= new QMediaPlayer();
    son->setMedia(QUrl("qrc:/sons/game_over.mp3"));
    son->play();


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

void Control::augmenter_score()
{
    score->increase();
    game->setScore(score->getScore());
}




