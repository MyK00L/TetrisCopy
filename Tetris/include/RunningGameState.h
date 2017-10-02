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
};

#endif // RUNNINGGAMESTATE_H
