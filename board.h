#ifndef BOARD_H
#define BOARD_H

#define N 3

namespace TileStatus{
enum TileStatus{Empty, Player1 , Player2 };
}
namespace Players{
enum Players{ Player1=1,  Player2=2 };
}


class Board
{
private:
    int matrix[N][N];
public:
    Board();
    void updateBoard(int row,int col,Players::Players player);
    TileStatus::TileStatus checktileStatus(int row,int col);
};

#endif