/*
 * File: 16.3+4-MidPoint.c
 * -----------------------
 * This program returns the midpoint of the line segment
 * between the points p1 and p2.
 */

#include <stdio.h>

#include "graphics.h"
#include "ptgraph.h"

/* types */

/*
typedef struct {
	double x, y;
} pointT;
*/

/* function prototypes */

pointT MidPoint(pointT p1, pointT p2);

/* main program */

main()
{
	pointT p1, p2;

	InitGraphics();
	p1.x = 1.0;
	p1.y = 1.5;
	MovePenToPoint(p1);
	p2.x = 2.0;
	p2.y = 3.0;
	DrawLineToPoint(p2);
	p1 = MidPoint(p1, p2);
	printf("x:%g y:%g\n", p1.x, p1.y);
}

pointT MidPoint(pointT p1, pointT p2)
{
	pointT p;

	p.x = (p1.x + p2.x) / 2.0;
	p.y = (p1.y + p2.y) / 2.0;
	return p;
}
