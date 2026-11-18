#include "Game.h"
#include <limits>
using namespace std;
Game::Game() {
    srand(time(NULL));
}
void Game::run() {
    bool keepPlaying = true;
    while (keepPlaying) {
        board.reset();
        system("cls"); 
        cout << "=================================\n";
        cout << "       КРЕСТИКИ-НОЛИКИ           \n";
        cout << "=================================\n";
        Difficulty level = chooseDifficulty();
        bool playerStarts = chooseWhoStarts();
        char currentTurn = playerStarts ? PLAYER_SYMBOL : AI_SYMBOL;
        while (true) {
            board.draw();
            if (currentTurn == PLAYER_SYMBOL) {
                playerMove();
                if (board.checkWin(PLAYER_SYMBOL)) {
                    board.draw();
                    cout << ">>> Поздравляю! Вы победили! <<<\n";
                    score.player++;
                    break;
                }
            }
            else {
                cout << "Ход компьютера...\n";
                aiMove(level);
                if (board.checkWin(AI_SYMBOL)) {
                    board.draw();
                    cout << ">>> Увы, победил компьютер. <<<\n";
                    score.ai++;
                    break;
                }
            }
            if (board.isFull()) {
                board.draw();
                cout << ">>> Ничья! <<<\n";
                score.draws++;
                break;
            }
            currentTurn = (currentTurn == PLAYER_SYMBOL) ? AI_SYMBOL : PLAYER_SYMBOL;
        }
        printScore();
        keepPlaying = askPlayAgain();
    }
    cout << "Игра завершена. До встречи!\n";
}
Difficulty Game::chooseDifficulty() {
    int choice;
    while (true) {
        cout << "\nВыберите уровень сложности:\n";
        cout << "1 - Легкий (рандом)\n";
        cout << "2 - Средний (иногда думает)\n";
        cout << "3 - Сложный (непобедимый)\n";
        cout << "Ваш выбор: ";
        if (cin >> choice && choice >= 1 && choice <= 3) {
            return (Difficulty)choice;
        }
        else {
            cout << "Ошибка ввода. Попробуйте снова.\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
}
bool Game::chooseWhoStarts() {
    int choice;
    while (true) {
        cout << "\nКто ходит первым?\n";
        cout << "1 - Вы (X)\n";
        cout << "2 - Компьютер (O)\n";
        cout << "Ваш выбор: ";

        if (cin >> choice && (choice == 1 || choice == 2)) {
            return choice == 1;
        }
        else {
            cout << "Ошибка! Введите 1 или 2.\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
}
void Game::playerMove() {
    int row, col;
    while (true) {
        cout << "Введите строку и столбец (от 1 до 3, через пробел): ";
        if (cin >> row >> col) {
            row--; col--;

            if (board.isMoveValid(row, col)) {
                board.grid[row][col] = PLAYER_SYMBOL;
                return;
            }
            else {
                cout << "Неверные координаты или клетка занята!\n";
            }
        }
        else {
            cout << "Ошибка ввода. Введите два числа.\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
}
void Game::aiMove(Difficulty level) {
    Move bestMove = ai.getMove(board, AI_SYMBOL, PLAYER_SYMBOL, level);
    board.grid[bestMove.row][bestMove.col] = AI_SYMBOL;
}
void Game::printScore() {
    cout << "\n--- СЧЕТ ---\n";
    cout << "Побед игрока: " << score.player << "\n";
    cout << "Побед компьютера: " << score.ai << "\n";
    cout << "Ничьих: " << score.draws << "\n";
}
bool Game::askPlayAgain() {
    char answer;
    while (true) {
        cout << "\nСыграть еще раз? (y/n): ";
        cin >> answer;
        answer = tolower(answer);

        if (answer == 'y') return true;
        if (answer == 'n') return false;
        cout << "Введите 'y' или 'n'.\n";
    }
}