#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SFML/Graphics.hpp>
#include "Shape.h"

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
        static constexpr float blockSide = 16;
        static sf::Color ** grid;
        static sf::Color EMPTY;

    private:
};

#endif // GAMESTATE_H
