#include "RunningGameState.h"
#include "globals.h"
#include <SFML/Audio.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(blockSide*W, blockSide*H), "Tetris");

    window.setFramerateLimit(30);

    sf::Music music;
    music.openFromFile("korobeiniki.ogg");
    music.setLoop(1);
    music.play();

    GameState* game;
    game = new RunningGameState(window, game);

    sf::Color backgroundColor = sf::Color(32,32,64);

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
    game->cleanup();
    delete game;
    music.stop();
    return 0;
}
