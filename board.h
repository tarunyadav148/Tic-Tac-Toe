#ifndef BOARD_H
#define BOARD_H

#define N 3

enum TileStatus{Empty, Player1 , Player2 };

class Board
{
private:
    int matrix[N][N];
public:
   void updateBoard(int row,int col);
   TileStatus checktileStatus(int row,int col);
};

#endif