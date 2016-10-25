#ifndef BOT_H
#define BOT_H

#include <string>


#include "TwoVector.h"
#include "Flag.h"
#include "Base.h"

class Bot
{
public:
	Bot();
	Bot(TwoVector& position);

	TwoVector& getPosition();
	void setPosition( TwoVector& position);

	TwoVector& getVelocity() ;
	void setVelocity( TwoVector& position);

	int getSpeed() ;
	void setSpeed(int speed);

	TwoVector& getTarget() ;
	void setTarget(std::string target);

	void update();

	Flag *getFlag();
	void setFlag(Flag *flag);

	Base *getBase();
	void setBase(Base *base);

	int getPoints();
	void setPoints(int points);

	void setHasFlag(bool flag);

private:
	TwoVector fPosition;
	TwoVector fVelocity;
	TwoVector fTarget;
	bool fHasFlag;
	int fSpeed;
	Flag* fFlag;
	Base* fBase;
	int fPoints;


};

#endif // BOT_H
