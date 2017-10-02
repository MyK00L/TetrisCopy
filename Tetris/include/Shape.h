#ifndef SHAPE_H
#define SHAPE_H

#include <SFML/Graphics.hpp>

class Shape
{
    public:
        enum Shapes{I,T,S,Q};
        Shape(Shapes shape);
        virtual ~Shape();
        void rot();
        void draw(sf::RenderWindow& window);
        void moveR(sf::Color ** grid);
        void moveL(sf::Color ** grid);
        bool update(sf::Color ** grid );



    protected:

    private:
        sf::Vector2f blocks[4];
        sf::Vector2f pos;
        sf::Color col;
        static float vel;
};

#endif // SHAPE_H
