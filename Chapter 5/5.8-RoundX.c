/*
 * File: 5.7-RoundX.c
 * ------------------
 * This program rounds a float-point number to the nearest integer.
 */

#include <stdio.h>

/* function prototypes */

int RoundX(double x);

/* main program */

main()
{
	int i;
	double n;

	for (i = -100; i < 100; i += 11) {
		n = i / 10.0;
		printf("%-4.1f  %4d\n", n, RoundX(n));
	}
		
}

int RoundX(double x)
{
	int r;

	if (x < 0) {
		x -= 0.5;
		r = x / 1;  //use the truncation feature
	} else {
		x += 0.5;
		r = x / 1;
	}
	return r;
}
