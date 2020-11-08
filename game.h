#ifndef GAME_H
#define GAME_H
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QGraphicsLineItem>
#include <QFontDatabase>
#include "button.h"
#include <QGraphicsTextItem>
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

private:
    QGraphicsScene * gameScene;
};

#endif // GAME_H
