/*
 * File: 2.4+2.5-BankeBalance.c
 * ----------------------------
 * This program get starting balance and annual interest rate percentage 
 * and calculte the balance after one year.
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main()
{
	double balance, rate;
	int year;

	printf("Interest calculation program.\n");
	printf("Starting balance? ");
	balance = GetReal();
	printf("Annual interest rate percentage? ");
	rate = GetReal();
	printf("years? ");
	year = GetInteger();
	balance *= (1 + rate / 100);
	printf("Balance after one year: %g\n", balance);
	/*
	balance *= (1 + rate / 100);
	printf("Balance after two years: %g\n", balance);
	*/
}