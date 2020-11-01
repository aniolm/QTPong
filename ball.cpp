#include "ball.h"
#include <QTimer>

Ball::Ball(int width, int height) :  WIDTH(width), HEIGHT(height), dx(-20), dy(-20), speed(10)
{
    setRect(0,0,WIDTH,HEIGHT);
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
    if(collidesWithItem(paddle1) || collidesWithItem(paddle2)){

        dx = -dx;
        dy = -(rand() % 2) + 1;
    }
    else if((y()<0)||(y()<800)) {
        dy = -dy;
    }
    else {

    }
    setPos(x() + dx, y() + dy);
    //paddle2->randomMove(y());
}

