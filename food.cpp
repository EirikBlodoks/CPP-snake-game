#include "Food.h"
#include <random>
#include <algorithm>

namespace TDT4102 {
    Food::Food():snake({20, 15}) { position = {0, 0};}

    void Food::respawn(const std::vector<Point>& snakeBody) {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_int_distribution<> xDist(0, 39);
        std::uniform_int_distribution<> yDist(0, 29); 
        position = {xDist(gen), yDist(gen)}; // Generer en tilfeldig posisjon
        bool goodPosition=false;

    while(!goodPosition){

        switch (snake.getMap()){
            case 0 : for (int i = 10; i <30; ++i){
                if (position.x <i && (position.y  == 10 || position.y==20)){
                    goodPosition=false;
                }}
                break;
            case 1 : for (int i = 5; i < 20; ++i) {//sjekker om eplet overlapper med hindrene for mapsene
                if ((position.x ==10 || position.x==  32)&& position.y==i){
                    goodPosition =false;
                }}
                break;
            default : goodPosition =true;
            }
        
        

        if (std::any_of(snakeBody.begin(), snakeBody.end(), [&](const Point& p) { return p.x == position.x && p.y == position.y; }) ) {// Sjekk om posisjonen overlapper med slangen
            goodPosition=false;
        }
        else{goodPosition=true;}
        position = {xDist(gen), yDist(gen)};// Hvis eplet overlapper med noe, generer vi en ny posisjon
    }
    }
    Point Food::getPosition() const { return position; }

}