#include "player.h"

Player::Player()
{
    std::string name = "NULL";

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            rows[i] = 0;      
            cols[i] = 0;
            if(i<2)
                diags[i] = 0;  
        }
    }      
}

bool Player::updateWinparameter(int row,int col)
{
    rows[row]++;
    if(rows[row]==N)
        return true;

    cols[col]++;
    if(cols[col]==N)
        return true;
    
    if(row==col)
    {
        diags[0]++;
        if(diags[0]==N)
            return true;
    }

    if(row+col==N-1)
    {
        diags[1]++;
        if(diags[1]==N)
            return true;
    }

    return false;
}

void Player::setName(std::string name)
{
    this->name = name;
} 

std::string Player::getName()
{
    return name;
}
