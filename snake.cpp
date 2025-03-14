#include "Snake.h"

namespace TDT4102 {
    Snake::Snake(Point startPos) : currentDir(Direction::RIGHT) {//Direction er ett egetdefinert enum
        body.push_back(startPos);
    }

    void Snake::changeDirection(Direction newDir) {
        if ((currentDir == Direction::UP && newDir != Direction::DOWN) ||
            (currentDir == Direction::DOWN && newDir != Direction::UP) ||
            (currentDir == Direction::LEFT && newDir != Direction::RIGHT) ||
            (currentDir == Direction::RIGHT && newDir != Direction::LEFT)) {//sjekker som sørger for at man ikke kan bytte direkte mellom høyre og venstre eller opp og ned
            currentDir = newDir;
        }
    }

    void Snake::move() {
        Point newHead = body.front();
        switch(currentDir) {//bruker en switch-case struktur til å håndtere de ulike retningene
            case Direction::UP:    newHead.y--;
            break;
            case Direction::DOWN:  newHead.y++;
             break;
            case Direction::LEFT:  newHead.x--;
             break;
            case Direction::RIGHT: newHead.x++; 
            break;//y eller x verdien blir 1 mer eller mindre for hver frame, som representerer en bevegelse i den gitte retning
        }
        
        body.insert(body.begin(), newHead);//dette er delen av koden som hele tiden flytter den fremste delen av slangen for hver frame
        if (!shouldGrow) {
            body.pop_back();//så lenge det ikke er meningen at slangen skal vokse, sletter vi også bakerste del av slangen
        }
        shouldGrow = false;
    }

    void Snake::grow() { shouldGrow = true; }//når denne kalles blir shouldGrow true slik at bakerste element ikke blir slettet i en frame i move funksjonen

    bool Snake::checkCollision() const {
        const Point& head = body.front();//henter ut hodet
        // Sjekk for veggkollisjon
        if (head.x < 0 || head.x >= 40 || head.y < 0 || head.y >= 30) return true;
            
        // Sjekk for om den kolliderer i seg selv
        for (size_t i = 1; i < body.size(); ++i) {
            if (head.x == body[i].x && head.y == body[i].y) return true;
        }
        switch(map){
                case 0: for (int i = 10; i <30; ++i){if (head.x ==i && (head.y  == 10 || head.y==20)){return true;}};//Sjekk for kollisjon basert på ulike maps
                break;
                case 1:for (int i = 5; i < 20; ++i) {if ((head.x ==10 || head.x==  32)&& head.y==i){return true;}};
                 break;
                case 2:true;
                 break;
                default: true; 
                break;}
        return false;
    }

    bool Snake::checkFoodCollision(Point foodPos) const {
        return body.front().x == foodPos.x && body.front().y == foodPos.y; //sjekker om slangen har truffet maten
    }

    const std::vector<Point>& Snake::getBody() const { return body; }


    int Snake::getMap(){return map;}

    void Snake::setMap(int newMap){map=newMap;}
}