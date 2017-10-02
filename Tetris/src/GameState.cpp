#include "GameState.h"

sf::Texture GameState::blockTexture;
sf::Sprite GameState::blockSprite;
sf::Color GameState::EMPTY = sf::Color(0,0,0);
sf::Color ** GameState::grid;

GameState::GameState(sf::RenderWindow& window)
:
    window(window)
{
    blockTexture.loadFromFile("block.png");
    blockSprite.setTexture(blockTexture);
    blockSprite.setScale(sf::Vector2f(blockSide/32, blockSide/32));
    grid = new sf::Color * [32];
    for(int y=0; y<32; y++){
        grid[y]=new sf::Color[32];
        for(int x=0; x<32; x++){
            grid[y][x] = EMPTY;
        }
    }
    grid[31][31]=sf::Color(255,0,0);
}

GameState::GameState(GameState& o)
:
    window(o.window)
{

}

GameState::~GameState()
{

}

void GameState::draw(){
    for(int y=0; y<32; y++){
        for(int x=0; x<32; x++){
            if(grid[y][x]!=EMPTY){
                blockSprite.setPosition(sf::Vector2f(x*blockSide,y*blockSide));
                blockSprite.setColor(grid[y][x]);
                window.draw(blockSprite);
            }
        }
    }
}

void GameState::update(){

}