#include "score.h"


Score::Score(Paddle * paddle)
{
    setDefaultTextColor(Qt::white);
    setPlainText("0");
    connect(paddle ,SIGNAL(scoreIncreased(int)),this,SLOT(updateScore(int)));

    QFont * font = new QFont;
    font->setPointSize(20);
    font->setFamily("LCD Solid");
    this->setFont(*font);

}


void Score::updateScore(int score)
{
    setPlainText(QString::number(score));
    return ;
}

