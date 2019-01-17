/*
 * File: 15.9-Polygon.c
 * --------------------
 * This program reads the input file and draw the polygons on the screen.
 */

#include <stdio.h>

#include "genlib.h"
#include "graphics.h"

/* constants */

#define FileName  "polygon.dat"

/* function prototypes */

void DrawLineTo(double x, double y);

/* main program */

main()
{
	FILE *infile;
	errno_t err;
	double x, y, ox, oy;
	int nscan;
	char termch;
	int flag = 1;

	err = fopen_s(&infile, FileName, "r");
	if (err) {
		printf("Can't open the file %s.  Try again.\n", FileName);
	}
	InitGraphics();
	while (TRUE) {
		nscan = fscanf_s(infile, "%*[(]%lf, %lf%*[)]%c", &x, &y, &termch, sizeof(char));
		if (nscan == EOF) {
			DrawLineTo(ox, oy);
			flag = 1;
			break;
		}
		if (nscan == 0) {
			fscanf_s(infile, "%c", &termch, sizeof(char));
			if (termch == '\n') {
				DrawLineTo(ox, oy);
				flag = 1;
				continue;
			}
		}
		else if (nscan != 3 || termch != '\n') {
			Error("Improper file format");
		}
		if (flag == 1) {
			ox = x;
			oy = y;
			MovePen(x, y);
		}
		else {
			DrawLineTo(x, y);
		}
		flag++;
	}
}

void DrawLineTo(double x, double y)
{
	DrawLine(x - GetCurrentX(), y - GetCurrentY());
}
