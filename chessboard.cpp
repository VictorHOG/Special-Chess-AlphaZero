#include "chessboard.h"
#include "chessbox.h"
#include "game.h"
#include "knight.h"

extern Game *game;

ChessBoard::ChessBoard() {
 //   setUpBlack();
 //   setUpWhite();
}
void ChessBoard::drawBoxes(int x,int y)
{
    int SHIFT = 100;
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++)
        {
            ChessBox *box = new ChessBox();
            game->collection[i][j] = box;
            box->rowLoc = i;
            box->colLoc = j;
            box->setPos(x+SHIFT*j,y+SHIFT*i);
            if((i+j)%2==0)
                box->setOriginalColor(Qt::lightGray);
            else
                box->setOriginalColor(Qt::darkGray);
            game->addToScene(box);



        }
    }

}


void ChessBoard::addChessPiece() {

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++)
        {

            ChessBox *box =game->collection[i][j];
            if(i < 2) {
                static int k;
                box->placePiece(black[k]);
                game->alivePiece.append(black[k]);
                game->addToScene(black[k++]);
            }
            if(i > 5) {

                static int h;
                box->placePiece(white[h]);
                game->alivePiece.append(white[h]);

                  game->addToScene(white[h++]);
            }

        }
    }


}

void ChessBoard::setUpWhite() {

    ChessPiece *piece;

    piece = new Knight("WHITE");
    white.append(piece);
}

void ChessBoard::setUpBlack() {

    ChessPiece *piece;

    piece = new Knight("BLACK");
    black.append(piece);
}

/*
void ChessBoard::reset() {
    int k = 0; int h = 0;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++)
        {

            ChessBox *box =game->collection[i][j];
            box->setHasChessPiece(false);
            box->setChessPieceColor("NONE");
            box->currentPiece = NULL;
            if(i < 2) {

                box->placePiece(black[k]);
                black[k]->setIsPlaced(true);
                black[k]->firstMove = true;
                game->alivePiece.append(black[k++]);

            }
            if(i > 5) {

                box->placePiece(white[h]);
                white[h]->setIsPlaced(true);
                white[h]->firstMove = true;
                game->alivePiece.append(white[h++]);

            }

        }
    }
}*/
