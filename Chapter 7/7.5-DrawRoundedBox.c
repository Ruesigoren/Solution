/*
 * File: 7.5-DrawRoundedBox.c
 * --------------------------
 * This program draws a rounded box.
 */

#include <stdio.h>

#include "graphics.h"

/* constants */

#define CornerRadius 0.2

/* function prototypes */

void DrawRoundedBox(double x, double y, double width, double height);

/* main program */

main()
{
	InitGraphics();
	DrawRoundedBox(1.0, 1.0, 1.0, 0.6);
}

void DrawRoundedBox(double x, double y, double width, double height)
{
	double dx, dy;

	dx = width - 2 * CornerRadius;
	dy = height - 2 * CornerRadius;
	MovePen(x, y + CornerRadius);
	DrawArc(CornerRadius, 180, 90);
	DrawLine(dx, 0);
	DrawArc(CornerRadius, 270, 90);
	DrawLine(0, dy);
	DrawArc(CornerRadius, 0, 90);
	DrawLine(-dx, 0);
	DrawArc(CornerRadius, 90, 90);
	DrawLine(0, -dy);
}
