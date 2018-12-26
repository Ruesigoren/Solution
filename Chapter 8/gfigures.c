/*
 * File: gfigures.c
 * ----------------
 * Program to draw a centered box.
 */

#include <stdio.h>

#include "graphics.h"
#include "gfigures.h"

 /*
  * Function: DrawBox
  * Usage: DrawBox(x, y, width, height)
  * -----------------------------------
  * This function draws a rectangle of the given width and
  * height with its lower left corner at (x, y).
  */

void DrawBox(double x, double y, double width, double height)
{
	MovePen(x, y);
	DrawLine(0, height);
	DrawLine(width, 0);
	DrawLine(0, -height);
	DrawLine(-width, 0);
}

/*
 * Function: DrawCenteredBox
 * Usage: DrawCenteredBox(x, y, width, height)
 * -------------------------------------------
 * This function draws a rectangle of the given width and
 * height with its center at (x, y).
 */

void DrawCenteredBox(double x, double y,
	double width, double height)
{
	DrawBox(x - width / 2, y - height / 2, width, height);
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

/*
 * Function: DrawGrid
 * Usage: DrawGrid(x, y, width, height, columns, rows);
 * ----------------------------------------------------
 * DrawGrid draws rectangles arranged in a two-dimensional
 * grid.  As always, (x, y) specifies the lower left corner
 * of the figure.
 */

void DrawGrid(double x, double y, double width, double height,
	int columns, int rows)
{
	int i, j;

	for (i = 0; i < columns; i++) {
		for (j = 0; j < rows; j++) {
			DrawBox(x + i * width, y + j * height,
				width, height);
		}
	}
}
