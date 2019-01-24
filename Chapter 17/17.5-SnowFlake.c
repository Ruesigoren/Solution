/*
 * File: 17.5-SnowFlake.c
 * ----------------------
 * This program draws a Koch fractal snowflake.
 */

#include <stdio.h>
#include <math.h>

#include "genlib.h"
#include "graphics.h"

/* function prototypes */

void DrawSnowFlake(int order, double EdgeLength);
double *KochFlake(int order);
double *Fractal(double *theta, int n);
static void DrawPolarLine(double r, double theta);

/* main program */

main()
{
	InitGraphics();

	MovePen(GetWindowWidth() / 2, GetWindowHeight() / 2);
	DrawSnowFlake(3, 30);

	/*
	DrawPolarLine(6, 60);
	DrawPolarLine(6, -60);
	DrawPolarLine(6, 180);

	DrawPolarLine(2, 60);
	DrawPolarLine(2, 120);
	DrawPolarLine(2, 0);
	DrawPolarLine(2, 60);

	DrawPolarLine(2, -60);
	DrawPolarLine(2, 0);
	DrawPolarLine(2, -120);
	DrawPolarLine(2, -60);

	DrawPolarLine(2, 180);
	DrawPolarLine(2, -120);
	DrawPolarLine(2, 120);
	DrawPolarLine(2, 180);
	*/
}

void DrawSnowFlake(int order, double EdgeLength)
{
	double *theta;
	int i;
	int len;

	theta = KochFlake(order);
	len = 3 * pow(4, order);
	for (i = 0; i < len; i++) {
		DrawPolarLine(EdgeLength * pow(1.0 / 3, order), theta[i]);
	}
}

double *KochFlake(int order)
{
	double *theta;
	int len;

	if (order == 0) {
		theta = NewArray(3, double);
		theta[0] = 60;
		theta[1] = -60;
		theta[2] = 180;
		return theta;
	}
	else {
		len = 3 * pow(4, order - 1);
		theta = Fractal(KochFlake(order - 1), len);
		return theta;
	}
}

double *Fractal(double *theta, int n)
{
	int i, j;
	int len;
	double *NewTheta;

	len = n;
	NewTheta = NewArray(4 * len, double);
	for (i = 0, j = 0; i < len; i++, j += 4) {
		NewTheta[j] = theta[i];
		NewTheta[j + 1] = theta[i] + 60;
		NewTheta[j + 2] = theta[i] - 60;
		NewTheta[j + 3] = theta[i];
	}
	return NewTheta;
}

static void DrawPolarLine(double r, double theta)
{
	double radians;

	radians = theta / 180 * 3.1415926535;
	DrawLine(r * cos(radians), r * sin(radians));
}
