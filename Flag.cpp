#include <stdlib.h>
#include <time.h>

#include "Flag.h"

Flag::Flag()
{
    fPosition.setXY(0, 0);
}

Flag::Flag(TwoVector &position)
{
    fPosition = position;
}

 TwoVector Flag::getPosition()
{
    return fPosition;
}

void Flag::setPosition( TwoVector &position)
{
    fPosition = position;
}

void Flag::resetPosition()
{
    int randX = rand() % 100;
    int randY = rand() % 100;
    fPosition.setXY(randX, randY);
}
