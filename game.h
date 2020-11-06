#ifndef GAME_H
#define GAME_H
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QGraphicsLineItem>
#include "config.h"
#include "paddle.h"
#include "ball.h"
#include "score.h"

class Game: public QGraphicsView{

public:
    Game();
};

#endif // GAME_H
