#include "FileHandler.h"
#include <fstream>
#include "Exceptions.h"

void FileHandler::saveHighScore(int score) {//Funksjon for å lagre en hghscore, denne blir kalt dersom score>hiscore i game.cpp
    try {
        std::ofstream file("highscore.txt");
        if (!file) throw FileIOException("Failed to save high score");
        file << score;
    } catch (const std::exception& e) {
        throw FileIOException(e.what());
    }
}

int FileHandler::loadHighScore() { //funksjon for å laste highscoren, denne blir kalt hvert spill
    try {
        std::ifstream file("highscore.txt");
        if (!file) return 0;
        int score;
        file >> score;
        return score;
    } catch (...) {
        return 0;
    }
}