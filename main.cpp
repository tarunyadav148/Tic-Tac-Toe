#include<iostream>
#include "tictactoe.h"
#include "ui.h"

void play(TicTacToe &ttt,UI &ui);

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

void play(TicTacToe &ttt,UI &ui)
{
    int row,col;

    std::string name;
    std::cout<<"Enter name of player 1:";
    std::cin>>name;
    ttt.player1.setName(name);
    std::cout<<"Enter name of player 2:";
    std::cin>>name;
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
                    <<" enter row and col of move:";
                std::cin>>row>>col;
                ttt.playMove(row,col);
            }
            else
            {
                std::cout<<"\n"<<ttt.player2.getName()
                    <<" enter row and col of move:";
                std::cin>>row>>col;
                ttt.playMove(row,col);
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