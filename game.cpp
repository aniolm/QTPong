#include "game.h"

Game::Game()
{

    //add custom font to application
    QFontDatabase::addApplicationFont(":/fonts/LcdSolid-VPzB.ttf");

    // create a game scene
    gameScene = new QGraphicsScene();
    gameScene->setSceneRect(0,0,BOARD_WIDTH,BOARD_HEIGHT);
    gameScene->setBackgroundBrush(Qt::black);



    //set-up game view

    setScene(gameScene);
    setFixedSize(BOARD_WIDTH,BOARD_HEIGHT);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void Game::displayInstructions(){
    // create the title text
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("QT PONG"));
    titleText->setDefaultTextColor(Qt::white);
    QFont titleFont("LCD Solid",50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    gameScene->addItem(titleText);

    QGraphicsTextItem* instructionText = new QGraphicsTextItem(QString("Use UP and DOWN keys to move your paddle."));
    instructionText->setDefaultTextColor(Qt::white);
    QFont instFont("LCD Solid",15);
    instructionText->setFont(instFont);
    int instxPos = this->width()/2 - instructionText->boundingRect().width()/2;
    int instyPos = 250 ;
    instructionText->setPos(instxPos,instyPos);
    gameScene->addItem(instructionText);


    // create the play button
    Button* playButton = new Button(QString("PLAY"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 350;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    gameScene->addItem(playButton);

    // create the quit button
    Button* quitButton = new Button(QString("QUIT"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 425;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    gameScene->addItem(quitButton);
}

void Game::start(){
    // clear the screen
    gameScene->clear();
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

}
