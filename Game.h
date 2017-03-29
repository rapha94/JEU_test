#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QWidget>
#include <QGraphicsView>
#include <QObject>

#include "Player.h"
#include "Score.h"
#include "Health.h"
#include "Enemy.h"
#include "Menu.h"



class Game : public QGraphicsView {

    Q_OBJECT

public:
    Game(QWidget * parent=0);

    QGraphicsScene *scene;
    Player *player;
    QGraphicsTextItem *score;
    Health *health;
    //Game *game;
    //Enemy *enemy;
    void displayMainMenu();
    void displayGOMenu();
    void setScore(const QString &s);

    void supprimerItem();
public slots:
    void quit();
    void start();




};

#endif // GAME_H
