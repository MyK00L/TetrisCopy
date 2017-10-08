#ifndef PAUSEDGAMESTATE_H
#define PAUSEDGAMESTATE_H

#include "GameState.h"


class PausedGameState : public GameState
{
    public:
        PausedGameState(GameState& o);
        virtual ~PausedGameState();
        virtual void draw();
        virtual void update();

    protected:

    private:
};

#endif // PAUSEDGAMESTATE_H
