#include <cmath>
#include "Shape.h"
#include "GameState.h"

float Shape::vel=blockSide/4.0f;

Shape::Shape(Shapes shape)
{
    pos=sf::Vector2i(W/2,1);
    if(shape == O){
        blocks[0]=sf::Vector2i(0,0);
        blocks[1]=sf::Vector2i(0,1);
        blocks[2]=sf::Vector2i(1,0);
        blocks[3]=sf::Vector2i(1,1);
        col = sf::Color(255,255,0);
    } else if(shape == S){
        blocks[0]=sf::Vector2i(0,0);
        blocks[1]=sf::Vector2i(0,1);
        blocks[2]=sf::Vector2i(-1,1);
        blocks[3]=sf::Vector2i(1,0);
        col = sf::Color(0,255,0);
    } else if(shape == Z){
        blocks[0]=sf::Vector2i(0,0);
        blocks[1]=sf::Vector2i(0,1);
        blocks[2]=sf::Vector2i(1,1);
        blocks[3]=sf::Vector2i(-1,0);
        col = sf::Color(255,0,0);
    } else if(shape == T){
        blocks[0]=sf::Vector2i(0,0);
        blocks[1]=sf::Vector2i(0,-1);
        blocks[2]=sf::Vector2i(-1,0);
        blocks[3]=sf::Vector2i(1,0);
        col = sf::Color(127,0,255);
    } else if(shape == L){
        blocks[0]=sf::Vector2i(0,0);
        blocks[1]=sf::Vector2i(-1,0);
        blocks[2]=sf::Vector2i(1,0);
        blocks[3]=sf::Vector2i(1,-1);
        col = sf::Color(255,127,0);
    } else if(shape == J){
        blocks[0]=sf::Vector2i(0,0);
        blocks[1]=sf::Vector2i(1,0);
        blocks[2]=sf::Vector2i(-1,0);
        blocks[3]=sf::Vector2i(-1,-1);
        col = sf::Color(0,0,255);
    } else if(shape == I){
        blocks[0]=sf::Vector2i(0,0);
        blocks[1]=sf::Vector2i(-1,0);
        blocks[2]=sf::Vector2i(1,0);
        blocks[3]=sf::Vector2i(2,0);
        col = sf::Color(0,255,255);
    }
}

Shape::~Shape()
{

}

bool Shape::canGoTo(sf::Vector2i newPos, sf::Color ** grid){
    for(int i=0;i<4;i++){
        if(newPos.x+blocks[i].x>=W||newPos.x+blocks[i].x<0)return 0;
        if(py<(float)blockSide*3/4 && (newPos.y+blocks[i].y<0||newPos.y+blocks[i].y>=H||grid[newPos.y+blocks[i].y][newPos.x+blocks[i].x]!=EMPTY))return 0;
        if(newPos.y+blocks[i].y+1<0||newPos.y+blocks[i].y+1>=H||grid[newPos.y+blocks[i].y+1][newPos.x+blocks[i].x]!=EMPTY)return 0;
    }
    return 1;
}

void Shape::placeBlock(sf::Color ** grid){
    for(int i=0;i<4;i++){
        grid[pos.y+blocks[i].y][pos.x+blocks[i].x]=col;
    }
}

void Shape::rot(sf::Color ** grid){
    for(int i=0;i<4;i++){
        int Px = (int)(pos.x - blocks[i].y);
        int Py = (int)(pos.y + blocks[i].x);

        if(Px>=W||Px<0)return;
        if(py<(float)blockSide*3/4 && (Py<0||Py>=H||grid[Py][Px]!=EMPTY))return;
        if(Py+1<0||Py+1>=H||grid[Py+1][Px]!=EMPTY)return;

    }
    for(int i=0;i<4;i++){
        blocks[i]=sf::Vector2i(-blocks[i].y,blocks[i].x);
    }
}

void Shape::draw(sf::RenderWindow& window){
    for(int i=0;i<4;i++){
        GameState::blockSprite.setPosition( (pos.x+blocks[i].x)*(float)blockSide,(pos.y+blocks[i].y)*(float)blockSide+py);
        GameState::blockSprite.setColor(col);
        window.draw(GameState::blockSprite);
    }
}

bool Shape::moveR(sf::Color ** grid){
    if(canGoTo(sf::Vector2i(pos.x+1,pos.y),grid)){
        pos.x++;
        return 1;
    } else
        return 0;
}

bool Shape::moveL(sf::Color ** grid){
    if(canGoTo(sf::Vector2i(pos.x-1,pos.y),grid)){
        pos.x--;
        return 1;
    } else
        return 0;
}

bool Shape::update(sf::Color ** grid){
    py+=vel;
    if(py>=blockSide){
        py-=blockSide;
        pos.y++;
        if(canGoTo(sf::Vector2i(pos),grid)){
            return 0;
        } else {
            placeBlock(grid);
            return 1;
        }
    }
    return 0;
}

