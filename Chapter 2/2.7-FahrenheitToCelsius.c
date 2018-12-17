/*
 * File: 2.7-FahrenheitToCelsius.c
 * -------------------------------
 * This program convert Fahrenheit to Celsius;
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main()
{
	double fahrenheit, celsius;

	printf("This program concert Fahrenheit to Celsius.\n");
	printf("Fahrenheit Temperature? ");
	fahrenheit = GetReal();
	celsius = (5.0 / 9) * (fahrenheit - 32);  //5.0 / 9
	printf("Celsius equivalent: %g\n", celsius);
}