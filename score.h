#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsTextItem>
#include <QObject>
#include <QFont>
#include "paddle.h"

using std::string;


class Score :  public QGraphicsTextItem
{
    Q_OBJECT

public:
    Score(Paddle * paddle);


public slots:
    void updateScore(int score);

private:
    int score2;

};

#endif // SCORE_H
