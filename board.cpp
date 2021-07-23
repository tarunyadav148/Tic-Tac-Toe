#include<iostream>
#include "board.h"


//Setting all values 0 initially of board
Board::Board()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            matrix[i][j] = 0;
        }
    }
}



//Update board value for a move
//@input : Oject of Players enum {Player1=1,Player2=2}
void Board::updateBoard(int row,int col,Players::Players player)
{
    matrix[row][col] = (int)player;
}



//Return status of a title on board
//@input : row and column in board
//@output : TitleStatus enum {Empty=0,Player1=1,Player2=2}
TileStatus::TileStatus Board::checktileStatus(int row,int col)
{
    return (TileStatus::TileStatus)matrix[row][col];
}