#include "ball.h"
#include <QTimer>
#include <QBrush>
#include <cmath>
#include "config.h"

Ball::Ball(int width, int height) :  WIDTH(width), HEIGHT(height), dx(-1), dy(0), speed(10)
{
    setRect(0,0,WIDTH,HEIGHT);
    setBrush((QBrush)Qt::white);
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);

}

int Ball::getWidth() const
{
    return WIDTH;
}

int Ball::getHeight() const
{
    return HEIGHT;
}


void Ball::setPaddles(Paddle *player1, Paddle *player2)
{
    paddle1 = player1;
    paddle2 = player2;
}

void Ball::move()
{

        // hit right left
        if (collidesWithItem(paddle1)) {
            // set fly direction depending on where it hit the racket
            qreal t = ((y() - paddle1->y()) / paddle1->getHeight()) - 0.5;
            dx = fabs(dx); // force it to be positive
            dy = t;
        }

        // hit right paddle
        else if (collidesWithItem(paddle2)) {
            // set fly direction depending on where it hit the racket
            qreal t = ((y() - paddle2->y()) / paddle2->getHeight()) - 0.5;
            dx = -fabs(dx); // force it to be negative
            dy = t;
        }

        // hit left wall
        else if (x() < 0) {
            paddle2->increaseScore();
            setPos( BOARD_WIDTH / 2 , BOARD_HEIGHT / 2);
            dx = fabs(dx); // force it to be positive
            dy = 0;
        }

        // hit right wall
        else if (x() > BOARD_WIDTH) {
            paddle1->increaseScore();
            setPos( BOARD_WIDTH / 2 , BOARD_HEIGHT / 2);
            dx = -fabs(dx); // force it to be negative
            dy = 0;
        }

        // hit top wall
        else if (y() < 0) {
            dy = fabs(dy); // force it to be positive
        }

        // hit bottom wall
        else if (y() > BOARD_HEIGHT - BALL_HEIGHT) {
            dy = -fabs(dy); // force it to be negative
        }

        setPos(x() + dx*speed, y() + dy*speed);

}

