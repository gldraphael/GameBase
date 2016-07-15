#pragma once

#include "Point.h"

// Forward Declaration
//typedef struct SDL_rect SDL_rect;
#include <SDL_video.h>

//Represents a Rectangle
struct /*GCALL*/ Rectangle
{
	float X;
	float Y;
	float Width;
	float Height;

	Rectangle();

	Rectangle (float X,float Y,float Width,float Height);

	Rectangle (Point xy, float Width,float Height);
	Rectangle (Point xy, Point width_height);

	Rectangle& operator=(const Rectangle &A);
	Rectangle& operator=(float &A);
	Rectangle(const Rectangle& A);
	Rectangle(const float& A);

	Rectangle operator+ (Rectangle A);
	Rectangle operator- (Rectangle A);
	Rectangle operator/ (Rectangle A);
	Rectangle operator* (Rectangle A);

	Rectangle operator+= (Rectangle A);
	Rectangle operator-= (Rectangle A);
	Rectangle operator/= (Rectangle A);
	Rectangle operator*= (Rectangle A);

	Rectangle operator+ (float A);
	Rectangle operator- (float A);
	Rectangle operator/ (float A);
	Rectangle operator* (float A);

	Rectangle operator+= (float A);
	Rectangle operator-= (float A);
	Rectangle operator/= (float A);
	Rectangle operator*= (float A);

	// Checks if this rectangle intersects the rectangle A
	bool Intersects (Rectangle A);
	bool operator ^ (Rectangle A);

	operator SDL_Rect();
};