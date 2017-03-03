#ifndef MENU_H
#define MENU_H

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>
#include <QObject>



class Menu: public QObject, public QGraphicsRectItem{

    Q_OBJECT

public:
   Menu(QString name, QGraphicsItem* parent=NULL);



    void moussePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);


signals:
    void clicked();

private:
   QString text;

};

#endif // MENU_H
