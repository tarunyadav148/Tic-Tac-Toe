#include<iostream>
#include<limits>
#include "tictactoe.h"
#include "ui.h"

//Play Game
//@take a tic tac toe and ui oject as input
void play(TicTacToe &ttt,UI &ui);

//input move from player
void getMove(int& row,int& col);

//Get a pair containing row and col of board of a move
std::pair<int,int> getRowAndCol(int i);

//Input name of players
void setPlayersNames(TicTacToe &ttt);

int main()
{
    TicTacToe ttt;
    UI ui;

    ui.displayMenu();

    GetValidMenuChocie:
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
            std::cout<<"Not a valid choice enter again";
            goto GetValidMenuChocie;
            break;
    }

    getchar();
    
}



//Get a pair containing row and col of board of a move
std::pair<int,int> getRowAndCol(int move)
{
    switch (move)
    {
        case 1:return std::pair<int,int>(0,0);
        case 2:return std::pair<int,int>(0,1);
        case 3:return std::pair<int,int>(0,2);
        case 4:return std::pair<int,int>(1,0);
        case 5:return std::pair<int,int>(1,1);
        case 6:return std::pair<int,int>(1,2);
        case 7:return std::pair<int,int>(2,0);
        case 8:return std::pair<int,int>(2,1);
        case 9:return std::pair<int,int>(2,2);
    }
    throw "invalid move";
}



//Input name of players
void setPlayersNames(TicTacToe &ttt)
{
    std::string name;

    std::cout<<"Enter name of player 1:";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    getline(std::cin,name);
    ttt.player1.setName(name);

    std::cout<<"Enter name of player 2:";
    getline(std::cin,name);
    ttt.player2.setName(name);
}



//input move from player
void getMove(int& row,int& col)
{
    int move;
    std::pair<int,int> MovePair;

    std::cin>>move;
    while(!std::cin.good()) //checking validity of move
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout<<"Please enter a intger only[1-9]:";
        std::cin>>move;
    }

    try
    {
        MovePair = getRowAndCol(move);
        row = MovePair.first;
        col = MovePair.second;
    }catch(const char* e)
    {
        std::cout<<e<<std::endl;
        std::cout<<"Enter again [1-9]:";
        getMove(row,col);
    }
    
}



//playing the game
void play(TicTacToe &ttt,UI &ui)
{ 
    int row,col;

    setPlayersNames(ttt);

    system("clear");

    int moveCounter = 0;
    while(ttt.Status()==GameStatus::GameStatus::NotFinished)
    {
        if(moveCounter==0) ui.displayCurrentBoard(ttt.board);

        if(moveCounter%2==0)
        {
            std::cout<<"\n"<<ttt.player1.getName()
                <<" Enter a move [1-9]:";
        }

        if(moveCounter%2!=0)
        {
            std::cout<<"\n"<<ttt.player2.getName()
                    <<" Enter a move [1-9]:";
        }

        getMove(row,col);

        while(!ttt.playMove(row,col))
        {
            std::cout<<"Please enter a valid move:";
            getMove(row,col);
        }

        system("clear");
        ui.displayCurrentBoard(ttt.board);
        moveCounter++;
    }

    if(ttt.Result()==GameResult::GameResult::Player1)
    {
        std::cout<<ttt.player1.getName()
                <<" win the game"<<std::endl;
    }

    if(ttt.Result()==GameResult::GameResult::Player2)
    {
        std::cout<<ttt.player2.getName()
                <<" win the game"<<std::endl;
    }

    if(ttt.Result()==GameResult::GameResult::Tie)
    {
        std::cout<<"Game Tie"<<std::endl;
    }
}