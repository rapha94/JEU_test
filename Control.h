#ifndef CONTROL_H
#define CONTROL_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

#include "Game.h"


class Control{

    Q_OBJECT

public:

    Control ();

    void afficheMainMenu();
    void start();
    void afficheGOMenu();
    void quitter();
    void health_decrease();

};







#endif // CONTROL_H
