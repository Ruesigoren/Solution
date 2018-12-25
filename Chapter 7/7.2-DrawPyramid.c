/*
 * File: 7.2-DrawPyramid.c
 * -----------------------
 * This program draws a pyramid on the screen.
 */

#include <stdio.h>

#include "genlib.h"
#include "graphics.h"

/*
 * Constants
 * ---------
 * The following constants control the sizes of the
 * Bricks and the Prymaid.
 */

#define NBricksInBase       16
#define BrickWidth          1.0      
#define BrickHeight         0.5    

/* function prototypes */

void DrawPyramid(double x, double y);
void DrawBox(double x, double y, double width, double height);

/* main program */

main()
{
	double cx, cy;

	InitGraphics();
	cx = GetWindowWidth() / 2;
	cy = GetWindowHeight() / 2;
	DrawPyramid(cx - NBricksInBase / 2 * BrickWidth,
		cy - NBricksInBase / 2 * BrickHeight);

}

void DrawPyramid(double x, double y)
{
	int i, j, NBricks = NBricksInBase;

	for (i = 0; i < NBricksInBase; i++) {
		for (j = 0; j < NBricks; j++) {
			DrawBox(x + i * (BrickWidth / 2) + j * BrickWidth,
				y + i * BrickHeight, BrickWidth, BrickHeight);
		}
		NBricks--;
	}
}

void DrawBox(double x, double y, double width, double height)
{
	MovePen(x, y);
	DrawLine(0, height);
	DrawLine(width, 0);
	DrawLine(0, -height);
	DrawLine(-width, 0);
}