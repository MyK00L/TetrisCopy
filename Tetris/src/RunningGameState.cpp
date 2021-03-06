#include "RunningGameState.h"
#include "PausedGameState.h"
#include <string>

RunningGameState::RunningGameState(sf::RenderWindow& window, GameState*& game)
:
    GameState(window, game)
{
    actShape = ((Shape::Shapes)(rng()%((int)Shape::nShapes)));
    moveClock.restart();
}

RunningGameState::RunningGameState(GameState& o)
:
    GameState(o)
{
    moveClock.restart();
}

RunningGameState::~RunningGameState()
{

}

void RunningGameState::draw(){
    GameState::draw();
}

void RunningGameState::update(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::P)){
        game = new PausedGameState(*this);
        delete this;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        if(!spacePressedLastFrame)
            actShape.rot(grid);
        spacePressedLastFrame=1;
    } else {
        spacePressedLastFrame=0;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && moveClock.getElapsedTime().asMilliseconds()>moveDelayMillis){
        if(actShape.moveL(grid))
            moveClock.restart();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && moveClock.getElapsedTime().asMilliseconds()>moveDelayMillis){
        if(actShape.moveR(grid))
            moveClock.restart();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        actShape.vel = blockSide;
    } else {
        actShape.vel = blockSide/4.0f;
    }
    if(actShape.update(grid)){
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
        if(movAm==1)score+=40;
        else if(movAm==2)score+=100;
        else if(movAm==3)score+=300;
        else if(movAm==4)score+=1200;
        moveClock.restart();
        actShape = Shape((Shape::Shapes)(rng()%((int)Shape::nShapes)));
        scoreText.setString("Score: " + std::to_string(score));
    }
}
