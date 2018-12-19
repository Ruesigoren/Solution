/*
 * File: 5.4-FibonacciSequence.c
 * -----------------------------
 * This program lists the Fibonacci sequence.
 *
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

/*
 * Constants:
 * ----------
 * ListLength -- The length of the list.
 */

#define ListLength  25

 /* Function prototypes */

long long int Fibonacci(int n);
void adjustdisplay(int currentindex, int lengthoflastindex);


main()
{
	int i, lastindex, lengthoflastindex = 0;

	lastindex = ListLength;
	while (lastindex > 0) {
		lastindex /= 10;
		lengthoflastindex++;
	}
	for (i = 1; i <= ListLength; i++) {
		adjustdisplay(i, lengthoflastindex);
		printf("F(%d) = %lld\n", i, Fibonacci(i));
	}
}

long long int Fibonacci(int n)
{
	int i, Fn, Fn1 = 0, Fn2 = 1;

	if (n == 1) Fn = Fn1;
	if (n == 2) Fn = Fn2;
	for (i = 2; i < n; i++) {
		Fn = Fn2 + Fn1;
		Fn1 = Fn2;
		Fn2 = Fn;
	}
	return Fn;
}

void adjustdisplay(int currentindex, int lengthoflastindex)
{
	int k, lengthofcurrentindex = 0;

	while (currentindex > 0) {
		currentindex /= 10;
		lengthofcurrentindex++;
	}
	for (k = 0; k < (lengthoflastindex - lengthofcurrentindex); k++) {
		printf(" ");
	}
}
