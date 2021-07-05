#ifndef PLAYER_H
#define PLAYER_H

#include<string>

#define N 3

class Player{
private:
    std::string name; 
    int rows[N];       
    int cols[N];       
    int diags[N-1];    
    void updateWinparameter(int row,int col); 
public:
    void setName();  
    void getName();  
    bool playMove(int row,int col); 
};

#endif