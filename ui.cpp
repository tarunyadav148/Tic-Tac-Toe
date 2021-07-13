#include<iostream>
#include<limits>
#include "ui.h"
#include "board.h"

void UI::displayMenu()
{
    std::cout<<"\t\t\tTic-Tac-Toe"<<std::endl;
    std::cout<<"Enter 0 for exit"<<std::endl;
    std::cout<<"Enter 1 for play"<<std::endl;
}

Menu UI::getChoice()
{
    int choice;
    std::cout<<"Enter your choice:";
    std::cin>>choice;
    while(!std::cin.good())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout<<"Please enter a intger only:";
        std::cin>>choice;
    }
    return (Menu)choice;
}

void UI::displayCurrentBoard(Board &board)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(board.checktileStatus(i,j)==TileStatus::TileStatus::Player1)
            {
                std::cout<<" O |";
            }
            else if(board.checktileStatus(i,j)==TileStatus::TileStatus::Player2)
            {
                std::cout<<" X |";
            }
            else
            {
                std::cout<<"   |";
            }
        }
        std::cout<<std::endl;
    }
}