/*
 * File: 6.3+6.4-IsPerfect.c
 * -------------------------
 * This program determines wheather a number is perfect number or not.
 */

#include <stdio.h>
#include "genlib.h"

boolean IsPerfect(int n);

main()
{
	int i;

	for (i = 1; i < 10000; i++) {
		if (IsPerfect(i)) {
			printf(" %d", i);
		}
	}
	printf("\n");
}

boolean IsPerfect(int n)
{
	int sum, limit, realdivisior;

	sum = 0;
	//limit = n;
	limit = n / 2 + 1;
	for (realdivisior = 1; realdivisior < limit; realdivisior++) {
		if (n % realdivisior == 0) {
			sum += realdivisior;
		}
	}
	if (sum == n) return TRUE;
	return FALSE;
}
