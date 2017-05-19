#ifndef HEALTH_H
#define HEALTH_H


#include <QGraphicsTextItem>
#include <QObject>




class Health : public QGraphicsTextItem
{

public:
    Health(QGraphicsItem * parent=0);
    void decrease();
    int getHealth();
    void razHealth();
   // Game *game;

private:
    int health;
};

#endif // HEALTH_H
