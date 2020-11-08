#ifndef GAME_H
#define GAME_H
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QGraphicsLineItem>
#include <QFontDatabase>
#include <QGraphicsTextItem>
#include <QTimer>
#include <QDebug>
#include <cstdlib>
#include "button.h"
#include "config.h"
#include "paddle.h"
#include "ball.h"
#include "score.h"

class Game: public QGraphicsView{

    Q_OBJECT

public:
    Game();
    void displayInstructions();

public slots:
    void start();
    void moveComputerPaddle();

private:
    QGraphicsScene * gameScene;
    Paddle * paddle1;
    Paddle * paddle2;
    Ball * ball;
};

#endif // GAME_H
