/*
 * File: 8.13-DrawHouse.c
 * ----------------------
 * This program draws a simple frame house using an user-defined library.
 */

#include <stdio.h>

#include "genlib.h"
#include "graphics.h"
#include "gfigures.h"

/*
 * Constants
 * ---------
 * The following constants control the sizes of the
 * various elements in the display.
 */

#define HouseHeight         2.0
#define HouseWidth          3.0
#define AtticHeight         0.7

#define DoorWidth           0.4
#define DoorHeight          0.7
#define DoorknobRadius      0.03
#define DoorknobInset       0.07

#define PaneHeight          0.25
#define PaneWidth           0.2

#define FirstFloorWindows   0.3
#define SecondFloorWindows  1.25

/* Function prototypes */

void DrawHouse(double x, double y);
void DrawOutline(double x, double y);
void DrawWindows(double x, double y);
void DrawDoor(double x, double y);

/* Main program */

main()
{
	double cx, cy;

	InitGraphics();
	cx = GetWindowWidth() / 2;
	cy = GetWindowHeight() / 2;
	DrawHouse(cx - HouseWidth / 2,
		cy - (HouseHeight + AtticHeight) / 2);
}

/*
 * Function: DrawHouse
 * Usage: DrawHouse(x, y);
 * -----------------------
 * This function draws a house diagram with the lower left corner
 * at (x, y).  This level of the function merely divides up
 * the work.
 */

void DrawHouse(double x, double y)
{
	DrawOutline(x, y);
	DrawDoor(x + (HouseWidth - DoorWidth) / 2, y);
	DrawWindows(x, y);
}

/*
 * Function: DrawOutline
 * Usage: DrawOutline(x, y);
 * -------------------------
 * This function draws the outline for the house, using (x, y)
 * as the origin.  The outline consists of a box with a triangle
 * on top.
 */

void DrawOutline(double x, double y)
{
	DrawBox(x, y, HouseWidth, HouseHeight);
	DrawTriangle(x, y + HouseHeight, HouseWidth, AtticHeight);
}

/*
 * Function: DrawDoor
 * Usage: DrawDoor(x, y);
 * ----------------------
 * This function draws a door, with its doorknob.  As usual,
 * (x, y) specifies the lower left corner of the door.
 */

void DrawDoor(double x, double y)
{
	DrawBox(x, y, DoorWidth, DoorHeight);
	DrawCenteredCircle(x + DoorWidth - DoorknobInset,
		y + DoorHeight / 2, DoorknobRadius);
}

/*
 * Function: DrawWindows
 * Usage: DrawWindows(x, y);
 * -------------------------
 * This function draws all the windows for the house,
 * taking advantage of the fact that the windows are all
 * arranged in two-dimensional grids of equal-sized panes.
 * By calling the function DrawGrid, this implementation
 * can create all of the window structures using a single
 * tool.
 */

void DrawWindows(double x, double y)
{
	double xleft, xright;

	xleft = x + HouseWidth * 0.25;
	xright = x + HouseWidth * 0.75;
	DrawGrid(xleft - PaneWidth * 1.5, y + FirstFloorWindows,
		PaneWidth, PaneHeight, 3, 2);
	DrawGrid(xright - PaneWidth * 1.5, y + FirstFloorWindows,
		PaneWidth, PaneHeight, 3, 2);
	DrawGrid(xleft - PaneWidth, y + SecondFloorWindows,
		PaneWidth, PaneHeight, 2, 2);
	DrawGrid(xright - PaneWidth, y + SecondFloorWindows,
		PaneWidth, PaneHeight, 2, 2);
}
