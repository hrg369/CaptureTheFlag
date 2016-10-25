#ifndef TWOVECTOR_H
#define TWOVECTOR_H


class TwoVector
{
public:
	TwoVector();
	TwoVector(double x, double y);

	void setX(double x);
	double getX();

	void setY(double y);
	double getY();

	void setXY(double x, double y);

	TwoVector operator + (TwoVector &addition);
	TwoVector operator - ( TwoVector& addition);

	double mag();

private:
	double fX;
	double fY;
};



#endif // TWOVECTOR_H
