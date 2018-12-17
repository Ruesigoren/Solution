/*
 * File: 3.14-FindTheLargestNumber.c
 * ---------------------------------
 * This program finds the largest integer in a list. 
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main()
{
	int value, max;

	printf("This program finds the largest integer in a list.\n");
	printf("Enter 0 to signal the end of the list.\n");
	printf("? ");
	value = GetInteger();
	max = value;
	while (value != 0) {
		printf("? ");
		value = GetInteger();
		/*
		if (value == 0) {
			break;
		}
		*/
		if (max < value) {
			max = value;
		}
	}
	printf("The largest value is %d\n", max);
}