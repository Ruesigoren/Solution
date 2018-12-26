/*
 * File: DrawSheet.c
 * -----------------
 * this program draws a sheet.
 */

#include <stdio.h>

#include "random.h"
#include "graphics.h"

/* function prototypes */

void DrawSheet(double x, double y, double width, double height,
	int columns, int rows);

/* main program */

main()
{
	InitGraphics();
	DrawSheet(0.0, 0.0, 1.0, 1.0, 14, 9);
}

void DrawSheet(double x, double y, double width, double height,
	int columns, int rows)
{
	int i, j;
	double w, h;

	w = width / columns;
	h = height / rows;
	for (i = 0; i <= columns; i++) {
		MovePen(x + i * w, y);
		DrawLine(0, height);
	}
	for (j = 0; j <= rows; j++) {
		MovePen(x, y + j * h);
		DrawLine(width, 0);
	}
}
