#ifndef UI_H
#define UI_H

#include "board.h";

enum Choice { PlayGame };

class UI{
private:
    Choice currChoice;
public:
    void displayMenu();
    void getChoice();
    void playNextMove(Player player);
    void displayCurrentBoard(Board &board);
};

#endif