#ifndef SHAPE_H
#define SHAPE_H

#include <SFML/Graphics.hpp>
#include "globals.h"

class Shape
{
    public:
        enum Shapes{O,S,Z,T,L,J,I,nShapes};
        Shape(Shapes shape);
        virtual ~Shape();
        void rot(sf::Color ** grid);
        void draw(sf::RenderWindow& window);
        bool moveR(sf::Color ** grid);
        bool moveL(sf::Color ** grid);
        bool update(sf::Color ** grid);

        static float vel;

    protected:

    private:

        bool canGoTo(sf::Vector2i newPos, sf::Color ** grid);
        void placeBlock(sf::Color ** grid);

        sf::Vector2i blocks[4];
        sf::Vector2i pos;
        float py;
        sf::Color col;
};

#endif // SHAPE_H
