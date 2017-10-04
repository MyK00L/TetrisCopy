#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "RunningGameState.h"
#include "globals.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(blockSide*W, blockSide*H), "Tetris");

    window.setFramerateLimit(30);

    GameState* game = new RunningGameState(window);
    sf::Color backgroundColor = sf::Color(32,32,64);

    sf::Music music;
    music.openFromFile("korobeiniki.ogg");
    music.setLoop(1);
    music.play();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        game->update();

        window.clear(backgroundColor);
        game->draw();
        window.display();
    }
    delete game;
    music.stop();
    return 0;
}
