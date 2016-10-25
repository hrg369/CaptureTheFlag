#include <cmath>
#include <iostream>

#include "Bot.h"

Bot::Bot()
{
	fPosition.setXY(0, 0);
	fVelocity.setXY(0, 0);
	fSpeed = 1;
	fHasFlag = false;
	fPoints = 0;
}

Bot::Bot(TwoVector &position)
{
	fPosition = position;
	fVelocity.setXY(0, 0);
	fSpeed = 1;
	fHasFlag = false;
	fPoints = 0;
}

TwoVector& Bot::getPosition()
{
	return fPosition;
}

void Bot::setPosition( TwoVector& position)
{
	fPosition = position;
}

TwoVector& Bot::getVelocity()
{
	return fVelocity;
}

void Bot::setVelocity( TwoVector& position)
{
	fVelocity = position;
}

int Bot::getSpeed()
{
	return fSpeed;
}

void Bot::setSpeed(int speed)
{
	fSpeed = speed;
}

TwoVector& Bot::getTarget()
{
	return fTarget;
}

// This needs to be called whenever the dynamic targets move, works fine for static targets
void Bot::setTarget(std::string target)
{
	if(target.compare("flag") == 0)
	{
		fTarget = getFlag()->getPosition();

		TwoVector velocity = getFlag()->getPosition() - fPosition;
		double magVelocity = velocity.mag();

		velocity.setXY(velocity.getX()*fSpeed/magVelocity, velocity.getY()*fSpeed/magVelocity);
		fVelocity = velocity;
	}
	else if(target.compare("base") == 0)
	{
		fTarget = getBase()->getPosition();

		TwoVector velocity = getBase()->getPosition() - fPosition;
		double magVelocity = velocity.mag();

		velocity.setXY(velocity.getX()*fSpeed/magVelocity, velocity.getY()*fSpeed/magVelocity);
		fVelocity = velocity;
	}
}

Flag *Bot::getFlag()
{
	return fFlag;
}

void Bot::setFlag(Flag *flag)
{
	fFlag = flag;
}

Base *Bot::getBase()
{
	return fBase;
}

void Bot::setBase(Base *base)
{
	fBase = base;
}

int Bot::getPoints()
{
	return fPoints;
}

void Bot::setPoints(int points)
{
	fPoints = points;
}

void Bot::setHasFlag(bool flag)
{
	fHasFlag = flag;
}

void Bot::update()
{
	fPosition = fPosition + fVelocity;
	if(fHasFlag)
	{
		fFlag->setPosition(fPosition);
		if(std::abs(fBase->getPosition().getX() - fPosition.getX()) < 0.5 && std::abs(fBase->getPosition().getY() - fPosition.getY()) < 0.5)
		{
			fVelocity.setXY(0, 0);
			getFlag()->resetPosition();
			setHasFlag(false);
			setTarget("flag");
			fPoints++;
			std::cout << "\nSCORE!!!\n";
		}
	}
	if(!fHasFlag && std::abs(fFlag->getPosition().getX() - fPosition.getX()) < 0.5 && std::abs(fFlag->getPosition().getY() - fPosition.getY()) < 0.5)
	{
		setHasFlag(true);
		setTarget("base");
	}
}
