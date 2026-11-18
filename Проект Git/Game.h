#pragma once
#include "Board.h"
#include "AI.h"
#include <iostream>
class Game {
private:
    Board board;
    AI ai;
    struct Score {
        int player = 0;
        int ai = 0;
        int draws = 0;
    } score;
    const char PLAYER_SYMBOL = 'X';
    const char AI_SYMBOL = 'O';
    void printMenu();
    Difficulty chooseDifficulty();
    bool chooseWhoStarts();
    void playerMove();
    void aiMove(Difficulty level);
    void printScore();
    bool askPlayAgain();
public:
    Game();
    void run();
};