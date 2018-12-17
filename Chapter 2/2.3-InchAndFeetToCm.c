/*
 * File: 2.3-InchAndFeetToCm.c
 * ---------------------------
 * This program converts from feet and inches to centimeters
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main()
{
	double inch, feet, cm;

	printf("This program converts from feet and inches to centimeters.\n");
	printf("Number of feet? ");
	feet = GetReal();
	printf("Number of inches? ");
	inch = GetReal();
	cm = (feet * 12 + inch) * 2.54;
	printf("The corresponding length is %g cm\n", cm);
}
