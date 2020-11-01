#include "paddle.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <ball.h>

Paddle::Paddle(int width, int height) : HEIGHT(height), WIDTH(width)
{
   setRect(0, 0, WIDTH, HEIGHT);
}

int Paddle::getWidth() const
{
    return WIDTH;
}

int Paddle::getHeight() const
{
    return HEIGHT;
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

