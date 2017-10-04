#ifndef RUNNINGGAMESTATE_H
#define RUNNINGGAMESTATE_H

#include "GameState.h"


class RunningGameState : public GameState
{
    public:
        RunningGameState(sf::RenderWindow& window);
        RunningGameState(GameState& o);
        virtual ~RunningGameState();
        virtual void draw();
        virtual void update();

    protected:
        Shape actShape;
    private:
        bool spacePressedLastFrame;
        sf::Clock moveClock;
        static constexpr int moveDelayMillis = 50;
};

#endif // RUNNINGGAMESTATE_H
