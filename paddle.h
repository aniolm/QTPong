#ifndef PADDLE_H
#define PADDLE_H

#include <QGraphicsRectItem>


class Paddle : public QGraphicsRectItem
{
public:
    Paddle(int width, int height);
    void keyPressEvent(QKeyEvent * event);
    int getHeight() const;
    int getWidth() const;
    int getScore() const;
    void increaseScore();

private:
    int score;
    int HEIGHT;
    int WIDTH;
};

#endif // PADDLE_H
