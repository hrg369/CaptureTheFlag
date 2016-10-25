#include <cmath>

#include "TwoVector.h"

TwoVector::TwoVector(){}

TwoVector::TwoVector(double x, double y)
{
	fX = x;
	fY = y;
}

double TwoVector::getX()
{
	return fX;
}

void TwoVector::setX(double x)
{
	fX = x;
}

double TwoVector::getY()
{
	return fY;
}

void TwoVector::setY(double y)
{
	fY = y;
}

void TwoVector::setXY(double x, double y)
{
	fX = x;
	fY = y;
}

double TwoVector::mag()
{
	return std::sqrt(fX*fX + fY*fY);
}

TwoVector TwoVector::operator +(TwoVector& addition)
{
	TwoVector tempVec;

	tempVec.fX = this->fX + addition.fX;
	tempVec.fY = this->fY + addition.fY;

	return tempVec;
}

TwoVector TwoVector::operator -(TwoVector &addition)
{
	TwoVector tempVec;

	tempVec.fX = this->fX - addition.fX;
	tempVec.fY = this->fY - addition.fY;

	return tempVec;
}
