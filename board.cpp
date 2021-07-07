#include "board.h"

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

void Board::updateBoard(int row,int col,Players::Players player)
{
    matrix[row][col] = player;
}

TileStatus::TileStatus Board::checktileStatus(int row,int col)
{
    return (TileStatus::TileStatus)matrix[row][col];
}