#include <cmath>
#include "Shape.h"
#include "GameState.h"

float Shape::vel=blockSide/4.0f;

Shape::Shape(Shapes shape)
{
    pos=sf::Vector2f((W/2)*blockSide,blockSide);
    if(shape == O){
        blocks[0]=sf::Vector2f(0,0);
        blocks[1]=sf::Vector2f(0,1);
        blocks[2]=sf::Vector2f(1,0);
        blocks[3]=sf::Vector2f(1,1);
        col = sf::Color(255,255,0);
    } else if(shape == S){
        blocks[0]=sf::Vector2f(0,0);
        blocks[1]=sf::Vector2f(0,1);
        blocks[2]=sf::Vector2f(-1,1);
        blocks[3]=sf::Vector2f(1,0);
        col = sf::Color(0,255,0);
    } else if(shape == Z){
        blocks[0]=sf::Vector2f(0,0);
        blocks[1]=sf::Vector2f(0,1);
        blocks[2]=sf::Vector2f(1,1);
        blocks[3]=sf::Vector2f(-1,0);
        col = sf::Color(255,0,0);
    } else if(shape == T){
        blocks[0]=sf::Vector2f(0,0);
        blocks[1]=sf::Vector2f(0,-1);
        blocks[2]=sf::Vector2f(-1,0);
        blocks[3]=sf::Vector2f(1,0);
        col = sf::Color(127,0,255);
    } else if(shape == L){
        blocks[0]=sf::Vector2f(0,0);
        blocks[1]=sf::Vector2f(-1,0);
        blocks[2]=sf::Vector2f(1,0);
        blocks[3]=sf::Vector2f(1,-1);
        col = sf::Color(255,127,0);
    } else if(shape == J){
        blocks[0]=sf::Vector2f(0,0);
        blocks[1]=sf::Vector2f(1,0);
        blocks[2]=sf::Vector2f(-1,0);
        blocks[3]=sf::Vector2f(-1,-1);
        col = sf::Color(0,0,255);
    } else if(shape == I){
        blocks[0]=sf::Vector2f(0,0);
        blocks[1]=sf::Vector2f(-1,0);
        blocks[2]=sf::Vector2f(1,0);
        blocks[3]=sf::Vector2f(2,0);
        col = sf::Color(0,255,255);
    }
}

Shape::~Shape()
{

}

void Shape::rot(sf::Color ** grid){
    for(int i=0;i<4;i++){
        int px = (int)(pos.x/blockSide - blocks[i].y);
        int py = (int)(pos.y/blockSide + blocks[i].x);
        int pyb = (int)ceil(pos.y/blockSide + (float)blocks[i].x);
        if(px>=W||px<0||pyb>=H||py<0)return;
        if(grid[py][px]!=EMPTY || grid[pyb][px]!=EMPTY)return;
    }
    for(int i=0;i<4;i++){
        blocks[i]=sf::Vector2f(-blocks[i].y,blocks[i].x);
    }
}

void Shape::draw(sf::RenderWindow& window){
    for(int i=0;i<4;i++){
        GameState::blockSprite.setPosition(pos+blocks[i]*(float)blockSide);
        GameState::blockSprite.setColor(col);
        window.draw(GameState::blockSprite);
    }
}

void Shape::moveR(sf::Color ** grid){
    for(int i=0; i<4; i++){
        int py=(int)(pos.y/blockSide + blocks[i].y);
        int px=(int)(pos.x/blockSide + blocks[i].x);
        if(px==W-1){return;}
        if(grid[py][px+1]!=EMPTY){return;}
        int pyb=(int)ceil(pos.y/blockSide + (float)blocks[i].y);
        if(pyb<H&&grid[pyb][px+1]!=EMPTY){return;}
    }
    pos.x+=blockSide;
}

void Shape::moveL(sf::Color ** grid){
    for(int i=0; i<4; i++){
        int py=(int)(pos.y/blockSide + blocks[i].y);
        int px=(int)(pos.x/blockSide + blocks[i].x);
        if(px==0){return;}
        if(grid[py][px-1]!=EMPTY){return;}
        int pyb=(int)ceil(pos.y/blockSide + (float)blocks[i].y);
        if(pyb<H&&grid[pyb][px-1]!=EMPTY){return;}
    }
    pos.x-=blockSide;
}

bool Shape::update(sf::Color ** grid){
    int py = (int)(pos.y/blockSide), py1 = (int)((pos.y+vel)/blockSide);
    if( py != (int)ceil(pos.y/blockSide) && py==py1 ){
        pos.y+=vel;
        return 0;
    }
    for(int i=0;i<4;i++){
        int pyb = py1 + blocks[i].y +1;
        int px=(int)(pos.x/blockSide + blocks[i].x);
        if(pyb >= H || grid[pyb][px]!=EMPTY){
            for(i=0;i<4;i++){
                int py = py1 + blocks[i].y;
                int px=(int)(pos.x/blockSide + blocks[i].x);
                grid[py][px]=col;
            }
            return 1;
        }
    }
    pos.y+=vel;
    return 0;
}
