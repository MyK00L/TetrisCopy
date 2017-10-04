#include "RunningGameState.h"


RunningGameState::RunningGameState(sf::RenderWindow& window)
:
    GameState(window),actShape(Shape::T)
{
    moveClock.restart();
}

RunningGameState::RunningGameState(GameState& o)
:
    GameState(o),actShape(Shape::T)
{
    moveClock.restart();
}

RunningGameState::~RunningGameState()
{

}

void RunningGameState::draw(){
    GameState::draw();
    actShape.draw(window);
}

void RunningGameState::update(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        if(!spacePressedLastFrame)
            actShape.rot(grid);
        spacePressedLastFrame=1;
    } else {
        spacePressedLastFrame=0;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && moveClock.getElapsedTime().asMilliseconds()>moveDelayMillis){
        actShape.moveL(grid);
        moveClock.restart();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && moveClock.getElapsedTime().asMilliseconds()>moveDelayMillis){
        actShape.moveR(grid);
        moveClock.restart();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        actShape.vel = blockSide;
    } else {
        actShape.vel = blockSide/8.0f;
    }
    if(actShape.update(grid)){
        actShape = Shape((Shape::Shapes)(rng()%((int)Shape::nShapes)));
        int movAm=0;
        for(int y=H-1; y; --y){
            int num=0;
            for(int x=0; x<W; ++x){
                if(grid[y][x]!=EMPTY)num++;
                if(movAm){
                    grid[y+movAm][x]=grid[y][x];
                }
            }
            if(num==W)movAm++;
        }
    }
}
