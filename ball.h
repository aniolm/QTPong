#ifndef BALL_H
#define BALL_H

#include <QGraphicsRectItem>
#include <QObject>
#include "paddle.h"

class Ball : public QObject, public QGraphicsRectItem
{
    Q_OBJECT

public:
    Ball(int width, int height);
    void setPaddles(Paddle *player1, Paddle *player2);
    void setScores(Paddle *score1, Paddle *score2);
    int getHeight() const;
    int getWidth() const;


public slots:
   void move();

private:

   Paddle *paddle1;
   Paddle *paddle2;
   int WIDTH = 10;
   int HEIGHT = 10;
   qreal dx, dy, speed;
};

#endif // BALL_H
