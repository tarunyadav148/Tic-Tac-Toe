#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include "board.h"
#include "player.h"

//namespaces are used in enum to
//resolve naming conflicts

//enum for result of game
namespace GameResult{
enum GameResult { Tie , Player1 , Player2 };
}


//enum for status of game
namespace GameStatus{
enum GameStatus { NotFinished , Finished};
}


class TicTacToe{

private:

    //Count of successfully played move
    int countOfMovePlayed;

    //Status of game
    GameStatus::GameStatus gameStatus;

    //Result of game
    GameResult::GameResult gameResult;

public:

    //Set intial values
    TicTacToe();

    //Board of game
    Board board;

    //Players of game
    Player player1,player2;

    //Check validity of move
    bool isValidMove(int row,int col);

    //Play a move
    bool playMove(int row,int col);

    //Returns status of game
    GameStatus::GameStatus Status();

    //Returns result of game
    GameResult::GameResult Result();

};

#endif