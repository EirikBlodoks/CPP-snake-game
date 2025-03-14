
#include "Game.h"

int main() {
    try {
        TDT4102::Game game;
        game.run();
    } catch (const std::exception& e) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

