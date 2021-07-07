#ifndef UI_H
#define UI_H

#include "board.h"

enum Menu{ Exit,PlayGame };

class UI{
public:
    void displayMenu();
    Menu getChoice();
    void displayCurrentBoard(Board &board);
};

#endif