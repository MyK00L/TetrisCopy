#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <random>
#include "Shape.h"
#include "globals.h"

class GameState
{
    friend class Shape;
    public:
        GameState(sf::RenderWindow& window, GameState*& game);
        GameState(GameState& o);
        virtual ~GameState();
        static void cleanup();
        virtual void draw();
        virtual void update();

    protected:
        sf::RenderWindow& window;
        GameState*& game;

        static sf::Texture blockTexture;
        static sf::Sprite blockSprite;

        static sf::Texture pausedTexture;
        static sf::Sprite pausedSprite;

        static sf::Font font;
        static sf::Text scoreText;

        static sf::Color ** grid;
        static Shape actShape;
        static int score;


        static std::mt19937 rng;

    private:
};

#endif // GAMESTATE_H
