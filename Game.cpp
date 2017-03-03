#include <QTimer>
#include <QFont>
#include <QGraphicsItem>
#include <QMediaPlayer>
#include <QGraphicsPixmapItem>
#include <QImage>
#include <QGraphicsRectItem>

#include "Enemy.h"
#include "Menu.h"
#include "Game.h"



Game::Game(QWidget *parent){

    // création de la scene de jeu
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setScene(scene);
    setFixedSize(800, 600);

    setBackgroundBrush(QBrush(QImage(":/image/Image_de_fond.jpg")));


    // création d'un item a mettre dans la scene
    player = new MyRect();
    player->setPixmap(QPixmap(":/image/singeLOL.gif"));
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
    music->setMedia(QUrl("qrc:/sons/Chocolate.mp3"));
    music->play();
    show();

}




/*
void Game::displayMainMenu()

{

   QGraphicsTextItem *titleText =new QGraphicsTextItem (QString("hey bro"));
    QFont titleFont("comics sans", 50);
    titleText->setFont(titleFont);
    scene->addItem(titleText);


    int Posx = this->width()/2 - titleText->boundingRect().width()/2;
    int Posy = 150;
    titleText->setPos(Posx, Posy);

    //bouton jouer
    Menu *playButton = new Menu(QString("PLAY"));
   // connect(playButton, SIGNAL(clicked()), this, SLOT(start()));

    int Jouer_Posx = this->width()/2 - playButton->boundingRect().width()/2;
    int Jouer_Posy = 500;
    playButton->setPos(Jouer_Posx,Jouer_Posy);
    scene-> addItem(playButton);




    //bouton quitter
    Menu *quitButton = new Menu(QString("QUIT"));
   // connect(quitButton, SIGNAL(clicked()), this, SLOT(quit()));

    int Quitter_Posx = this->width()/2 - quitButton->boundingRect().width()/2;
    int Quitter_Posy = 350;
    playButton->setPos(Quitter_Posx,Quitter_Posy);
    scene-> addItem(quitButton);

}


void Game::start()
{

}


void Game::quit()
{
    quit();
}

*/





