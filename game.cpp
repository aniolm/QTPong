#include "game.h"

Game::Game()
{
    // create a game scene
    QGraphicsScene * gameScene = new QGraphicsScene();
    gameScene->setSceneRect(0,0,BOARD_WIDTH,BOARD_HEIGHT);
    gameScene->setBackgroundBrush(Qt::black);

    QGraphicsLineItem * pitchLine = new QGraphicsLineItem(BOARD_WIDTH/2, 0 , BOARD_WIDTH/2, BOARD_HEIGHT);
    pitchLine->setPen(QPen(Qt::white, 2, Qt::DashLine));

    //create game objects
    Paddle * paddle1 = new Paddle(PADDLE_WIDTH, PADDLE_HEIGHT);
    paddle1->setPos(5, (BOARD_HEIGHT / 2.0) - (paddle1->getHeight()/2));

    paddle1->setFlag(QGraphicsItem::ItemIsFocusable);
    paddle1->setFocus();

    Paddle * paddle2 = new Paddle(PADDLE_WIDTH, PADDLE_HEIGHT);
    paddle2->setPos(BOARD_WIDTH - paddle2->getWidth() - 5, (BOARD_HEIGHT / 2) - (paddle2->getHeight()/2));

    Ball * ball = new Ball(BALL_WIDTH, BALL_HEIGHT);
    ball->setPaddles(paddle1, paddle2);
    //ball->setPos(paddle1->x() + ball->getWidth(), paddle1->y() + paddle1->getHeight() / 2);
    ball->setPos( BOARD_WIDTH / 2 , BOARD_HEIGHT / 2);

    Score * score1 = new Score(paddle1);
    score1->setPos(BOARD_WIDTH/2-75,50);
    Score * score2 = new Score(paddle2);
    score2->setPos(BOARD_WIDTH/2+50,50);

    //add game objects to the scene
    gameScene->addItem(pitchLine);
    gameScene->addItem(paddle1);
    gameScene->addItem(paddle2);
    gameScene->addItem(ball);
    gameScene->addItem(score1);
    gameScene->addItem(score2);

    //set-up game view

    setScene(gameScene);
    setFixedSize(BOARD_WIDTH,BOARD_HEIGHT);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}
