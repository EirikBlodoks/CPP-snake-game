#include "PauseGUI.h"
#include <iostream>

PauseGUI::PauseGUI(int windowWidth, int windowHeight): snake({20, 15}) {

    menuX = (windowWidth - menuWidth) / 2; 
    menuY = (windowHeight - menuHeight) / 2;//Finner midtpunktet av vinduet
}

void PauseGUI::draw(TDT4102::AnimationWindow& window) {
    window.draw_rectangle({menuX, menuY}, menuWidth, menuHeight, TDT4102::Color::white);// Tegn en boks som menyen er i
    window.draw_text({menuX + 90, menuY + 30}, "Paused", TDT4102::Color::black, 30); // Skriv Paused øverst i menyen

    window.draw_rectangle({menuX + 50, menuY + 80}, 200, 50, TDT4102::Color::green);
    window.draw_text({menuX + 90, menuY + 95}, "Continue", TDT4102::Color::white, 20);// Lag Continueknapp

    window.draw_rectangle({menuX + 50, menuY + 140}, 200, 50, TDT4102::Color::red);
    window.draw_text({menuX + 90, menuY + 155}, "Quit", TDT4102::Color::white, 20);//Lag quit knapp

    window.draw_rectangle({menuX + 50, menuY + 195}, 200, 50, TDT4102::Color::dim_grey);
    window.draw_text({menuX + 90, menuY + 210}, "Switch Map", TDT4102::Color::white, 20);//Lag map knapp, hvert trykk skal endre map

    window.draw_rectangle({menuX + 50, menuY + 250}, 200, 50, TDT4102::Color::dim_grey);
    window.draw_text({menuX + 90, menuY + 265}, "Change Difficulty", TDT4102::Color::white, 20);
}

bool PauseGUI::handleContinue(TDT4102::AnimationWindow& window) {
    // Hent musas posisjon
    TDT4102::Point mousePos = getMouseCoordinates(window);

    if (window.is_left_mouse_button_down()) {// Sjekk om musa er trykket ned
        if (mousePos.x >= menuX + 50 && mousePos.x <= menuX + 250 &&
            mousePos.y >= menuY + 80 && mousePos.y <= menuY + 130) {// Sjekk om contunue er trykkt
            return true; // Fortsett spillet, denne blir satt inn i xxx
        }
    }
    return false;
}

bool PauseGUI::handleQuit(TDT4102::AnimationWindow& window){

    TDT4102::Point mousePos = getMouseCoordinates(window);
    if (window.is_left_mouse_button_down()) {
    if (mousePos.x >= menuX + 50 && mousePos.x <= menuX + 250 &&
        mousePos.y >= menuY + 140 && mousePos.y <= menuY + 190) {
        return true; // Avslutt spillet
    }
    }
    return false;
}

bool PauseGUI::handleMap(TDT4102::AnimationWindow& window){

    TDT4102::Point mousePos =  getMouseCoordinates(window);
    if (window.is_left_mouse_button_down()) {
        if (mousePos.x >= menuX + 50 && mousePos.x <= menuX + 250 &&
            mousePos.y >= menuY + 200 && mousePos.y <= menuY + 250){
                return true;
            }
    }
    return false;
}
bool PauseGUI::handleDifficulty(TDT4102::AnimationWindow& window){

    TDT4102::Point mousePos =  getMouseCoordinates(window);
    if (window.is_left_mouse_button_down()){
        if (mousePos.x >= menuX + 50 && mousePos.x <= menuX + 250 &&
            mousePos.y >= menuY + 260 && mousePos.y <= menuY + 310){
                return true;
            }
    }
    return false;
}

TDT4102::Point PauseGUI::getMouseCoordinates(TDT4102::AnimationWindow& window) const {
    return window.get_mouse_coordinates();
}//Definerer en getMouseCoordinates inne i PauseGUI
