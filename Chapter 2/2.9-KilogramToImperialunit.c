/*
 * File: 2.9-KilogramToImperialunit.c
 * ----------------------------------
 * This program convert kilogram to imperial unit;
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main()
{
	double kilograms;
	int pounds, ounces;

	printf("This program convert kilogram to imperial unit.\n");
	printf("kilogram? ");
	kilograms = GetReal();
	pounds = kilograms * 2.2;  //double to int, using the truncation feature
	ounces = (kilograms * 2.2 - pounds) * 16;
	printf("%g kilogram equal to %d pound and %d ounce\n", kilograms, pounds, ounces);
}