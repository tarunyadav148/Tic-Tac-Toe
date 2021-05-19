#ifndef BOARD_H
#define BOARD_H

#include "move.h"
#include "player.h"

enum Result { Tie , Player1 , Player2 };
enum Status { NotFinished , Finished};

class Board
{
private:
    int board[3][3];
    Status gameStatus;
    Result gameResult;
    int countOfplayedMove;
public:
   void playMove(Move move, Player currentPlayer);
   void checkStatus();
   void isWinMove();
   friend class UI;
};



#endif