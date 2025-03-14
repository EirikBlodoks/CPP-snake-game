#pragma once
#include <vector>
#include "Point.h"

namespace TDT4102 {
    class Snake {
    public:
        enum class Direction { UP, DOWN, LEFT, RIGHT};
        
        Snake(Point startPos);
                void changeDirection(Direction newDir);
        void move();
        void grow();
        bool checkCollision() const;
        bool checkFoodCollision(Point foodPos) const;
        int getMap();
        void setMap(int newMap);
        const std::vector<Point>& getBody() const;
        
        
    private:
        std::vector<Point> body;
        Direction currentDir;
        bool shouldGrow = false;
        int map;
    };
}