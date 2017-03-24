#ifndef CONTROL_H
#define CONTROL_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

#include "Game.h"


class Control: public QObject {

    Q_OBJECT

public:

    Control ();

    void afficheMainMenu();
    void start();
    void afficheGOMenu();
    void quitter();
    void health_decrease();
    void augmenter_score();
    void score();

};







#endif // CONTROL_H