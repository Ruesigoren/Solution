/*
 * File: 5.3-FahrenheitToCelsius.c
 * -------------------------------
 * This program illustrates the use of functions by generating
 * a table of Fahrenheit to Celsius conversions.
 */

#include <stdio.h>
#include "genlib.h"

/*
 * Constants
 * ---------
 * LowerLimit -- Starting value for temperature table
 * UpperLimit -- Final value for temperature table
 * StepSize   -- Step size between table entries
 */

#define LowerLimit   32
#define UpperLimit  100
#define StepSize      2

/* Function prototypes */

double FahrenheitToCelsius(double fahrenheit);

/* Main program */

main()
{
	int fahrenheit;

	printf("Fahrenheit to Celsius table.\n");
	printf("  F     C\n");
	for (fahrenheit = LowerLimit; fahrenheit <= UpperLimit; fahrenheit += StepSize) {
		printf("%3d  %4.1f\n", fahrenheit, FahrenheitToCelsius(fahrenheit));
	}
}

/*
 * Function: FahrenheitToCelsius
 * Usage: elsius = FahrenheitToCelsius(fahrenheit);
 * -----------------------------------------------
 * Returns the Celsius equivalent of the Fahrenheit
 * temperature fahrenheit.
 */

double FahrenheitToCelsius(double fahrenheit)
{
	return (fahrenheit - 32) * (5.0 / 9);
}
