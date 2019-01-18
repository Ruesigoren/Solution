/*
 * File: 16.5-AddRationals.c
 * -------------------------
 * This program adds a list of rational numbers.
 */

#include <stdio.h>

#include "rational.h"
#include "genlib.h"

/* constants */

#define MaxRational  100

/* main program */

main()
{
	ratioanlT r[MaxRational];
	ratioanlT total;
	int nRational;
	int i = 0;

	printf("This program adds a list of rational numbers.\n");
	printf("Signal end of list with a 0.\n");
	while (TRUE) {
		if (i == MaxRational) {
			printf("No more rational needed\n");
			break;
		}
		printf("? ");
		r[i] = GetRational();
		if (r[i].den == 0 && r[i].num == 0) {
			break;
		}
		else { 
			i++; 
		}
	}
	nRational = i;
	switch (nRational) {
	case 0: 
		printf("No rational input\n");
		break;
	case 1: 
		printf("The total is ");
		PrintRational(r[0]);
		break;
	default:
		total.den = r[0].den;
		total.num = r[0].num;
		for (i = 1; i < nRational; i++) {
			total = AddRational(total, r[i]);
		}
		printf("The total is ");
		PrintRational(total);
		break;
	}
	printf("\n");
}
