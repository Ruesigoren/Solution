/*
 * File: 7.7-DrawPumpkin.c
 * -----------------------
 * This program draws a halloween pumpkin.
 */

#include <stdio.h>
#include <math.h>

#include "graphics.h"

/* 
 * Constants 
 * ---------
 * The following constants control the sizes of the
 * various elements in the display.
 */

#define HeadRadius              1.0
#define StemWidth               0.1
#define StemHeight              0.15
#define EyeWidth                0.3
#define EyeHeight               0.2
#define NoseWidth               0.2
#define NoseHeight              0.2
#define NTeethPerRow            7
#define ToothWidth              0.083333
#define ToothHeight             0.15

 /* Function prototypes */

void DrawPumpkin(double x, double y);
void DrawHead(double x, double y);
void DrawStem(double x, double y);
void DrawEyes(double x, double y);
void DrawNose(double x, double y);
void DrawTeeth(double x, double y);
void DrawBox(double x, double y, double width, double height);
void DrawTriangle(double x, double y, double base, double height);
void DrawCenteredCircle(double x, double y, double r);
void DrawGrid(double x, double y, double width, double height,
	int columns, int rows);

/* main program */

main()
{
	double cx, cy;

	InitGraphics();
	cx = GetWindowWidth() / 2;
	cy = GetWindowHeight() / 2;
	DrawPumpkin(cx, cy);
}

void DrawPumpkin(double x, double y)
{
	DrawHead(x, y);
	DrawStem(x, y);
	DrawEyes(x, y);
	DrawNose(x, y);
	DrawTeeth(x, y);
}

void DrawHead(double x, double y)
{
	DrawCenteredCircle(x, y, HeadRadius);
}

void DrawStem(double x, double y)
{
	double dy;

	dy = sqrt(HeadRadius * HeadRadius - StemWidth * StemWidth / 4);
	MovePen(x - StemWidth / 2, y + dy);
	DrawLine(0, StemHeight);
	DrawLine(StemWidth, 0);
	DrawLine(0, -StemHeight);
}

void DrawEyes(double x, double y)
{
	DrawTriangle(x - HeadRadius / 2, y + HeadRadius / 2, 
		EyeWidth, -EyeHeight);
	DrawTriangle(x + HeadRadius / 2 - EyeWidth, y + HeadRadius / 2,
		EyeWidth, -EyeHeight);
}

void DrawNose(double x, double y)
{
	DrawTriangle(x - NoseWidth / 2, y - NoseHeight / 2, 
		NoseWidth, NoseHeight);
}

void DrawTeeth(double x, double y)
{
	DrawGrid(x - NTeethPerRow * ToothWidth / 2, y - HeadRadius / 2 - ToothHeight,
		ToothWidth, ToothHeight, NTeethPerRow, 2);
}

void DrawBox(double x, double y, double width, double height)
{
	MovePen(x, y);
	DrawLine(width, 0);
	DrawLine(0, height);
	DrawLine(-width, 0);
	DrawLine(0, -height);
}

/*
 * Function: DrawTriangle
 * Usage: DrawTriangle(x, y, base, height)
 * ---------------------------------------
 * This function draws an isosceles triangle (i.e., one with
 * two equal sides) with a horizontal base.  The coordinate of
 * the left endpoint of the base is (x, y), and the triangle
 * has the indicated base length and height.  If height is
 * positive, the triangle points upward.  If height is negative,
 * the triangle points downward.
 */

void DrawTriangle(double x, double y, double base, double height)
{
	MovePen(x, y);
	DrawLine(base, 0);
	DrawLine(-base / 2, height);
	DrawLine(-base / 2, -height);
}

/*
 * Function: DrawCenteredCircle
 * Usage: DrawCenteredCircle(x, y, r);
 * -----------------------------------
 * This function draws a circle of radius r with its
 * center at (x, y).
 */

void DrawCenteredCircle(double x, double y, double r)
{
	MovePen(x + r, y);
	DrawArc(r, 0, 360);
}

void DrawGrid(double x, double y, double width, double height,
	int columns, int rows)
{
	int i, j;

	MovePen(x, y);
	for (i = 0; i < columns; i++) {
		for (j = 0; j < rows; j++) {
			DrawBox(x + i * width, y + j * height,
				ToothWidth, ToothHeight);
		}
	}
}
