#pragma once
#include "Point.h" 
#include "snake.h"
#include <vector>  

namespace TDT4102 {
    class Food {
    public:
        Food();
        void respawn(const std::vector<Point>& snakeBody); 
        Point getPosition() const;
    private:
        Point position;
        Snake snake;
        bool goodPosition= false;
    };
}