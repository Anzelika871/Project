#pragma once
#include <iostream>

class Board {
public:
    char grid[3][3];

    Board();                              
    void reset();                                                  
    void draw();                                               
    bool isMoveValid(int row, int col);                         
    bool checkWin(char player);                                
    bool isFull();                                              
};