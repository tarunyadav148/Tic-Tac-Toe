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
public:
    Player();
    void setName(std::string name);  
    bool updateWinparameter(int row,int col); 
    std::string getName();  
};

#endif