/*
 * File: 11.10-Probablilityboard.c
 * -------------------------------
 * This program simulate the operation of dropping 50 marbles into a probability board
 * with 10 channels along the bottom.
 */

#include <stdio.h>
#include <time.h>

#include "simpio.h"
#include "graphics.h"
#include "random.h"

/* constants */

#define Ntimes              50
#define Radcircle          0.5
#define Diacylinder        2.0
#define RadSmallcircle     0.2
#define HeightSmallCircle  1.0

/* variables */

typedef enum dirselection {left, right} dirT;

/* function prototypes */

void ClearIntegerArray(int array[], int n);
void PlinkoResult(int result[]);
int Randomselect(void);
void DrawPlinko(void);
void DrawResult(int result[], int n);
void DrawLineTo(double x, double y);
void DrawNcircle(int index, int number);
void DrawCenteredCircle(double x, double y, double r);

/* main program */

main()
{
	int i;
	int result[10];
	long start, finish;
	double elapsed;

	start = clock();
	ClearIntegerArray(result, 10);
	Randomize();
	InitGraphics();
	DrawPlinko();
	for (i = 0; i < Ntimes; i++) {
		PlinkoResult(result);
	}
	DrawResult(result, 10);
	finish = clock();
	elapsed = (double) (finish - start) / CLOCKS_PER_SEC;
	printf("runtime: %g ms\n", elapsed * 1000);
}

void ClearIntegerArray(int array[], int n)
{
	int i;

	for (i = 0; i < n; i++) {
		array[i] = 0;
	}
}

void PlinkoResult(int result[])
{
	int selection[10];
	int sum = 0;
	int i;

	for (i = 0; i < 10; i++) {
		selection[i] = Randomselect();
	}
	for (i = 0; i < 10; i++) {
		sum += selection[i];
	}
	result[sum]++;
}

int Randomselect(void)
{
	if (rand() <= RAND_MAX / 2) {
		return (left);
	}
	else {
		return (right);
	}
}

void DrawPlinko(void)
{
	double width, height;
	int Nsmallcircle = 9;
	int i, j;

	width = 10 * Diacylinder;
	height = 50 * Radcircle;
	MovePen(0, 0);
	DrawLine(width, 0);
	for (i = 0; i < 11; i++) {
		MovePen(i * Diacylinder, 0);
		DrawLine(0, height);
	}
	for (i = 0; i < 9; i++) {
		for (j = 0; j < Nsmallcircle; j++) {
			DrawCenteredCircle(Diacylinder + i * Diacylinder / 2 + j * Diacylinder,
				height + RadSmallcircle + i * HeightSmallCircle, RadSmallcircle);
		}
		Nsmallcircle--;
	}
	MovePen(0, height);
	DrawArc(width / 2, 180, -85);
	DrawLineTo(0, height);
	MovePen(width, height);
	DrawArc(width / 2, 0, 85);
	DrawLineTo(width, height);
}

void DrawLineTo(double x, double y)
{
	DrawLine(x - GetCurrentX(), y - GetCurrentY());
}

void DrawResult(int result[], int n)
{
	int i;

	for (i = 0; i < n; i++) {
		DrawNcircle(i, result[i]);
	}
}

void DrawNcircle(int index, int number)
{
	int i;

	for (i = 0; i < number; i++) {
		DrawCenteredCircle(index * Diacylinder + Diacylinder / 2,
			i * 2 * Radcircle + Radcircle, Radcircle);
	}
}

void DrawCenteredCircle(double x, double y, double r)
{
	MovePen(x + r, y);
	DrawArc(r, 0, 360);
}
