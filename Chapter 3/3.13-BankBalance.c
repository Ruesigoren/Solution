/*
 * File: 3.13-BankeBalance.c
 * -------------------------
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
	for (int i = 0; i < year; i++) {
		balance *= (1 + rate / 100);
	}
	printf("Balance after %d year: %g\n", year, balance);
}