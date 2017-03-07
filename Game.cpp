#include <QTimer>
#include <QFont>
#include <QGraphicsItem>
#include <QMediaPlayer>
#include <QGraphicsPixmapItem>
#include <QImage>
#include <QGraphicsRectItem>
#include <QApplication>
#include <QObject>

#include <QDebug>

#include "Enemy.h"
#include "Menu.h"
#include "Game.h"
#include "MyRect.h"

extern Game *game;

Game::Game(QWidget *parent){

    // création de la scene de jeu
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1200,900);
    setScene(scene);
    setFixedSize(1200, 900);

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



void Game::displayMainMenu()

{

   QGraphicsTextItem *titleText =new QGraphicsTextItem (QString("MENU"));
    QFont titleFont("comics sans", 50);
    titleText->setFont(titleFont);
    scene->addItem(titleText);


    int Posx = this->width()/2 - titleText->boundingRect().width()/2;
    int Posy = 150;
    titleText->setPos(Posx, Posy);


    //bouton jouer
    Menu *playButton = new Menu(QString("PLAY"));
    int Jouer_Posx = this->width()/2 - playButton->boundingRect().width()/2;
    int Jouer_Posy = 250;
    playButton->setPos(Jouer_Posx,Jouer_Posy);
   // QObject::connect(playButton, SIGNAL(clicked()), this, SLOT(start()));
    scene-> addItem(playButton);


    //bouton quitter
    Menu *quitButton = new Menu(QString("QUIT"));
    int Quitter_Posx = this->width()/2 - quitButton->boundingRect().width()/2;
    int Quitter_Posy = 350;
    quitButton->setPos(Quitter_Posx,Quitter_Posy);
    //connect(quitButton, SIGNAL(clicked()), this, SLOT(quit())) ;
    scene-> addItem(quitButton);

    scene->removeItem(player);
    delete player;

}


void Game::displayGOMenu()

{
    //scene-> clear();

    //son qd il y a le game over
    QMediaPlayer * son= new QMediaPlayer();
    son->setMedia(QUrl("qrc:/sons/game_over.mp3"));
    son->play();
    show();


    //image de fond qd il y a le game over
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1200,900);
    setScene(scene);
    setFixedSize(1200, 900);

    setBackgroundBrush(QBrush(QImage(":/image/NY.jpg")));

    //titre du menu
    QGraphicsTextItem *titleText =new QGraphicsTextItem (QString("GAME OVER"));
    QFont titleFont("arial", 90);
    titleText->setDefaultTextColor("orange");
    titleText->setFont(titleFont);
    scene->addItem(titleText);

    int Posx = this->width()/2 - titleText->boundingRect().width()/2;
    int Posy = 150;
    titleText->setPos(Posx, Posy);


    //bouton rejouer
    Menu *playButton = new Menu(QString("RE-PLAY"));
    int Jouer_Posx = this->width()/2 - playButton->boundingRect().width()/2;
    int Jouer_Posy = 250;
    playButton->setPos(Jouer_Posx,Jouer_Posy);
    //connect(playButton, SIGNAL(clicked()), this, SLOT(start()));
    scene-> addItem(playButton);


    //bouton quitter
    Menu *quitButton = new Menu(QString("QUIT"));
    int Quitter_Posx = this->width()/2 - quitButton->boundingRect().width()/2;
    int Quitter_Posy = 350;
    quitButton->setPos(Quitter_Posx,Quitter_Posy);
    connect(quitButton, SIGNAL(clicked()), this, SLOT(quit())) ;
    scene-> addItem(quitButton);

    scene->removeItem(player);
    delete player;

    //scene->removeItem(enemy);
    //delete enemy;

}


void Game::start()
{
    game->show();

}


void Game::quit()
{
    qApp->quit();
}





