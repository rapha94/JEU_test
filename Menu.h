#ifndef MENU_H
#define MENU_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsSceneMouseEvent>




class Menu: public QObject, public QGraphicsRectItem{

    Q_OBJECT

public:
   Menu(QString name, QGraphicsItem* parent=NULL);



    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);


signals:
    void clicked();


private:
   QGraphicsRectItem * text;

};

#endif // MENU_H
