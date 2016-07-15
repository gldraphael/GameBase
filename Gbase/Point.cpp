#include "Point.h"
#include "Rectangle.h"

Point::Point()
{
	X = Y = 0;
}

Point::Point(const Point& A)
{
	X = A.X;
	Y = A.Y;
}

Point& Point::operator=(const Point &A)
{
	X = A.X;
	Y = A.Y;
	return *this;
}

Point& Point::operator=(float &A)
{
	X = Y = A;
	return *this;
}

Point::Point(float X,float Y)
{
	this->X = X;
	this->Y = Y;
}

Point::Point(const float& A)
{
	X = Y = A;
}

Point Point::operator+ (Point A)
{
	return Point(X+A.X,Y+A.Y);
}

Point Point::operator- (Point A)
{
	return Point( X-A.X, Y-A.Y );
}

Point Point::operator/ (Point A)
{
	return Point( X/A.X, Y/A.Y );
}

Point Point::operator* (Point A)
{
	return Point( X*A.X, Y*A.Y );
}



//--------------------------------
Point Point::operator+= (Point A)
{
	*this = *this + A;
	return *this;
}

Point Point::operator-= (Point A)
{
	*this = *this - A;
	return *this;
}

Point Point::operator/= (Point A)
{
	*this = *this / A;
	return *this;
}

Point Point::operator*= (Point A)
{
	*this = *this * A;
	return *this;
}



//--------------------------------
Point Point::operator+ (float A)
{
	return Point(X + A, Y + A);
}

Point Point::operator- (float A)
{
	return Point(X - A, Y - A);
}

Point Point::operator/ (float A)
{
	return Point(X / A, Y / A);
}

Point Point::operator* (float A)
{
	return Point(X * A, Y * A);
}

//------------------------------
Point Point::operator+= (float A)
{
	*this = *this + A;
	return *this;
}

Point Point::operator-= (float A)
{
	*this = *this - A;
	return *this;
}

Point Point::operator/= (float A)
{
	*this = *this / A;
	return *this;
}

Point Point::operator*= (float A)
{
	*this = *this * A;
	return *this;
}

bool Point::operator == (Point A)
{
	return this->X == A.X && this->Y == A.Y;
}