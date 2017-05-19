#include "Enemy.h"

#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QMediaPlayer>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QString>
#include <QDebug>

#include "stdlib.h"
#include "Game.h"
#include "Score.h"
#include "Player.h"
#include "Control.h"


extern Game *game;
//extern Score *score;
extern Control *control;


Enemy::Enemy(QGraphicsItem * parent) : QGraphicsPixmapItem(parent)
{


    // random position
    int random_number = rand() % 700;
    setPos(random_number, 0);

    setPixmap(QPixmap(":/image/fille.png"));
    setTransformOriginPoint(50,50);


   timer = new QTimer();
   connect(timer, SIGNAL(timeout()), this, SLOT(move()));

   timer->start(50);

}

void Enemy::razEnemy()
{
    timer->stop();
    delete this;
}



void Enemy :: move()
{
    int score;

     if (score <= 3 )
        setPos(x(), y() +10);
    else //if (score->score >=2 && score->score <8)

        setPos(x(), y() +40);

 /* else if (score >=8, score <20)
       setPos(x(), y() +15);

   else if (score >=20, score <30)
       setPos(x(), y() +25);

   else if (score >=30, score <40)
       setPos(x(), y() +40);

   else if (score >=40, score <60)
       setPos(x(), y() +50);

   else
       setPos(x(), y() +80);*/



       // colision entre l'enemy et le mini horny king kong
       QList<QGraphicsItem *> collinding_items = collidingItems();
       for (int i = 0, n = collinding_items.size(); i < n; ++i )
       {
           if (typeid(*(collinding_items[i]))==typeid(Player)){

               control->afficheGOMenu();

           }
       }


    if (pos().y() > 1000){
        control->health_decrease();
        scene()->removeItem(this);
        delete this;
    }
}
