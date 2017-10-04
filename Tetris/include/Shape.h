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
        void moveR(sf::Color ** grid);
        void moveL(sf::Color ** grid);
        bool update(sf::Color ** grid );

        static float vel;

    protected:

    private:
        sf::Vector2f blocks[4];
        sf::Vector2f pos;
        sf::Color col;
};

#endif // SHAPE_H
