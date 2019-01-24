/*
 * File: 17.1-Fib.c
 * ----------------
 * This is the recursive implementation for the function Fib(n)
 * that returns the nth Fibonacci number.
 */

#include <stdio.h>

#include "genlib.h"

/* function prototypes */

int Fib(int n);

/* main program */

main()
{
	int n;

	for (n = 0; n < 10; n++) {
		printf("%d ", Fib(n));
	}
}

int Fib(int n)
{
	if (n < 0) {
		Error("Illegal data");
	}
	else if (n < 2) {
		return n;
	}
	else {
		return Fib(n - 1) + Fib(n - 2);
	}
}
