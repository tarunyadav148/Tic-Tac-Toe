#include "tictactoe.h"

TicTacToe::TicTacToe()
{
    countOfMovePlayed = 0;
    gameStatus = GameStatus::GameStatus::NotFinished;
    gameResult = GameResult::GameResult::Tie;
}

bool TicTacToe::isValidMove(int row,int col)
{
    return (
    gameStatus==GameStatus::GameStatus::NotFinished
    &&board.checktileStatus(row,col)==TileStatus::TileStatus::Empty
    &&(row>=0&&row<=2)
    &&(col>=0&&col<=2)
    );
}

bool TicTacToe::playMove(int row,int col)
{
    if(isValidMove(row,col))
    {
        Players::Players player;
        countOfMovePlayed++;

        if(countOfMovePlayed%2!=0)
        {
            player = Players::Players::Player1;
            if(player1.updateWinparameter(row,col))
            {
                gameStatus = GameStatus::GameStatus::Finished;
                gameResult = GameResult::GameResult::Player1;
            }
        }
        else
        {
            player = Players::Players::Player2;
            if(player2.updateWinparameter(row,col))
            {
                gameStatus = GameStatus::GameStatus::Finished;
                gameResult = GameResult::GameResult::Player2;
            }
        }
        
        if(countOfMovePlayed==N*N&&gameStatus==GameStatus::GameStatus::NotFinished)
        {
            gameStatus = GameStatus::GameStatus::Finished;
            gameResult = GameResult::GameResult::Tie;
        }

        board.updateBoard(row,col,player);

        return true;
    }
    return false;
}

GameStatus::GameStatus TicTacToe::Status()
{
    return gameStatus;
}

GameResult::GameResult TicTacToe::Result()
{
    return gameResult;
}