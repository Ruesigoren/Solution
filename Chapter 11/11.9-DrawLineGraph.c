/*
 * File: 11.9-DrawLineGraph.c
 * --------------------------
 * This program generates a line graph given an array of x-coordinate values,
 * a second array of the corresponding y-coordinate values, and the number of data points..
 */

#include <stdio.h>

#include "simpio.h"
#include "graphics.h"

/* function prototypes */

void DrawLineGraph(double x[], double y[], double Npoints);
void DrawLineTo(double x, double y);

/* main program */

main()
{
	double xCoordinate[20] = { 0.0, 0.4, 0.8, 1.2, 1.6, 2.0, 2.4, 2.8, 3.2, 3.6 };
	double yCoordinate[20] = { 0.67, 0.68, 0.71, 0.86, 0.86, 1.04, 1.30, 1.81, 1.46, 1.86 };

	InitGraphics();
	DrawLineGraph(xCoordinate, yCoordinate, 10);
}

void  DrawLineGraph(double x[], double y[], double Npoints)
{
	int i;

	MovePen(x[0], y[0]);
	for (i = 1; i < Npoints; i++) {
		DrawLineTo(x[i], y[i]);
	}
}

/*
 * Function:DrawLineTo
 * Usage: DrawLineTo(x, y);
 * -----------------------
 * This function is like DrawLine, except it uses the
 * absolute coordinates of the endpoint rather than the relative
 * diaplacement from the current point.
 */

void DrawLineTo(double x, double y)
{
	DrawLine(x - GetCurrentX(), y - GetCurrentY());
}
