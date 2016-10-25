#ifndef FLAG_H
#define FLAG_H

#include "TwoVector.h"

class Flag
{
public:
	Flag();
	Flag(TwoVector& position);

	TwoVector getPosition() ;
	void setPosition( TwoVector& position);

	void resetPosition();

private:
	TwoVector fPosition;
};

#endif // FLAG_H
