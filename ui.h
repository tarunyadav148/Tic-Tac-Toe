#ifndef UI_H
#define UI_H

#include "board.h"


//enum of menu choice
enum Menu{ Exit,PlayGame };

class UI{
public:

    //Display menu
    void displayMenu();

    //Get menu choice
    Menu getChoice();

    //Diplay current board
    void displayCurrentBoard(Board &board);
};

#endif