/*
 * File: 7.11-DrawCheckerBoard.c
 * -----------------------------
 * this program draws a checkerboard.
 */

#include <stdio.h>

#include "graphics.h"

/*
 * Constants
 * ---------
 * The following constants control the shading seperation parameter.
 */

#define Points                    1.0/72
#define SizeOfCheckBoard          0.25

/* function prototypes */

void DrawCheckBoard(double x, double y, double size, int NumberOfPoints);
void DrawShadedBox(double x, double y, double width, double height, int NumberOfPoints);
void DrawShadow(double x, double y, double width, double height, int NumberOfPoints);
void DrawBox(double x, double y, double width, double height);
void DrawLineBetween(double x1, double y1, double x2, double y2);

/* main program */

main()
{
	InitGraphics();
	DrawCheckBoard(1.0, 1.0, SizeOfCheckBoard, 3);
}

void DrawCheckBoard(double x, double y, double size, int NumberOfPoints)
{
	int i, j;

	for (i = 0; i < 8; i++) {
		if (i % 2) {
			for (j = 0; j < 8; j++) {
				if (j % 2 == 0) {
					DrawBox(x + j * 0.25, y + i * 0.25, size, size);
				}
				else {
					DrawShadedBox(x + j * 0.25, y + i * 0.25, size, size, NumberOfPoints);
				}
			}
		}
		else {
			for (j = 0; j < 8; j++) {
				if (j % 2 == 0) {
					DrawShadedBox(x + j * 0.25, y + i * 0.25, size, size, NumberOfPoints);
				}
				else {
					DrawBox(x + j * 0.25, y + i * 0.25, size, size);
				}
			}
		}
	}
}

void DrawShadedBox(double x, double y, double width, double height, int NumberOfPoints)
{
	DrawBox(x, y, width, height);
	DrawShadow(x, y, width, height, NumberOfPoints);
}

void DrawShadow(double x, double y, double width, double height, int NumberOfPoints)
{
	double x1, y1, x2, y2;
	double distance;
	int i;

	distance = Points * NumberOfPoints;
	MovePen(x, y);
	x1 = x;
	y1 = y + height - distance;
	x2 = x + distance;
	y2 = y + height;
	if (width >= height) {
		for (i = 0; y1 >= y; i++) {
			DrawLineBetween(x, y1, x2, y + height);
			y1 -= distance;
			x2 += distance;
		}
		x1 = x + (y - y1);
		for (i = 0; x2 <= x + width; i++) {
			DrawLineBetween(x1, y, x2, y + height);
			x1 += distance;
			x2 += distance;
		}
		y2 = y + height - (x2 - x - width);
		for (i = 0; ; i++) {
			DrawLineBetween(x1, y, x + width, y2);
			x1 += distance;
			y2 -= distance;
			if ((x1 > x + width) || (y2 < y))
				break;
		}
	}
	else if (width < height) {
		for (i = 0; x2 <= x + width; i++) {
			DrawLineBetween(x, y1, x2, y + height);
			y1 -= distance;
			x2 += distance;
		}
		y2 = y + height - (x2 - x - width);
		for (i = 0; y1 >= y; i++) {
			DrawLineBetween(x, y1, x + width, y2);
			y1 -= distance;
			y2 -= distance;
		}
		x1 = x + (y - y1);
		for (i = 0; ; i++) {
			DrawLineBetween(x1, y, x + width, y2);
			x1 += distance;
			y2 -= distance;
			if ((x1 > x + width) || (y2 < y))
				break;
		}
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

void DrawLineBetween(double x1, double y1, double x2, double y2)
{
	MovePen(x1, y1);
	DrawLine(x2 - x1, y2 - y1);
}
