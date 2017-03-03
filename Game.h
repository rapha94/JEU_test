#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QWidget>
#include <QGraphicsView>
#include <QObject>

#include "MyRect.h"
#include "Score.h"
#include "Health.h"


class Game : public QGraphicsView {

    Q_OBJECT

public:
    Game(QWidget * parent=0);

    QGraphicsScene *scene;
    MyRect *player;
    Score *score;
    Health *health;




    void displayMainMenu();

public slots:
    void quit();
    void start();


   // void start();


};

#endif // GAME_H
