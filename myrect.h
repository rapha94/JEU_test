#ifndef MYRECT_H
#define MYRECT_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>
#include <QGraphicsItem>

class MyRect: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    MyRect (QGraphicsItem * parent=0 );
    void keyPressEvent(QKeyEvent *event);

public slots:
    void spawn();
private:
    QMediaPlayer *bullet_son;


};

#endif // MYRECT_H

