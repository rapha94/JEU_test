#include "Game.h"
#include <QTimer>
#include <QFont>
#include "Enemy.h"
#include <QGraphicsItem>
#include <QMediaPlayer>
#include <QGraphicsPixmapItem>
#include <QImage>



Game::Game(QWidget *parent){

    // création de la scene de jeu
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setScene(scene);
    setFixedSize(800, 600);

    setBackgroundBrush(QBrush(QImage(":/image/NY.jpg")));



    // création d'un item a mettre dans la scene
    player = new MyRect();
    player->setPixmap(QPixmap(":/image/King_Kong.jpg"));
    player->setPos(400, 500);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    scene->addItem(player);

    //creation du score
    score = new Score();
    scene-> addItem(score);

    health =new Health();
    health->setPos(health->x(), health->y()+25);
    scene->addItem(health);


    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000);

    QMediaPlayer * music= new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sons/Explosion.mp3"));
    music->play();
    show();

}


