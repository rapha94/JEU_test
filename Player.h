#ifndef MYRECT_H
#define MYRECT_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>
#include <QGraphicsItem>

class Player: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player (QGraphicsItem * parent=0 );
    void keyPressEvent(QKeyEvent *event);

public slots:
    void spawn();
private:
    QMediaPlayer *bullet_son;


};

#endif // MYRECT_H

