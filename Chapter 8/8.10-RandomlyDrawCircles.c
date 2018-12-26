/*
 * File: 8.10-RandomlyDrawCircles.c
 * --------------------------------
 * This program randomly draws 10 circles.
 */

#include <stdio.h>

#include "genlib.h"
#include "random.h"
#include "graphics.h"

/* Constants
 * ---------
 * these constans the radius of the circle.
 */

#define Low          0.05
#define High         0.5

/* function prototypes */

void RandowlyDrawCircle(void);
void DrawCenteredCircle(double x, double y, double r);
void DrawBox(double x, double y, double width, double height);
double GenerateX(double width);
double GenerateY(double height);
double GenerateR(void);

/* main program */

main()
{
	Randomize();
	InitGraphics();
	for (int i = 0; i < 10; i++) {
		RandowlyDrawCircle();
	}
}

void RandowlyDrawCircle(void)
{
	double width, height;
	double X, Y, R;
	double x, y, r;

	width = GetWindowWidth();
	height = GetWindowHeight();
	DrawBox(0, 0, width, height);
	while (TRUE) {
		X = GenerateX(width);
		Y = GenerateY(height);
		R = GenerateR();
		if ((X >= R) && (X <= (width - R))
			&& (Y >= R) && (Y <= (height - R))) {
			x = X;
			y = Y;
			r = R;
			break;
		}
	}
	DrawCenteredCircle(x, y, r);
}

void DrawCenteredCircle(double x, double y, double r)
{
	MovePen(x + r, y);
	DrawArc(r, 0, 360);
}

void DrawBox(double x, double y, double width, double height)
{
	MovePen(x, y);
	DrawLine(0, height);
	DrawLine(width, 0);
	DrawLine(0, -height);
	DrawLine(-width, 0);
}

double GenerateX(double width)
{
	return (RandomReal(0, width));
}

double GenerateY(double height)
{
	return (RandomReal(0, height));
}

double GenerateR(void)
{
	return (RandomReal(Low, High));
}
