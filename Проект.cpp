#include "Game.h"
#include <windows.h>
#include <clocale>
using namespace std;
int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    setlocale(LC_ALL, "ru_RU.UTF-8");

    Game game;
    game.run();
    return 0;
}