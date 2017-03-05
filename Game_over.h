#ifndef GAME_OVER_H
#define GAME_OVER_H


#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsSceneMouseEvent>




class Game_over: public QObject, public QGraphicsRectItem{

    Q_OBJECT

public:
   Game_over(QString name, QGraphicsItem* parent=NULL);



    void moussePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);


signals:
    void clicked();

private:
   QGraphicsRectItem * text;

};
#endif // GAME_OVER_H
