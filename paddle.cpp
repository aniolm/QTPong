#include "paddle.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <ball.h>

Paddle::Paddle(int width, int height) : score(0), HEIGHT(height), WIDTH(width)
{
   setRect(0, 0, WIDTH, HEIGHT);
   setBrush((QBrush)Qt::white);
}

int Paddle::getWidth() const
{
    return WIDTH;
}

int Paddle::getHeight() const
{
    return HEIGHT;
}

int Paddle::getScore() const
{
    return score;
}


void Paddle::keyPressEvent(QKeyEvent *event)
{
   if (event->key() == Qt::Key_Up)
   {
       if(y()>0)
       setPos(x(),y()-10);
   }
   else if (event->key() == Qt::Key_Down)
   {
       if(y()<500)
       setPos(x(),y()+10);
    }
}

void Paddle::increaseScore()
{
    ++score;
    emit scoreIncreased(score);
    return ;
}
