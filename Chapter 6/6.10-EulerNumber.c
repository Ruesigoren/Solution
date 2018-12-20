/*
 * File: 6.10-EulerNumber.c
 * ------------------------
 * This computes the value of e.
 */

#include <stdio.h>

int Factorial(int n);

main()
{
	double term, sum;

	sum = 0;
	term = 1;
	for (int i = 1; sum != sum + term; i++) {
		sum += term;
		term *= 1.0 / i;
		//term = 1.0 / Factorial(i);    //overflow
	}
	printf("Euler's number = %.10f\n", sum);
}

int Factorial(int n)
{
	int i,product = 1;

	for (i = 1; i <= n; i++) {
		product *= i;
	}
	return product;
}
