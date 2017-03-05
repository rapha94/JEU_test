#include "Enemy.h"

#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QMediaPlayer>

#include "stdlib.h"
#include "Game.h"
#include "Score.h"
#include "MyRect.h"

extern Game *game;

Enemy::Enemy()
{

    // random position
    int random_number = rand() % 700;
    setPos(random_number, 0);

    setPixmap(QPixmap(":/image/fille.png"));
    setTransformOriginPoint(50,50);


   QTimer * timer = new QTimer();
   connect(timer, SIGNAL(timeout()), this, SLOT(move()));

   timer->start(50);


}

void Enemy :: move()
{

   //if (score <= 2)
       setPos(x(), y() +10);
   //else
       //setPos(x(), y() +30);



       // colision entre l'enemy et le mini horny king kong
       QList<QGraphicsItem *> collinding_items = collidingItems();
       for (int i = 0, n = collinding_items.size(); i < n; ++i )
       {
           if (typeid(*(collinding_items[i]))==typeid(MyRect)){

               game->displayGOMenu();

           }
       }





    if (pos().y() > 1000){
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
    }
}
