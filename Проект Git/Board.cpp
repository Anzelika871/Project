#include "Board.h"
using namespace std;
Board::Board() {
    reset();
}
void Board::reset() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grid[i][j] = ' ';
        }
    }
}
void Board::draw() {
    cout << "\n  1 2 3\n";
    cout << " -------\n";
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << "|";
        for (int j = 0; j < 3; j++) {
            cout << grid[i][j] << "|";
        }
        cout << "\n -------\n";
    }
}
bool Board::isMoveValid(int row, int col) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3) {
        if (grid[row][col] == ' ') return true;
    }
    return false;
}
bool Board::checkWin(char player) {
    for (int i = 0; i < 3; i++) {
        if (grid[i][0] == player && grid[i][1] == player && grid[i][2] == player) return true;
        if (grid[0][i] == player && grid[1][i] == player && grid[2][i] == player) return true;
    }
    if (grid[0][0] == player && grid[1][1] == player && grid[2][2] == player) return true;
    if (grid[0][2] == player && grid[1][1] == player && grid[2][0] == player) return true;

    return false;
}
bool Board::isFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] == ' ') return false;
        }
    }
    return true;
}