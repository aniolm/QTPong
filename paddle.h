#ifndef PADDLE_H
#define PADDLE_H

#include <QGraphicsRectItem>
#include <QObject>

class Paddle :public QObject, public QGraphicsRectItem
{
    Q_OBJECT

public:
    Paddle(int width, int height);
    void keyPressEvent(QKeyEvent * event);
    int getHeight() const;
    int getWidth() const;
    int getScore() const;
    void increaseScore();

signals:
    void scoreIncreased(int score);
    void gameOver();

private:
    int score;
    int HEIGHT;
    int WIDTH;
};

#endif // PADDLE_H
