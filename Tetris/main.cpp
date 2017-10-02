#include <SFML/Graphics.hpp>

#include <RunningGameState.h>

int main()
{
    sf::RenderWindow window(sf::VideoMode(512, 512), "Tetris");

    window.setFramerateLimit(30);

    GameState* game = new RunningGameState(window);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        game->update();

        window.clear();
        game->draw();
        window.display();
    }

    return 0;
}
