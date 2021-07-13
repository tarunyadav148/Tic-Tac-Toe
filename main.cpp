#include<iostream>
#include<limits>
#include "tictactoe.h"
#include "ui.h"

void play(TicTacToe &ttt,UI &ui);
std::pair<int,int> getRowAndCol(int i);

int main()
{
    TicTacToe ttt;
    UI ui;

    ui.displayMenu();

    Menu choice = ui.getChoice();

    switch(choice)
    {
    case Exit:
        exit(EXIT_SUCCESS);
        break;
    case PlayGame:
        play(ttt,ui);
        break;
    default:
        std::cout<<"Not a valid choice";
        break;
    }

    getchar();
    
}

std::pair<int,int> getRowAndCol(int move)
{
    switch (move)
    {
    case 1:
        return std::pair<int,int>(0,0);
        break;
    case 2:
        return std::pair<int,int>(0,1);
        break;
    case 3:
        return std::pair<int,int>(0,2);
        break;
    case 4:
        return std::pair<int,int>(1,0);
        break;
    case 5:
        return std::pair<int,int>(1,1);
        break;
    case 6:
        return std::pair<int,int>(1,2);
        break;
    case 7:
        return std::pair<int,int>(2,0);
        break;
    case 8:
        return std::pair<int,int>(2,1);
        break;
    case 9:
        return std::pair<int,int>(2,2);
        break; 
       
    }
    throw "invalid move";
}

void play(TicTacToe &ttt,UI &ui)
{
    int move;
    int row,col;
    std::pair<int,int> pairMove;

    std::string name;
    std::cout<<"Enter name of player 1:";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    getline(std::cin,name);
    ttt.player1.setName(name);
    std::cout<<"Enter name of player 2:";
    getline(std::cin,name);
    ttt.player2.setName(name);

    system("clear");

    for(int i=0;i<9;i++)
    {
        if(i==0)
            ui.displayCurrentBoard(ttt.board);

        if(ttt.Status()==GameStatus::GameStatus::NotFinished)
        {
            if(i%2==0)
            {
                std::cout<<"\n"<<ttt.player1.getName()
                    <<" enter move [1-9]:";
            }
            else
            {
                std::cout<<"\n"<<ttt.player2.getName()
                    <<" enter move [1-9]:";
            }
            std::cin>>move;
            pairMove = getRowAndCol(move);
            row = pairMove.first;
            col = pairMove.second;
            while(!ttt.playMove(row,col))
            {
                std::cout<<"Enter a valid move:";
                std::cin>>move;
                pairMove = getRowAndCol(move);
                row = pairMove.first;
                col = pairMove.second;
            }
        }
        

        system("clear");
        ui.displayCurrentBoard(ttt.board);
        if(ttt.Status()==GameStatus::GameStatus::Finished)
            break;
    }

    if(ttt.Result()==GameResult::GameResult::Player1)
    {
        std::cout<<ttt.player1.getName()
                <<" win the game"<<std::endl;
    }
    else if(ttt.Result()==GameResult::GameResult::Player2)
    {
        std::cout<<ttt.player2.getName()
                <<" win the game"<<std::endl;
    }
    else
    {
        std::cout<<"Game Tie"<<std::endl;
    }
}