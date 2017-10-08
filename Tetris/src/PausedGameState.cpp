#include "PausedGameState.h"
#include "RunningGameState.h"

PausedGameState::PausedGameState(GameState& o)
:
    GameState(o)
{
    //ctor
}

PausedGameState::~PausedGameState()
{
    //dtor
}

void PausedGameState::draw(){
    GameState::draw();
    window.draw(pausedSprite);
}

void PausedGameState::update(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
        game = new RunningGameState(*this);
        delete this;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::N)){
        score=0;
        scoreText.setString("Score: 0");
        for(int y=0; y<H; y++){
            for(int x=0; x<W; x++){
                grid[y][x]=EMPTY;
            }
        }
        actShape = ((Shape::Shapes)(rng()%((int)Shape::nShapes)));
        game = new RunningGameState(*this);
        delete this;
    }
}
