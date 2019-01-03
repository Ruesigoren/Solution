/*
 * File: hist.c
 * ------------
 * This file implements the hist.h interface.
 */

#include "simpio.h"
#include "genlib.h"
#include "strlib.h"
#include "hist.h"

 /* constants */

#define NData          400
#define NGroup         20

typedef enum rangelimit  {lower, upper} LimitT;

/*
 * Private variables
 * -----------------
 */

static int Ndata;
static int Max;
static int Min;
static int Ngroup;
static int Data[NData];
static int Grange[NGroup][2];
static int Count[NGroup];

void SetDataNumber(int ndata)
{
	Ndata = ndata;
	if (ndata > NData) Error("data seeting is out of range");
}

void SetMaxandMin(int max, int min)
{
	if (max <= min) Error("Illegal input! max >= min");
	Max = max;
	Min = min;
}

void SetGroupNumber(int ngroup)
{
	if (ngroup > NGroup) Error("group setting is out of range");
	Ngroup = ngroup;
}

void SetGroupRange(int group, int lowerlimit, int upperlimit)
{
	if (group > NGroup) Error("group is out of range");
	else if (group > Ngroup) Error("group is out of user defined");
	Grange[group][lower] = lowerlimit;
	Grange[group][upper] = upperlimit;

}

int GetIntegerArray(int array[], int max, int sentinel)
{
	int n, value;

	n = 0;
	if (max > Ndata) Error("max data number setting is out of range");
	while (TRUE) {
		printf("? ");
		value = GetInteger();
		while (value > Max || value < Min) {
			printf("Inputted data is out of range, please retry.\n");
			printf("?");
			value = GetInteger();
		}
		if (value == sentinel) break;
		if (n == max) {
			printf("No more data is needed");
			break;
		}
		n++;
		array[n] = value;
	}
	return (n);
}

void DataCount(int array[], int n)
{
	int i, j;

	ClearIntegerArray(Count, Ngroup);
	for (i = 0; i < Ngroup; i++) {
		for (j = 0; j < n; j++) {
			if (array[j] >= Grange[i][lower] &&
				array[j] <= Grange[i][upper]) {
				Count[i]++;
			}
		}
	}
}

void ClearIntegerArray(int array[], int n)
{
	int i;

	for (i = 0; i < n; i++) {
		array[i] = 0;
	}
}

void FormatOutput(void)
{
	strings ouputstream;
	int i;

	for (i = 0; i < Ngroup; i++) {
		ouputstream = Concat(Concat(IntegerToStrings(Grange[i][lower]), "-"), IntegerToStrings(Grange[i][upper]));
		printf("%-10s|", ouputstream);
		if (Count[i] != 0) {
			printstars(Count[i]);
		}
		printf("\n");
	}
}

void printstars(int nstars)
{
	int i;

	for (i = 0; i < nstars; i++) {
		printf("*");
	}
}