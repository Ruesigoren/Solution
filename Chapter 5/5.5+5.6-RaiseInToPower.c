/*
 * File: 5.5+5.6-RasiseInToPower.c
 * -------------------------------
 * This Program gets two integer n , k and show n to k power in a list.
 */

#include <stdio.h>

int RaiseInToPower(int n, int k);
double RaiseRealToPower(double n, int k);

main()
{
	int k;

	printf("This Program gets two integer n , k and show n to k power in a list.\n");
	printf("         k\n");
	printf(" k      2\n");
	printf("----------\n");
	for (k = 0; k <= 10; k++) {
		if (k < 10) printf(" ");
		printf("%d  %5d\n", k, RaiseInToPower(2, k));
	}
	printf("\n");
	printf("This Program gets float-point number n and integer k, and show n to k power in a list.\n");
	printf("         k\n");
	printf(" k     10\n");
	printf("-----------\n");
	for (k = -4; k < 0; k++) {
		printf("%d   %g\n", k, RaiseRealToPower(10, k));
	}
	for (k = 0; k <= 4; k++) {
		printf(" %d   %.1f\n", k, RaiseRealToPower(10, k));
	}
}

int RaiseInToPower(int n, int k)
{
	int Power = 1;

	for (; k > 0; k--) {
		Power *= n;
	}
	return Power;
}

double RaiseRealToPower(double n, int k)
{
	double Power = 1.0;

	if (k < 0) {
		k = -k;
		for (; k > 0; k--) {
			Power *= n;
		}
		Power = 1 / Power;
	}
	for (; k > 0; k--) {
		Power *= n;
	}
	return Power;
}
