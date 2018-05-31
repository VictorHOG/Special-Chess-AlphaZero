#include "game.h"
#include "button.h"
#include <QPixmap>
#include <QDebug>

Game::Game(QWidget *parent ):QGraphicsView(parent) {

    //Making the Scene
    gameScene = new QGraphicsScene();
    gameScene->setSceneRect(0,0,1024,768);

    //Making the view
    setFixedSize(1024,768);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(gameScene);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::white);
    setBackgroundBrush(brush);
    pieceToMove = NULL;

    //display turn
    turnDisplay = new QGraphicsTextItem();
    turnDisplay->setPos(width()/2-100,10);
    turnDisplay->setZValue(1);
    turnDisplay->setDefaultTextColor(Qt::white);
    turnDisplay->setFont(QFont("",18));
    turnDisplay->setPlainText("Turn : WHITE");
    setTurn("WHITE");

}

void Game::drawChessBoard()
{
    chess = new ChessBoard();
//    drawDeadHolder(0,0,Qt::lightGray);
 //   drawDeadHolder(1100,0,Qt::lightGray);
     chess->drawBoxes(0,50);

}


/*
void Game::displayDeadWhite()
{
    int SHIFT = 50;
    int j = 0;
    int k = 0;
    for(size_t i = 0,n = whiteDead.size(); i<n; i++) {
            if(j == 4){
                k++;
                j = 0;
            }
            whiteDead[i]->setPos(40+SHIFT*j++,100+SHIFT*2*k);
    }
}

void Game::displayDeadBlack()
{
    int SHIFT = 50;
    int j = 0;
    int k = 0;
    for(size_t i = 0,n = blackDead.size(); i<n; i++) {
        if(j == 4){
            k++;
            j = 0;
        }
        blackDead[i]->setPos(1140+SHIFT*j++,100+SHIFT*2*k);
    }
}
*/


void Game::addToScene(QGraphicsItem *item) {

    gameScene->addItem(item);
}

void Game::removeFromScene(QGraphicsItem *item) {

    gameScene->removeItem(item);
}

QString Game::getTurn() {

    return turn;
}

void Game::setTurn(QString value) {
    turn = value;
}

void Game::changeTurn() {
    if(getTurn() == "WHITE")
        setTurn("BLACK");
    else
        setTurn("WHITE");
    turnDisplay->setPlainText("Turn : " + getTurn());
}

void Game::start() {

    drawChessBoard();

    for(size_t i =0, n = listG.size(); i < n; i++)
        removeFromScene(listG[i]);

    addToScene(turnDisplay);
    addToScene(check);
 //   chess->addChessPiece();
}

void Game::drawDeadHolder(int x, int y,QColor color) {

    deadHolder = new QGraphicsRectItem(x,y,300,900);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    deadHolder->setBrush(brush);
    addToScene(deadHolder);
}



void Game::displayMainMenu() {

    QGraphicsPixmapItem *p = new QGraphicsPixmapItem();
    p->setPixmap(QPixmap(":/images/a.jpg"));
    p->setPos(0,0);
    addToScene(p);
    listG.append(p);

    //Create the title
    QGraphicsTextItem *titleText = new QGraphicsTextItem("AlphaZero");
 //   titleFont->setDefaultTextColor();
    QFont titleFont("arial" , 50);
    titleText->setFont( titleFont);
    int xPos = width()/2 - titleText->boundingRect().width()/2;
    int yPos = 150;
    titleText->setPos(xPos,yPos);
    addToScene(titleText);
    listG.append(titleText);

    //Create Button
    Button * playButton = new Button("Play");
    int pxPos = width()/2 - playButton->boundingRect().width()/2;
    int pyPos = 300;
    playButton->setPos(pxPos,pyPos);
    connect(playButton,SIGNAL(clicked()) , this , SLOT(start()));
    addToScene(playButton);
    listG.append(playButton);

    //Create Quit Button
    Button * quitButton = new Button("Quit");
    int qxPos = width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 375;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton, SIGNAL(clicked()),this,SLOT(close()));
    addToScene(quitButton);
 //   drawChessBoard();
    listG.append(quitButton);
}

