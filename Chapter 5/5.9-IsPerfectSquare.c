/*
 * File: 5.9-IsPerfectSquare.c
 * ---------------------------
 * This Program determines wheather a integer is a perfect square number of not.
 */

#include <stdio.h>
#include <math.h>
#include "genlib.h"

boolean IsPerfectSquare(int n);

main()
{
	int i;

	for (i = 0; i < 1000; i++) {
		if (IsPerfectSquare(i)) {
			printf("%d\n", i);
		}
	}
}

boolean IsPerfectSquare(int n)
{
	int s;

	s = sqrt(n);  //type cast
	if (s * s == n) return TRUE;
	return FALSE;
}
