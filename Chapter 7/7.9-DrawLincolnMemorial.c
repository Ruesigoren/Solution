/*
 * File: 7.9-DrawLincolnMemorial.c
 * -------------------------------
 * This program draws Lincoln memorial.
 */

#include <stdio.h>

#include "graphics.h"

/*
 * Constants
 * ---------
 * The following constants control the sizes of the
 * various elements in the display.
 */

#define MemorialWidth          4.0
#define PedestalHeight         0.3

#define NumberOfColumns        12
#define ColumnWidth            0.15
#define ColumnHeight           1.0

#define ColumnCircleRadius     0.05

#define LowerRoofHeight        0.3
#define UpperRoofWidth         3.5
#define UpperRoofHeight        0.3

#define StatusWidth            0.1
#define StatusHeight           0.2

 /* Function prototypes */

void DrawLincolnMemorial(double x, double y);
void DrawPedestal(double x, double y);
void DrawMemorial(double x, double y);
void DrawColumns(double x, double y);
void DrawStatus(double x, double y);
void DrawLowerRoof(double x, double y);
void DrawUpperRoof(double x, double y);
void DrawBox(double x, double y, double width, double height);
void DrawCenteredCircle(double x, double y, double r);

/* main program */

main()
{
	double dx, dy;

	InitGraphics();
	dx = GetWindowWidth() / 2;
	dy = GetWindowHeight() / 2;
	DrawLincolnMemorial(dx - MemorialWidth / 2,
		dy - (PedestalHeight + ColumnHeight + LowerRoofHeight + UpperRoofHeight) / 2);
}

void DrawLincolnMemorial(double x, double y)
{
	DrawPedestal(x, y);
	DrawMemorial(x, y + PedestalHeight);
	DrawLowerRoof(x, y + PedestalHeight + ColumnHeight);
	DrawUpperRoof(x + (MemorialWidth - UpperRoofWidth) / 2,
		y + PedestalHeight + ColumnHeight + LowerRoofHeight);
}

void DrawPedestal(double x, double y)
{
	DrawBox(x, y, MemorialWidth, PedestalHeight);
}

void DrawMemorial(double x, double y)
{
	DrawBox(x, y, MemorialWidth, ColumnHeight);
	DrawColumns(x, y);
	DrawStatus(x + (MemorialWidth - StatusWidth) / 2, y);
}

void DrawColumns(double x, double y)
{
	double SpaceBetweenColumns;

	SpaceBetweenColumns = (MemorialWidth - ColumnWidth) / (NumberOfColumns - 1);
	for (int i = 0; i < NumberOfColumns; i++) {
		DrawBox(x + i * SpaceBetweenColumns, y, ColumnWidth, ColumnHeight);
	}
}

void DrawStatus(double x, double y)
{
	DrawBox(x, y, StatusWidth, StatusHeight);
	DrawCenteredCircle(x + StatusWidth / 2,
		y + StatusHeight + ColumnCircleRadius, ColumnCircleRadius);
}

void DrawLowerRoof(double x, double y)
{
	double SpaceBetweenCricles;

	SpaceBetweenCricles = (MemorialWidth - ColumnWidth) / (NumberOfColumns - 1);
	DrawBox(x, y, MemorialWidth, LowerRoofHeight);
	for (int i = 0; i < NumberOfColumns; i++) {
		DrawCenteredCircle(x + ColumnWidth / 2 + i * SpaceBetweenCricles,
			y + LowerRoofHeight / 2, ColumnCircleRadius);
	}
}

void DrawUpperRoof(double x, double y)
{
	DrawBox(x, y, UpperRoofWidth, UpperRoofHeight);
}

void DrawBox(double x, double y, double width, double height)
{
	MovePen(x, y);
	DrawLine(0, height);
	DrawLine(width, 0);
	DrawLine(0, -height);
	DrawLine(-width, 0);
}

void DrawCenteredCircle(double x, double y, double r)
{
	MovePen(x + r, y);
	DrawArc(r, 0, 360);
}
