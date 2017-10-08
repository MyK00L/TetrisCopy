#ifndef RUNNINGGAMESTATE_H
#define RUNNINGGAMESTATE_H

#include "GameState.h"


class RunningGameState : public GameState
{
    public:
        RunningGameState(sf::RenderWindow& window, GameState*& game);
        RunningGameState(GameState& o);
        virtual ~RunningGameState();
        virtual void draw();
        virtual void update();

    protected:

    private:
        bool spacePressedLastFrame;
        sf::Clock moveClock;
        static constexpr int moveDelayMillis = 50;
};

#endif // RUNNINGGAMESTATE_H
