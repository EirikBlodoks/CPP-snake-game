#include "Game.h"
#include <thread>
#include <windows.h>

namespace TDT4102 {
    Game::Game() //start av spill: lager vindu, plasserer slangen, henter highscore, genererer en tilfeldig matbit, og setter bakgrunnsfarge
        : AnimationWindow(100, 100, 800, 600, "Snake Game"), snake({20, 15}), pauseGUI(width(), height()) {

        highScore = FileHandler::loadHighScore();
        food.respawn(snake.getBody());
        setBackgroundColor(Color::light_gray);
    }

    void Game::run() {
        while (!should_close() && !gameOver) {
            handleInput();
            if(!paused){update();}
                    try {
                    drawGame();
                drawMenu();
                } 
                    catch (const std::exception& e) {
        
                    show_error_dialog("Drawing error: " + std::string(e.what()));
                    throw GameException("Drawing failed");
            }
            
            next_frame();
            Sleep(100);//denne kan du tweake for å påvirke vanskelighetsgraden, jo lavere tall, jo fortere går det.
}
        
        if (score > highScore) {
            try {
                FileHandler::saveHighScore(score);
            } catch (const FileIOException& e) {
                show_error_dialog("Failed to save high score: " + std::string(e.what()));
            }}

    }

    void Game::handleInput() {
        static const std::unordered_map<KeyboardKey, Snake::Direction> keyMap = {
            {KeyboardKey::UP, Snake::Direction::UP},
            {KeyboardKey::DOWN, Snake::Direction::DOWN},
            {KeyboardKey::LEFT, Snake::Direction::LEFT},
            {KeyboardKey::RIGHT, Snake::Direction::RIGHT}
        };
    
        for (const auto& [key, dir] : keyMap) {
            if (is_key_down(key)) {
                snake.changeDirection(dir);
                break;
            }
        }
    
        if (is_key_down(KeyboardKey::ESCAPE)) {
            paused = !paused; // Skru av og på pause når man trykker esc
        }
        if (pauseGUI.handleContinue(*this)){paused=false;}//når man trykker continue skrur man av pause
        if (pauseGUI.handleQuit(*this)){gameOver=true; return;} //når man trykker quit avslutter man spillet
        if (pauseGUI.handleMap(*this)){if (snake.getMap()==2){snake.setMap(0);}
                                        else{snake.setMap(snake.getMap()+1);}}
        if (paused){pauseGUI.draw(*this);}
    }

    void Game::update() {
        snake.move();
        
        if (snake.checkCollision()) {
            gameOver = true;
            return;
        }
        
        if (snake.checkFoodCollision(food.getPosition())) {
            snake.grow();
            score += 10;
            food.respawn(snake.getBody());
        }
    }

    void Game::drawGame() {
        // Tegn slangen
        for (const auto& segment : snake.getBody()) {
            draw_rectangle({segment.x * 20, segment.y * 20}, 20, 20, Color::green);
        }
        
        // Tegn maten
        Point foodPos = food.getPosition();
        draw_rectangle({foodPos.x * 20, foodPos.y * 20}, 20, 20, Color::red);

        switch(snake.getMap()) {//bruker en switch-case struktur til å håndtere de ulike mapsene
            case 0: for (int i = 0; i < 20; ++i) {draw_rectangle({200 + i * 20, 200}, 20, 20, Color::black); draw_rectangle({200 + i * 20, 400}, 20, 20, Color::black);}
            break;
            case 1: for (int i = 0; i < 20; ++i) {draw_rectangle({200 , i * 20 + 100}, 20, 20, Color::black); draw_rectangle({640,  i * 20+ 100}, 20, 20, Color::black);}
             break;
            case 2:true;
             break;
            case 3:true; 
            break;}
    }

    void Game::drawMenu() {
        draw_text({10, 10}, "Score: " + std::to_string(score), Color::black, 20);
        draw_text({10, 40}, "High Score: " + std::to_string(highScore), Color::black, 20);
        if (gameOver) {
            draw_text({200, 300}, "Game Over! Final Score: " + std::to_string(score), Color::red, 30);
        }

    }
}