#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SFML/Graphics.hpp>
#include <random>
#include "Shape.h"
#include "globals.h"

class GameState
{
    friend class Shape;
    public:
        GameState(sf::RenderWindow& window);
        GameState(GameState& o);
        virtual ~GameState();
        virtual void draw();
        virtual void update();

    protected:
        sf::RenderWindow& window;
        static sf::Texture blockTexture;
        static sf::Sprite blockSprite;
        static sf::Color ** grid;
        static std::mt19937 rng;

    private:
};

#endif // GAMESTATE_H
