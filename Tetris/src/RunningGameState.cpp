#include "RunningGameState.h"

RunningGameState::RunningGameState(sf::RenderWindow& window)
:
    GameState(window),actShape(Shape::T)
{

}

RunningGameState::RunningGameState(GameState& o)
:
    GameState(o),actShape(Shape::T)
{

}

RunningGameState::~RunningGameState()
{

}

void RunningGameState::draw(){
    GameState::draw();
    actShape.draw(window);
}

void RunningGameState::update(){
    if(actShape.update(grid)){ //It's important to update before anything else
        actShape = Shape(Shape::T);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        if(!spacePressedLastFrame)
            actShape.rot();
        spacePressedLastFrame=1;
    } else {
        spacePressedLastFrame=0;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        actShape.moveL(grid);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        actShape.moveR(grid);
    }

}
