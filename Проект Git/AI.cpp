#include "AI.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;
Move AI::getMove(Board& board, char aiSymbol, char playerSymbol, Difficulty level) {
    if (level == EASY) {
        return getRandomMove(board);
    }
    if (level == MEDIUM) {
        if (rand() % 2 == 0) {
            return getRandomMove(board);
        }
    }
    return findBestMove(board, aiSymbol, playerSymbol);
}
Move AI::getRandomMove(Board& board) {
    vector<Move> freeCells;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board.grid[i][j] == ' ') {
                freeCells.push_back({ i, j });
            }
        }
    }
    int idx = rand() % freeCells.size();
    return freeCells[idx];
}
Move AI::findBestMove(Board& board, char aiSymbol, char playerSymbol) {
    int bestVal = -1000;
    Move bestMove = { -1, -1 };
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board.grid[i][j] == ' ') {
                board.grid[i][j] = aiSymbol;
                int moveVal = minimax(board, 0, false, aiSymbol, playerSymbol);
                board.grid[i][j] = ' ';

                if (moveVal > bestVal) {
                    bestVal = moveVal;
                    bestMove = { i, j };
                }
            }
        }
    }
    return bestMove;
}
int AI::minimax(Board& board, int depth, bool isMax, char aiSymbol, char playerSymbol) {
    if (board.checkWin(aiSymbol)) return 10 - depth;
    if (board.checkWin(playerSymbol)) return depth - 10;
    if (board.isFull()) return 0;
    if (isMax) {
        int best = -1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board.grid[i][j] == ' ') {
                    board.grid[i][j] = aiSymbol;
                    best = max(best, minimax(board, depth + 1, false, aiSymbol, playerSymbol));
                    board.grid[i][j] = ' ';
                }
            }
        }
        return best;
    }
    else {
        int best = 1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board.grid[i][j] == ' ') {
                    board.grid[i][j] = playerSymbol;
                    best = min(best, minimax(board, depth + 1, true, aiSymbol, playerSymbol));
                    board.grid[i][j] = ' ';
                }
            }
        }
        return best;
    }
}