#include "Base.h"

Base::Base(){}

Base::Base(TwoVector &position)
{
	fPosition = position;
}

TwoVector& Base::getPosition()
{
	return fPosition;
}

void Base::setPosition( TwoVector& position)
{
	fPosition = position;
}
