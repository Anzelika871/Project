#pragma once
#include "Board.h"
enum Difficulty {
    EASY = 1,   
    MEDIUM = 2, 
    HARD = 3
};
struct Move {
    int row;
    int col;
};
class AI {
public:
    Move getMove(Board& board, char aiSymbol, char playerSymbol, Difficulty level);
private:
    Move getRandomMove(Board& board);
    Move findBestMove(Board& board, char aiSymbol, char playerSymbol);
    int minimax(Board& board, int depth, bool isMax, char aiSymbol, char playerSymbol);
};