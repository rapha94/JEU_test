#include "Enemy.h"

#include <QTimer>
#include <QGraphicsScene>
#include "stdlib.h"
#include "Game.h"

extern Game *game;

Enemy::Enemy()
{

    // random position
    int random_number = rand() % 700;
    setPos(random_number, 0);

    setPixmap(QPixmap(":/image/fille.png"));
    setTransformOriginPoint(50,50);
    //setPixmap(QSize(50,50));


   QTimer * timer = new QTimer();
   connect(timer, SIGNAL(timeout()), this, SLOT(move()));

   timer->start(50);


}

void Enemy :: move()
{
    setPos(x(), y() +5);
    if (pos().y() > 1000){
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
    }
}
