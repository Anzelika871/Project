#pragma once
#include <iostream>

class Board {
public:
    char grid[3][3];

    Board();                              
    void reset();                                                   // Очистка поля
    void draw();                                                   // Отрисовка поля в консоли
    bool isMoveValid(int row, int col);                           // Проверка, можно ли сходить
    bool checkWin(char player);                                  // Проверка победы игрока
    bool isFull();                                              // Проверка, заполнено ли поле
};