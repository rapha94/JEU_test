#include <QApplication>

#include"Game.h"

#include "Control.h"


Game *game;
Control *control;



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    control->start();

    // une fois que les boutons fonctionnenent, utiliser:
    //control->afficheMainMenu();


    return a.exec();

}

