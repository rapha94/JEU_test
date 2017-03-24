#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>


#include "Score.h"
//#include "Control.h"

class Enemy: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    Enemy (QGraphicsItem * parent=0);
   // int score;
    //Score *score;

public slots:
    void move(); //Score *score




};

#endif //ENEMY_H
