#include "GameState.h"

sf::Texture GameState::blockTexture;
sf::Sprite GameState::blockSprite;
sf::Font GameState::font;
sf::Text GameState::scoreText;
sf::Color ** GameState::grid;
int GameState::score = 0;
std::mt19937 GameState::rng(std::random_device{}());

GameState::GameState(sf::RenderWindow& window)
:
    window(window)
{
    blockTexture.loadFromFile("block.png");
    blockSprite.setTexture(blockTexture);
    blockSprite.setScale(sf::Vector2f((float)blockSide/blockTexture.getSize().x, (float)blockSide/blockTexture.getSize().y));
    font.loadFromFile("DejaVuSansMono.ttf");
    scoreText.setFont(font);
    scoreText.setColor(sf::Color(255,255,255));
    scoreText.setPosition(0,0);
    scoreText.setCharacterSize(16);
    scoreText.setString("Score: 0");
    grid = new sf::Color * [H];
    for(int y=0; y<H; y++){
        grid[y]=new sf::Color[W];
        for(int x=0; x<W; x++){
            grid[y][x] = EMPTY;
        }
    }
}

GameState::GameState(GameState& o)
:
    window(o.window)
{

}

GameState::~GameState()
{
    for(int y=0; y<H; y++){
        delete[] grid[y];
    }
    delete [] grid;
}

void GameState::draw(){
    for(int y=0; y<H; y++){
        for(int x=0; x<W; x++){
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
