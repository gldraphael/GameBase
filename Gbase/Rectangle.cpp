#include "Rectangle.h"

Rectangle::Rectangle()
{
	X = Y = Width = Height =0;
}

Rectangle::Rectangle (float X,float Y,float Width,float Height)
{
	this->X = X;
	this->Y = Y;
	this->Width = Width;
	this ->Height = Height;
}

Rectangle::Rectangle (Point xy, float Width,float Height)
{
	this->X = xy.X;
	this->Y = xy.Y;
	this->Width = Width;
	this ->Height = Height;
}

Rectangle::Rectangle (Point xy, Point width_height)
{
	this->X = xy.X;
	this->Y = xy.Y;
	this->Width = width_height.X;
	this->Height = width_height.Y;
}

Rectangle::operator SDL_Rect()
{
	SDL_Rect myRect;
	myRect.x = static_cast<Sint16>(X);
	myRect.y = static_cast<Sint16>(Y);
	myRect.w = static_cast<Sint16>(Width);
	myRect.h = static_cast<Sint16>(Height);
	return myRect;
}

// Assignment & Copy ctors -------------------------
Rectangle & Rectangle::operator=(const Rectangle &A)
{
	X = A.X;
	Y = A.Y;
	Width = A.Width;
	Height = A.Height;
	return *this;
}

Rectangle& Rectangle::operator=(float &A)
{
	X = Y = Width = Height;
	return *this;
}

Rectangle::Rectangle(const Rectangle& A)
{
	X = A.X;
	Y = A.Y;
	Width = A.Width;
	Height = A.Height;
}

Rectangle::Rectangle(const float& A)
{
	X = Y = Width = Height;
}

// Operators-------------------------------
Rectangle Rectangle::operator+ (Rectangle A)
{
	return Rectangle ( X+A.X, Y+A.Y, Width+A.Width, Height+A.Height);
}

Rectangle Rectangle::operator- (Rectangle A)
{
	return Rectangle ( X-A.X, Y-A.Y, Width-A.Width, Height-A.Height);
}

Rectangle Rectangle::operator/ (Rectangle A)
{
	return Rectangle ( X/A.X, Y/A.Y, Width/A.Width, Height/A.Height);
}

Rectangle Rectangle::operator* (Rectangle A)
{
	return Rectangle ( X*A.X, Y*A.Y, Width*A.Width, Height*A.Height);
}

//-------------------------------------------
Rectangle Rectangle::operator+= (Rectangle A)
{
	*this = *this + A;
	return *this;
}

Rectangle Rectangle::operator-= (Rectangle A)
{
	*this = *this - A;
	return *this;
}

Rectangle Rectangle::operator/= (Rectangle A)
{
	*this = *this / A;
	return *this;
}

Rectangle Rectangle::operator*= (Rectangle A)
{
	*this = *this * A;
	return *this;
}

//---------------------------------------
Rectangle Rectangle::operator+ (float A)
{
	return Rectangle ( X+A, Y+A, Width+A, Height+A);
}

Rectangle Rectangle::operator- (float A)
{
	return Rectangle ( X-A, Y-A, Width-A, Height-A);
}

Rectangle Rectangle::operator/ (float A)
{
	return Rectangle ( X/A, Y/A, Width/A, Height/A);
}

Rectangle Rectangle::operator* (float A)
{
	return Rectangle ( X*A, Y*A, Width*A, Height*A);
}

// ----------------------------------------
Rectangle Rectangle::operator+= (float A)
{
	*this = *this + A;
	return *this;
}

Rectangle Rectangle::operator-= (float A)
{
	*this = *this - A;
	return *this;
}

Rectangle Rectangle::operator/= (float A)
{
	*this = *this / A;
	return *this;
}

Rectangle Rectangle::operator*= (float A)
{
	*this = *this * A;
	return *this;
}

bool Rectangle::Intersects (Rectangle A)
{
	return (*this)^A;
}

bool Rectangle::operator ^ (Rectangle A)
{

	/*if( 
	(this->Y + this->Height <= A.Y)
	|| (this->Y >= A.Y + A.Height)
	|| (this->X + this->Width <= A.X)
	|| (this->X >= A.X + A.Width)
	)
	return true;

	return false;*/

	bool isHorizontalCollision = false;

	// Check left edge of A
	if (this->X < A.X && A.X < this->X + this->Width)
	{
		isHorizontalCollision = true;
	}

	// Check right edge of A
	if (this->X < A.X + A.Width && A.X + A.Width < this->X + this->Width)
	{
		isHorizontalCollision = true;
	}

	bool isVerticalCollision = false;

	// Check top edge of A
	if (this->Y < A.Y && A.Y < this->Y + this->Height)
	{
		isVerticalCollision = true;
	}

	// Check bottom edge of A
	if (this->Y < A.Y + A.Height && A.Y + A.Height < this->Y + this->Height)
	{
		isVerticalCollision = false;
	}

	bool isContainsCollision  = true;

	if (! (isHorizontalCollision && isVerticalCollision))
	{
		if (A.X < this->X && this->X < A.X + A.Width )
		{
			if (A.Y < this->Y && this->Y < A.Y + A.Height)
			{
				isContainsCollision = true;
			}
		}
	}

	return ((isHorizontalCollision && isVerticalCollision) || isContainsCollision);
		// return true;
	// return false;
}