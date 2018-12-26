/*
 * File: 7.4-DrawPeaceSymbol.c
 * ---------------------------
 * This program draws a peace symbol.
 */

#include <stdio.h>
#include <math.h>
#include "genlib.h"
#include "graphics.h"

/* function prototypes */

void DrawPeaceSymbol(double x, double y, double r);
void DrawCenteredCircle(double x, double y, double r);
void DrawSemaphoreCharacterN(double x, double y, double r);
void DrawSemaphoreCharacterD(double x, double y, double r);

/* main program */

main()
{
	double x ,y, r, dx;
	
	x = y = r = 1.0;
	InitGraphics();
	MovePen(x, y);
	DrawPeaceSymbol(x, y, r);
	
	/* test */

	for (int i = 0; i < 10; i++) {
		dx = 2 * r + 0.5;
		x += dx;
		r += 0.5;
		DrawPeaceSymbol(x, y, r);
	}
}

void DrawPeaceSymbol(double x, double y, double r)
{
	DrawCenteredCircle(x, y, r);
	DrawSemaphoreCharacterN(x, y, r);
	DrawSemaphoreCharacterD(x, y, r);
}

void DrawCenteredCircle(double x, double y, double r)
{
	MovePen(x + r, y);
	DrawArc(r, 0, 360);
}

void DrawSemaphoreCharacterN(double x, double y, double r)
{
	double dx, dy;

	dx = dy = sqrt(2.0) / 2 * r;
	MovePen(x, y);
	DrawLine(dx, -dy);
	MovePen(x, y);
	DrawLine(-dx, -dy);
}

void DrawSemaphoreCharacterD(double x, double y, double r)
{
	MovePen(x, y + r);
	DrawLine(0, -2 * r);
}
