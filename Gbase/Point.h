#pragma once
// Forward declaration
struct Rectangle;
// This class represents a Point with X & Y co-oridinates
struct Point
{
	float X;
	float Y;

	Point();

	Point(float X,float Y);

	Point& operator=(const Point &A);
	Point& operator=(float &A);
	Point(const Point& A);
	Point(const float& A);

	Point operator+ (Point A);
	Point operator- (Point A);
	Point operator/ (Point A);
	Point operator* (Point A);

	Point operator+= (Point A);
	Point operator-= (Point A);
	Point operator/= (Point A);
	Point operator*= (Point A);

	Point operator+ (float A);
	Point operator- (float A);
	Point operator/ (float A);
	Point operator* (float A);

	Point operator+= (float A);
	Point operator-= (float A);
	Point operator/= (float A);
	Point operator*= (float A);

	bool operator == (Point A);
};