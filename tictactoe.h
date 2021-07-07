#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include "board.h"
#include "player.h"

namespace GameResult{
enum GameResult { Tie , Player1 , Player2 };
}
namespace GameStatus{
enum GameStatus { NotFinished , Finished};
}


class TicTacToe{
private:
    int countOfMovePlayed;
    GameStatus::GameStatus gameStatus;
    GameResult::GameResult gameResult;
public:
    TicTacToe();
    Board board;
    Player player1,player2;
    bool isValidMove(int row,int col);
    bool playMove(int row,int col);
    GameStatus::GameStatus Status();
    GameResult::GameResult Result();
};

#endif