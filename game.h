#pragma once
#include "AnimationWindow.h"
#include "Snake.h"
#include "Food.h"
#include "FileHandler.h"
#include "Exceptions.h"
#include "PauseGUI.h"


namespace TDT4102 {
    class Game : public AnimationWindow {
    public:
        Game();
        void run();
        
    private:
        void handleInput(); 
        void update();
        void drawGame();
        void drawMenu();
        
        Snake snake;
        Food food;
        PauseGUI pauseGUI;
        
        int score = 0;
        int highScore = 0;
        bool gameOver = false;
        bool paused = false;
        int difficulty;
        
    };
}