#include "MyRect.h"
#include <QKeyEvent>
#include "Bullet.h"
#include <QGraphicsScene>

#include "Enemy.h"
#include "Game.h"



MyRect::MyRect(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    bullet_son =new QMediaPlayer;
    bullet_son->setMedia(QUrl("qrc:/sons/Tire.mp3"));
}


void MyRect::keyPressEvent(QKeyEvent * event)
{
    if (event->key() == Qt::Key_Left)
    {
        if (pos().x()>0)
        setPos (x() -30, y());
    }

    else if (event->key() == Qt::Key_Right)
    {
        if (pos().x() + 130 <1200)
        setPos(x() +30, y());
    }

    else if (event->key() == Qt::Key_Up)
    {
        if (pos().x() <900)
        setPos(x(), y() -30);
    }

    else if (event->key() == Qt::Key_Down)
    {
        if (pos().x() + 100 <900)
        setPos(x(), y() +30);
    }




    else if(event->key() == Qt::Key_Space)
    {
        Bullet * bullet = new Bullet();
        bullet->setPos(x(), y());
        scene()->addItem(bullet);


        if (bullet_son->state() == QMediaPlayer::PlayingState)
        {
            bullet_son->setPosition(0);
        }
        else if (bullet_son->state() == QMediaPlayer::StoppedState)
        {
        bullet_son->play();
        }
    }




}

void MyRect::spawn()
{

        Enemy *enemy = new Enemy();
        scene()->addItem(enemy);

}


