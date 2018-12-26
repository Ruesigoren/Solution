/*
 * File: 7.3-DrawHeart.c
 * ---------------------
 * This program draws a heart on the screen.
 */

#include <stdio.h>
#include <math.h>

#include "graphics.h"

/* function prototypes */

void DrawHeart(double x, double y, double size);

/* main program*/

main()
{
	double cx, cy;
	double size = 10.0;

	InitGraphics();
	cx = GetWindowWidth();
	cy = GetWindowHeight();
	DrawHeart(cx / 2, cy / 2 - size, size);
}

void DrawHeart(double x, double y, double size)
{
	double radius;

	radius = sqrt(2.0) * size / 2;
	MovePen(x, y);
	DrawLine(size, size);
	//MovePen(x + radius + size / 2, y + 1.5 * size);    //wrong!
	DrawArc(radius, -45, 180);
	//MovePen(x - size / 2 + radius, y + 1.5 * size);
	DrawArc(radius, 45, 180);
	DrawLine(size, -size);
}
