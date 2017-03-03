#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include<QList>
#include"Enemy.h"
#include "Game.h"

extern Game * game;

Bullet::Bullet()
{
    setPixmap(QPixmap(":/image/banane.png"));
    setTransformOriginPoint(50,50);
    setRotation(-90);



   QTimer * timer = new QTimer();
   connect(timer, SIGNAL(timeout()), this, SLOT(move()));

   timer->start(50);


}

void Bullet :: move()
{

    //supprimer bullet et enemy s'il y a collision
    QList<QGraphicsItem *> collinding_items = collidingItems();
    for (int i = 0, n = collinding_items.size(); i < n; ++i )
    {
        if (typeid(*(collinding_items[i]))==typeid(Enemy)){

            game->score->increase();

            scene()->removeItem(collinding_items[i]);
            scene()->removeItem(this);

            delete collinding_items[i];
            delete this;
            return;
        }
    }



    setPos(x(), y() -10);
    if (pos().y() >1300){
        scene()->removeItem(this);
        delete this;
    }
}


