#pragma once
#include "AnimationWindow.h"
#include "Point.h"
#include "Snake.h"
#include "Color.h"

class PauseGUI {
public:
    PauseGUI(int windowWidth, int windowHeight);

    void draw(TDT4102::AnimationWindow& window);
    bool handleContinue(TDT4102::AnimationWindow& window);
    bool handleQuit(TDT4102::AnimationWindow& window);
    bool handleMap(TDT4102::AnimationWindow& window);
    bool handleDifficulty(TDT4102::AnimationWindow& window);

private:
    int windowWidth;
    int windowHeight;
    int menuWidth = 300;
    int menuHeight = 350;
    int menuX;
    int menuY;

    TDT4102::Snake snake;

    TDT4102::Point getMouseCoordinates(TDT4102::AnimationWindow& window) const;
};