/*
 * File: 7.8-DrawHouse.c
 * ---------------------
 * this program draws a house.
 */

#include <stdio.h>

#include "genlib.h"
#include "graphics.h"

 /*
  * Constants
  * ---------
  * The following constants control the sizes of the
  * various elements in the display.
  */

#define HouseWidth             1.5
#define HouseHeight            2.0
#define HouseArch              1.0

#define TowerWidth             0.4
#define TowerHeight            2.3
#define TowerArch              0.6

#define DoorWidth              0.3
#define DoorHeight             0.5
#define DoorArch               0.25

#define WindowLevel            1.4
#define WindowSize             0.3                              //0,3 error!

/* Function prototypes */

void DrawWholeHouse(double x, double y);
void DrawHouse(double x, double y);
void DrawTower(double x, double y);
void DrawDoor(double x, double y);
void DrawWindow(double x, double y);
void DrawBox(double x, double y, double width, double height);
void DrawTriangle(double x, double y, double base, double height);

/* main program */

main()
{
	double dx, dy;

	InitGraphics();
	dx = GetWindowHeight() / 2;
	dy = GetWindowHeight() / 2;
	DrawWholeHouse(dx - HouseWidth / 2 - TowerWidth,
		dy - (HouseHeight + HouseArch) / 2);
}

void DrawWholeHouse(double x, double y)
{
	DrawHouse(x, y);
	DrawTower(x, y);
	DrawDoor(x, y);
	DrawWindow(x, y);
}

void DrawHouse(double x, double y)
{
	DrawBox(x + TowerWidth, y, HouseWidth, HouseHeight);
	DrawTriangle(x + TowerWidth, y + HouseHeight, HouseWidth, HouseArch);
}

void DrawTower(double x, double y)
{
	DrawBox(x, y, TowerWidth, TowerHeight);
	DrawTriangle(x, y + TowerHeight, TowerWidth, TowerArch);
	DrawBox(x + TowerWidth + HouseWidth, y, TowerWidth, TowerHeight);
	DrawTriangle(x + TowerWidth + HouseWidth,
		y + TowerHeight, TowerWidth, TowerArch);
}

void DrawDoor(double x, double y)
{
	DrawBox(x + TowerWidth + (HouseWidth - DoorWidth) / 2, y,
		DoorWidth, DoorHeight);
}

void DrawWindow(double x, double y)
{
	DrawBox(x + TowerWidth + HouseWidth / 4 - WindowSize / 2,
		y + WindowLevel, WindowSize, WindowSize);
	DrawBox(x + TowerWidth + HouseWidth * 3 / 4 - WindowSize / 2,
		y + WindowLevel, WindowSize, WindowSize);
}

void DrawBox(double x, double y, double width, double height)
{
	MovePen(x, y);
	DrawLine(0, height);
	DrawLine(width, 0);
	DrawLine(0, -height);
	DrawLine(-width, 0);
}

void DrawTriangle(double x, double y, double base, double height)
{
	MovePen(x, y);
	DrawLine(base, 0);
	DrawLine(-base / 2, height);
	DrawLine(-base / 2, -height);
}
