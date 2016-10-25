#ifndef BASE_H
#define BASE_H

#include "TwoVector.h"

class Base
{
public:
    Base();
    Base(TwoVector& position);
     TwoVector& getPosition() ;
    void setPosition( TwoVector& position);
private:
    TwoVector fPosition;
};

#endif // BASE_H
