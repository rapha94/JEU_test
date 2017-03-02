#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QWidget>
#include <QGraphicsView>

#include "MyRect.h"
#include "Score.h"
#include "Health.h"


class Game : public QGraphicsView {

public:
    Game(QWidget * parent=0);

    QGraphicsScene *scene;
    MyRect *player;
    Score *score;
    Health *health;




};

#endif // GAME_H
