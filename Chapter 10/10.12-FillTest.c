/*
 * File: 10.12-FillTest.c
 * ----------------------
 * This program test the fill.h interface.
 */

#include <stdio.h>
#include <math.h>

#include "simpio.h"
#include "strlib.h"
#include "genlib.h"
#include "fill.h"

/* constants */

#define margin          55

/* function prototypes */

boolean IsPrime(int n);

/* main program */

main()
{
	strings prompt;

	prompt = "The primes between 0 and 200 are: ";
	printf("%s", prompt);
	SetCurrentPos(StringsLength(prompt) + 1);
	SetFillMargin(margin);
	PrintFilledString(IntegerToStrings(2));
	for (int i = 3; i < 200; i += 2) {
		if (IsPrime(i)) {
			if (i == 199) {
				printf("%s.\n", IntegerToStrings(199));
			}
			else {
				PrintFilledString(IntegerToStrings(i));
			}
		}
	}
}

boolean IsPrime(int n)
{
	int sqrtn;

	if (n <= 1) {
		return (FALSE);
	}
	if (n == 2) {
		return (TRUE);
	}
	if (n % 2 == 0) {
		return (FALSE);
	}
	sqrtn = sqrt(n) + 1;
	for (int i = 3; i <= sqrtn; i += 2) {
		if (n % i == 0) {
			return (FALSE);
		}
	}
	return (TRUE);
}
