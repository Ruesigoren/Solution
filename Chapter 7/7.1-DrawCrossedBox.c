/*
 * File: 7.2-DrawCrossedBox.c
 * --------------------------
 * This program draws a box with crossed line on the screen.
 */

#include <stdio.h>

#include "genlib.h"
#include "graphics.h"

/* function prototypes */

void DrawCrossedBox(double x, double y, double width, double height);

/* main program */

main()
{
	InitGraphics();
	DrawCrossedBox(0.5, 0.5, 1.0, 0.5);
}

void DrawCrossedBox(double x, double y, double width, double height)
{
	MovePen(x, y);
	DrawLine(0, height);
	DrawLine(width, 0);
	DrawLine(0, -height);
	DrawLine(-width, 0);
	DrawLine(width, height);
	MovePen(x, y + height);
	DrawLine(width, -height);
}