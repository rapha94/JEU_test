#include <QApplication>

#include"Game.h"


Game * game;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game();
    game->start();
   // game->displayMainMenu();


    return a.exec();

}

