/*
 * File: 8.11-DrawRandomRoute.c
 * -----------------------
 * this program draws a random route to home.
 */

#include <stdio.h>

#include "random.h"
#include "genlib.h"
#include "graphics.h"

/* Constanst
 * ---------
 * MapWidth  -- must be an integral multiple of MapGridSize.
 * MapHeight -- must be an integral multiple of MapGridSize.
 */

#define MapStartX      1.0
#define MapStartY      1.0
#define MapWidth       14.0
#define MapHeight      9.0
#define MapGridSize    1.0

#define South          1
#define West           2

#define points         1.0/72

/* function prototypes */

int RandomDirection(void);
void DrawMap(double x, double y,
	double width, double height, double gridsize);
void DrawRandomRoute(double RouteStartX, double RouteStartY,
	double RouteEndX, double RouteEndY, double LengthOfStep);
void DrawSheetOfSquare(double x, double y, double widthofsquare,
	int columns, int rows);

/* main program */

main()
{
	Randomize();
	InitGraphics();
	DrawMap(MapStartX, MapStartY, MapWidth, MapHeight, MapGridSize);
}

void DrawMap(double x, double y, double width, double height, double gridsize)
{
	double routestartx, routestarty, routeendx, routeendy, lengthofstep;
	int columns, rows;

	columns = width / gridsize;
	rows = height / gridsize;
	routestartx = x + width;
	routestarty = y + height;
	routeendx = x;
	routeendy = y;
	lengthofstep = gridsize;
	DrawSheetOfSquare(x, y, gridsize, columns, rows);
	DrawRandomRoute(routestartx, routestarty, routeendx, routeendy, lengthofstep);
}

void DrawRandomRoute(double RouteStartX, double RouteStartY,
	double RouteEndX, double RouteEndY, double LengthOfStep)
{
	double x, y, dx, dy, ex, ey;

	x = RouteStartX;
	y = RouteStartY;
	ex = RouteEndX + LengthOfStep;
	ey = RouteEndY + LengthOfStep;
	dx = dy = LengthOfStep;
	MovePen(x, y);
	x = GetCurrentX();
	y = GetCurrentY();
	while (x >= ex  && y >= ey) {
		switch (RandomDirection()) {
		case  1:  
			MovePen(x + points, y);
			DrawLine(0, -1.0);
			MovePen(x - points, y);
			DrawLine(0, -1.0);
			MovePen(x, y);
			DrawLine(0, -1.0);
			y = GetCurrentY();
			break;
		case  2:
			MovePen(x, y + points);
			DrawLine(-1.0, 0);
			MovePen(x, y - points);
			DrawLine(-1.0, 0);
			MovePen(x, y);
			DrawLine(-1.0, 0);
			x = GetCurrentX();
			break;
		default:  break;
		}
	}
	while (TRUE) {
		x = GetCurrentX();
		y = GetCurrentY();
		if (x == 1.0) {
			while (y >= ey) {
				MovePen(x + points, y);
				DrawLine(0, -1.0);
				MovePen(x - points, y);
				DrawLine(0, -1.0);
				MovePen(x, y);
				DrawLine(0, -1.0);
				y = GetCurrentY();
			}
			break;
		}
		if (y == 1.0) {
			while (x >= ex) {
				MovePen(x, y + points);
				DrawLine(-1.0, 0);
				MovePen(x, y - points);
				DrawLine(-1.0, 0);
				MovePen(x, y);
				DrawLine(-1.0, 0);
				x = GetCurrentX();
			}
			break;
		}
	}
}

int RandomDirection(void)
{
	if (rand() > RAND_MAX / 2) {
		return South;
	}
	else {
		return West;
	}
}

void DrawSheetOfSquare(double x, double y, double widthofsquare,
	int columns, int rows)
{
	int i, j;
	double width, height, w;

	w = widthofsquare;
	width = columns * w;
	height = rows * w;
	for (i = 0; i <= columns; i++) {
		MovePen(x + i * w, y);
		DrawLine(0, height);
	}
	for (j = 0; j <= rows; j++) {
		MovePen(x, y + j * w);
		DrawLine(width, 0);
	}
}
