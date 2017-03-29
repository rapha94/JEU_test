#include "Score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent)
{
    score = 0;
}

void Score::increase()
{
    score++;
}

QString Score::getScore()
{
    return QString::number(score);
}




