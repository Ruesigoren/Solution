/*
 * File: 6.3+6.4-IsPerfect.c
 * -------------------------
 * This program determines wheather a number is perfect number or not.
 */

#include <stdio.h>
#include <math.h>
#include "genlib.h"

/* function prototypes*/

boolean IsPerfect(int n);
void GeneratePerfect(void);
boolean IsPrime(long long int n);

main()
{
	int i;

	for (i = 1; i < 10000; i++) {
		if (IsPerfect(i)) {
			printf("%d\n", i);
		}
	}

	/* 6.4 */
	//GeneratePerfect();
}

/* 6.3 */
boolean IsPerfect(int n)
{
	int sum, limit, properfactor;

	if(n % 2) return FALSE;		//odds are not perfect number, at least when they were not marvelously large.
	sum = 0;
	limit = n / 2 + 1;
	for (properfactor = 1; properfactor < limit; properfactor++) {
		if (n % properfactor == 0) {
			sum += properfactor;
		}
	}
	if (sum == n) return TRUE;
	return FALSE;
}

/* 6.4 */
//It's better to generate perfect numbers rather than to find them.
//because integer increment is really slow, and perfect numbers are to rare to be reached.
void GeneratePerfect(void)
{
	long long int Pn, Mp = 3;		//Pn: Perfect number
									//Mp: Mersenne prime
	int i = 2;

	while (Mp <= INT_MAX) {
		Mp = pow(2, i) - 1;
		if (IsPrime(Mp)) {
			Pn = Mp * (Mp + 1) / 2;
			printf("%lld\n", Pn);
		}
		i++;
	}
}

boolean IsPrime(long long int n)
{
	long long int i, limit;

	//if (n <= 1) return (FALSE);	//here, n always greater than 2
	//if (n == 2) return (TRUE);
	if (n % 2 == 0) return (FALSE);
	limit = sqrt(n) + 1;
	for (i = 3; i <= limit; i += 2) {
		if (n % i == 0) return FALSE;
	}
	return TRUE;
}
