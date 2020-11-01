#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "paddle.h"
#include "ball.h"
#include <QGraphicsView>

#define PADDLE_WIDTH 5
#define PADDLE_HEIGHT 100

#define BOARD_WIDTH 800
#define BOARD_HEIGHT 600

#define BALL_WIDTH 10
#define BALL_HEIGHT 10

//#define BALL_SPEED 20
//#define BALL_X_INCREMENT 10
//#define BALL_Y_INCREMENT 10

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // create a game scene
    QGraphicsScene * gameScene = new QGraphicsScene();
    gameScene->setSceneRect(0,0,BOARD_WIDTH,BOARD_HEIGHT);

    //create game objects
    Paddle * paddle1 = new Paddle(PADDLE_WIDTH, PADDLE_HEIGHT);
    paddle1->setPos(5, (BOARD_HEIGHT / 2.0) - paddle1->getHeight());

    paddle1->setFlag(QGraphicsItem::ItemIsFocusable);
    paddle1->setFocus();

    Paddle * paddle2 = new Paddle(PADDLE_WIDTH, PADDLE_HEIGHT);
    paddle2->setPos(BOARD_WIDTH - paddle2->getWidth() - 5, (BOARD_HEIGHT / 2) - paddle2->getHeight());

    Ball * ball = new Ball(BALL_WIDTH, BALL_HEIGHT);
    ball->setPaddles(paddle1, paddle2);
    ball->setPos(paddle1->x() + ball->getWidth(), paddle1->y() + paddle1->getHeight() / 2);


    //add game objects to the scene
    gameScene->addItem(paddle1);
    gameScene->addItem(paddle2);
    gameScene->addItem(ball);


    //create game view
    QGraphicsView * gameView = new QGraphicsView(gameScene);

    gameView->show();
    gameView->setFixedSize(800,600);
    gameView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    gameView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);



    return a.exec();
}
