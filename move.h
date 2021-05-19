#ifndef MOVE_H
#define MOVE_H

class Move{
private:
    int row;
    int col;
public:
    void getMove(int row,int col);
    bool isValidMove();
};

#endif