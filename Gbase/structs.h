#pragma once

#include "Rectangle.h"			// Includes Point.h
#include "Color.h"

//namespace GameBase
//{

	//The ViewPort
	struct /*GCALL*/ Viewport
	{
		int X;
		int Y;
		int Height;
		int Width;

		Viewport()
		{
			X = Y = Height = Width = 0;
		}

		Viewport(Rectangle bounds)
		{
			X = static_cast<int>(bounds.X);
			Y = static_cast<int>(bounds.Y);
			Height = static_cast<int>(bounds.Height);
			Width = static_cast<int>(bounds.Width);
		}

		Viewport(int x, int y, int width, int height)
		{
			X = (int)x;
			Y = (int)y;
			Height = (int)height;
			Width = (int)width;
		}
	};
//}