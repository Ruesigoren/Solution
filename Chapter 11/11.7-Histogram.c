/*
 * File: 11.7-Histogram.c
 * ----------------------
 * This program reads in an array of integers using GetIntegerArray and then
 * displays a histogram of those numbers, divided into the ranges 0-9, 10-19, 20-29,
 * and so for the, up to the range containing only the value 100.
 */

#include <stdio.h>
#include <ctype.h>

#include "simpio.h"
#include "strlib.h"
#include "genlib.h"

/* constants */

#define Ndata          100
#define Sentinel       0


/* private functions declararion */

static int GetIntegerArray(int array[], int max, int sentinel);
void printstars(int nstars);
void ClearIntegerArray(int array[], int n);

/* main program */

main()
{
	int count[11];
	int data[Ndata];
	int i, j, n;

	ClearIntegerArray(count, 11);
	n = GetIntegerArray(data, Ndata, Sentinel);
	for (i = 0; i < 11; i++) {
		for (j = 0; j < Ndata; j++) {
			if (data[j] / 10 == i) {
				count[i]++;
			}
		}
	}
	printf("0 - 9    |  ");
	if (count[0] != 0) {
		printstars(count[0]);
	}
	printf("\n");
	printf("10 - 19  |  ");
	if (count[1] != 0) {
		printstars(count[1]);
	}
	printf("\n");
	printf("20 - 29  |  ");
	if (count[2] != 0) {
		printstars(count[2]);
	}
	printf("\n");
	printf("30 - 39  |  ");
	if (count[3] != 0) {
		printstars(count[3]);
	}
	printf("\n");
	printf("40 - 49  |  ");
	if (count[4] != 0) {
		printstars(count[4]);
	}
	printf("\n");
	printf("50 - 59  |  ");
	if (count[5] != 0) {
		printstars(count[5]);
	}
	printf("\n");
	printf("60 - 69  |  ");
	if (count[6] != 0) {
		printstars(count[6]);
	}
	printf("\n");
	printf("70 - 79  |  ");
	if (count[7] != 0) {
		printstars(count[7]);
	}
	printf("\n");
	printf("80 - 89  |  ");
	if (count[8] != 0) {
		printstars(count[8]);
	}
	printf("\n");
	printf("90 - 99  |  ");
	if (count[9] != 0) {
		printstars(count[9]);
	}
	printf("\n");
	printf("100      |  ");
	if (count[10] != 0) {
		printstars(count[10]);
	}
	printf("\n");
}

static int GetIntegerArray(int array[], int max, int sentinel)
{
	int n, value;

	n = 0;
	while (TRUE) {
		printf("? ");
		value = GetInteger();
		if (value == sentinel) break;
		if (n == max) Error("Too many input items for array");
		n++;
		array[n] = value;
	}
	return (n);
}

void ClearIntegerArray(int array[], int n)
{
	int i;

	for (i = 0; i < n; i++) {
		array[i] = 0;
	}
}

void printstars(int nstars)
{
	int i;

	for (i = 0; i < nstars; i++) {
		printf("*");
	}
}
