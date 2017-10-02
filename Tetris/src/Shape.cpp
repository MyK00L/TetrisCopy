#include <cmath>
#include "Shape.h"
#include "GameState.h"

float Shape::vel=4;

Shape::Shape(Shapes shape)
{
    pos=sf::Vector2f(32,100);
    if(shape == I){
        blocks[0]=sf::Vector2f(0,-1);
        blocks[1]=sf::Vector2f(0,0);
        blocks[2]=sf::Vector2f(0,1);
        blocks[3]=sf::Vector2f(0,2);
        col = sf::Color(255,0,0);
    }
    else if(shape == T){
        blocks[0]=sf::Vector2f(-1,0);
        blocks[1]=sf::Vector2f(0,0);
        blocks[2]=sf::Vector2f(1,0);
        blocks[3]=sf::Vector2f(0,1);
        col = sf::Color(255,128,0);
    }
    else if(shape == S){
        blocks[0]=sf::Vector2f(0,1);
        blocks[1]=sf::Vector2f(1,1);
        blocks[2]=sf::Vector2f(0,0);
        blocks[3]=sf::Vector2f(-1,0);
        col = sf::Color(0,0,200);
    }
    else if(shape == Q){
        blocks[0]=sf::Vector2f(1,0);
        blocks[1]=sf::Vector2f(0,0);
        blocks[2]=sf::Vector2f(0,1);
        blocks[3]=sf::Vector2f(1,1);
        col = sf::Color(255,255,255);
    }
}

Shape::~Shape()
{

}

void Shape::rot(){
    for(int i=0;i<4;i++){
        blocks[i]=sf::Vector2f(-blocks[i].y,blocks[i].x);
    }
}

void Shape::draw(sf::RenderWindow& window){
    for(int i=0;i<4;i++){
        GameState::blockSprite.setPosition(pos+blocks[i]*GameState::blockSide);
        GameState::blockSprite.setColor(col);
        window.draw(GameState::blockSprite);
    }
}

void Shape::moveR(sf::Color ** grid){
    bool b=1;
    for(int i=0; i<4; i++){
        int py=(int)ceil(pos.y/GameState::blockSide + blocks[i].y);
        int px=(int)(pos.x/GameState::blockSide + blocks[i].x);
        if(px==31){b=0;break;}
        if(grid[py][px+1]!=GameState::EMPTY){b=0;break;}
    }
    if(b)
        pos.x+=GameState::blockSide;
}

void Shape::moveL(sf::Color ** grid){
    bool b=1;
    for(int i=0; i<4; i++){
        int py=(int)ceil(pos.y/GameState::blockSide + blocks[i].y);
        int px=(int)(pos.x/GameState::blockSide + blocks[i].x);
        if(px==0){b=0;break;}
        if(grid[py][px-1]!=GameState::EMPTY){b=0;break;}
    }
    if(b)
        pos.x-=GameState::blockSide;
}

bool Shape::update(sf::Color ** grid){
    pos.y+=vel;
    for(int i=0;i<4;i++){
        int py=(int)ceil(pos.y/GameState::blockSide + blocks[i].y);
        int px=(int)(pos.x/GameState::blockSide + blocks[i].x);
        int py1 = (int)ceil((pos.y+vel)/GameState::blockSide + blocks[i].y);
        if(py1!=py && (py>=(int)(512/GameState::blockSide)-1 || grid[py+1][px] != GameState::EMPTY)){
            for(i=0;i<4;i++){
                py=(int)ceil(pos.y/GameState::blockSide + blocks[i].y);
                px=(int)(pos.x/GameState::blockSide + blocks[i].x);
                grid[py][px]=col;
            }
            return 1;
        }
    }
    return 0;
}
