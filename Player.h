#ifndef MYRECT_H
#define MYRECT_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>
#include <QGraphicsItem>

#include "Enemy.h"


class Player: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player (QGraphicsItem * parent=0 );
    void keyPressEvent(QKeyEvent *event);
    void razPlayer();
    Enemy *enemy;

public slots:
    void spawn();
private:
    QMediaPlayer *bullet_son;


};

#endif // MYRECT_H

