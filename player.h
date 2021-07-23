#ifndef PLAYER_H
#define PLAYER_H

#include<string>

#define N 3     //for baord dimensions

class Player{

private:

    //Name of player
    std::string name; 

    //Win parameters
    /*
        If in any row , column or diagonal if all titles
        belong to a player then player wins the game.
        So, count of moved played by player in any
        row , column or diagonal to check whether player
        wins or not.

    */
    int rows[N];       
    int cols[N];       
    int diags[N-1]; 

public:

    //Set intial values
    Player();

    //Update win parameter of a player
    void setName(std::string name);  

    //Set name of Player
    bool updateWinparameter(int row,int col); 

    //Return name of player
    std::string getName();  

};

#endif