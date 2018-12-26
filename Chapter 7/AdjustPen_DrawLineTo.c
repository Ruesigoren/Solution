/*
 * File: AdjustPen_DrawLineTo.c
 * ----------------------------
 * This file gives two function prototypes.
 */

#include <stdio.h>

#include "graphics.h"

/* function prototypes */

void AdjustPen(double dx, double dy);
void DrawLineTo(double x, double y);

/* main program*/

main()
{

}

/* 
 * Function:AdjustPen
 * Usage:AdjustPen(dx, dy);
 * ------------------------
 * This procedure adjusts the current point by moving it
 * dx inches from its current x coordinate and by inches
 * from its current y coordinate. As with MovePen, no
 * line is actually drawn.
 */

void AdjustPen(double dx, double dy)
{
	MovePen(GetCurrentX() + dx, GetCurrentY() + dy);
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