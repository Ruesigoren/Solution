/*
 * File: 11.8-Histogram.c
 * ----------------------
 * This program generates a histogram.
 */

#include <stdio.h>
#include "simpio.h"
#include "genlib.h"
#include "hist.h"

/*
 * Constants
 * ---------
 * MaxElements -- Maximum number of elements
 * Sentinel    -- Value used to terminate input
 */

#define MaxElements 250
#define Sentinel      0
#define Max         100
#define Min         0

/* main program */

main()
{
	int data[MaxElements];
	int n;

	SetDataNumber(MaxElements);
	SetMaxandMin(Max, Min);
	SetGroupNumber(5);
	SetGroupRange(0, 0, 15);
	SetGroupRange(1, 16, 39);
	SetGroupRange(2, 40, 59);
	SetGroupRange(3, 60, 79);
	SetGroupRange(4, 80, 100);

	n = GetIntegerArray(data, MaxElements, Sentinel);
	DataCount(data, n);
	FormatOutput();
}
