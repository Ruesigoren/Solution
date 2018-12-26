/*
 * File: 7.6-DrawInitials.c
 * ------------------------
 * This program draws my initials on the graphics window.
 */

#include <stdio.h>

#include "graphics.h"

/* function prototypes */

void DrawCharacterP(double x, double y, double size);
void DrawCharacterX(double x, double y, double size);
void DrawCharacterK(double x, double y, double size);

/* main program */

main()
{
	InitGraphics();
	DrawCharacterP(1.0, 1.0, 1.0);
	DrawCharacterX(2.5, 1.0, 1.0);
	DrawCharacterK(4.0, 1.0, 1.0);
}

void DrawCharacterP(double x, double y, double size)
{
	MovePen(x, y);
	DrawLine(0, 3 * size);
	DrawArc(1 * size, 90, -180);
}

void DrawCharacterX(double x, double y, double size)
{
	MovePen(x, y);
	DrawLine(1 * size, 3 * size);
	MovePen(x, y + 3 * size);
	DrawLine(1 * size, -3 * size);
}

void DrawCharacterK(double x, double y, double size)
{
	MovePen(x, y);
	DrawLine(0, 3 * size);
	MovePen(x, y + 1.5 * size);
	DrawLine(1 * size, 1.5 * size);
	MovePen(x, y + 1.5 * size);
	DrawLine(1 * size, -1.5 * size);
}
