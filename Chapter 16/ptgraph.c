/*
 * File: ptgraph.c
 * Version: 1.0
 * Last modified on Thu Dec  6 09:06:11 2018 by kaltics
 * -----------------------------------------------------
 */

#include <stdio.h>
#include <math.h>

#include "genlib.h"
#include "graphics.h"
#include "ptgraph.h"


/* Public functions */

void MovePenToPoint(pointT pt)
{
	MovePen(pt.x, pt.y);
}


void DrawLineToPoint(pointT pt)
{
	DrawLine(pt.x - GetCurrentX(), pt.y - GetCurrentY());
}

pointT GetCurrentPoint(void)
{
	pointT pt;

	pt.x = GetCurrentX();
	pt.y = GetCurrentY();
	return pt;
}
