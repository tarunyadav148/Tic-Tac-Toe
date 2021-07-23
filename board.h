#ifndef BOARD_H
#define BOARD_H

#define N 3    //for baord dimensions


//namespaces are used in enum to
//resolve naming conflicts

//enum for status of a tile in board
namespace TileStatus{
enum TileStatus{Empty, Player1 , Player2 };
}


//enum for status of a player used to update board
namespace Players{
enum Players{ Player1=1,  Player2=2 };
}



class Board
{

private:
    int matrix[N][N];  //3X3 board

public:

    //Setting all values 0 initially of board
    Board();

    //Update board value for a move
    void updateBoard(int row,int col,Players::Players player);

    //Return status of a title on board
    TileStatus::TileStatus checktileStatus(int row,int col);

};

#endif