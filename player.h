#ifndef PLAYER_H
#define PLAYER_H

#include<string>

enum GamePlayer { Player1 , Player2};

class Player{
private:
    std::string name;
    GamePlayer gamePlayer;
public:
    void setInfo();
    void getName();
    void getGamePlayer();
};

#endif