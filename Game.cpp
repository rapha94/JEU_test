#include <QTimer>
#include <QFont>
#include <QGraphicsItem>
#include <QMediaPlayer>
#include <QGraphicsPixmapItem>
#include <QImage>
#include <QGraphicsRectItem>
#include <QApplication>
#include <QObject>
#include <QGraphicsTextItem>

#include <QDebug>

#include "Enemy.h"
#include "Menu.h"
#include "Game.h"
#include "Player.h"
#include "Control.h"
#include "Score.h"

extern Game *game;
extern Control *control;

//view


Game::Game(QWidget *parent){

    // création de la scene de jeu
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1200,900);
    setScene(scene);
    setFixedSize(1200, 900);

    setBackgroundBrush(QBrush(QImage(":/image/Image_de_fond.jpg")));


    // création d'un item a mettre dans la scene
    player = new Player();
    player->setPixmap(QPixmap(":/image/singeLOL.gif"));
    player->setPos(400, 500);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    scene->addItem(player);


    //creation du score
    score = new QGraphicsTextItem();
    scene-> addItem(score);
    score->setDefaultTextColor(Qt::blue);
    score->setFont(QFont("times", 16));

    health = new Health();
    health->setPos(health->x(), health->y()+25);
    scene->addItem(health);


    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000);

    show();
}


void Game ::  setScore(const QString &s)
{
         score->setPlainText("Score: " + s);

}


//deplacer dans le controller
void Game::displayMainMenu()

{

    //image de fond
    QGraphicsScene *sceneMM = new QGraphicsScene();
    sceneMM->setSceneRect(0,0,1200,900);
    setScene(sceneMM);
    setFixedSize(1200, 900);

    setBackgroundBrush(QBrush(QImage(":/image/NY.jpg")));

    QGraphicsTextItem *titleText =new QGraphicsTextItem (QString("MENU"));
    QFont titleFont("comics sans", 50);
    titleText->setFont(titleFont);
    sceneMM->addItem(titleText);

    int Posx = this->width()/2 - titleText->boundingRect().width()/2;
    int Posy = 150;
    titleText->setPos(Posx, Posy);

    //bouton jouer
    Menu *playButton = new Menu(QString("PLAY"));
    int Jouer_Posx = this->width()/2 - playButton->boundingRect().width()/2;
    int Jouer_Posy = 250;
    playButton->setPos(Jouer_Posx,Jouer_Posy);
    QObject::connect(playButton, SIGNAL(clicked()), this, SLOT(start()));
    sceneMM-> addItem(playButton);

    //bouton quitter
    Menu *quitButton = new Menu(QString("QUIT"));
    int Quitter_Posx = this->width()/2 - quitButton->boundingRect().width()/2;
    int Quitter_Posy = 350;
    quitButton->setPos(Quitter_Posx,Quitter_Posy);
    QObject::connect(quitButton, SIGNAL(clicked()), this, SLOT(quit())) ;
    sceneMM-> addItem(quitButton);

    scene->removeItem(player);
    delete player;

}



//deplacer dans le controller
void Game::displayGOMenu()

{

    //image de fond qd il y a le game over
    QGraphicsScene * sceneGO = new QGraphicsScene();
    sceneGO->setSceneRect(0,0,1200,900);
    setScene(sceneGO);
    setFixedSize(1200, 900);

    setBackgroundBrush(QBrush(QImage(":/image/NY.jpg")));

    //titre du menu
    QGraphicsTextItem *titleText = new QGraphicsTextItem (QString("GAME OVER"));
    QFont titleFont("arial", 90);
    titleText->setDefaultTextColor("orange");
    titleText->setFont(titleFont);
    sceneGO->addItem(titleText);
    int Posx = this->width()/2 - titleText->boundingRect().width()/2;
    int Posy = 150;
    titleText->setPos(Posx, Posy);



    //Affichage du score
    sceneGO-> addItem(score);
    score->setPos(1100, 20);
    score-> setDefaultTextColor("green");


    //bouton rejouer
    Menu *playButton = new Menu(QString("RE-PLAY"));
    int Jouer_Posx = this->width()/2 - playButton->boundingRect().width()/2;
    int Jouer_Posy = 250;
    playButton->setPos(Jouer_Posx,Jouer_Posy);
    QObject:connect(playButton, SIGNAL(clicked()), this, SLOT(start()));
    sceneGO-> addItem(playButton);


    //bouton quitter
    Menu *quitButton = new Menu(QString("QUIT"));
    int Quitter_Posx = this->width()/2 - quitButton->boundingRect().width()/2;
    int Quitter_Posy = 350;
    quitButton->setPos(Quitter_Posx,Quitter_Posy);
    QObject::connect(quitButton, SIGNAL(clicked()), this, SLOT(quit())) ;
    sceneGO-> addItem(quitButton);


    qDebug()<<"#################";
    scene->removeItem(player);
    delete player;
}



//deplacer dans le controller
void Game::start()
{
    control->start();

}


//deplacer dans le controller
void Game::quit()
{
    control->quitter();
}
