#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include "board.h"
#include "player.h"

enum GameResult { Tie , Player1 , Player2 };
enum GameStatus { NotFinished , Finished};

class tictactoe{
private:
    void Move(int row,int col);
    int countOfMovePlayed;
    GameStatus gameStatus;
    GameResult gameResult;
public:
    Board board;
    Player player1,player2;
    GameStatus Status();
    GameResult Result();
};

#endif