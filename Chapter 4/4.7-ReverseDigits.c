/*
 * File: 4.7-ReverseDigits.c
 * -------------------------
 * This program generates the number that has the same digits in the reverse order.
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main()
{
	int n, reverse = 0;

	printf("This program  inverts an  integer.\n");
	printf("Enter a positive integer: ");
	n = GetInteger();
	while (n > 0) {
		reverse += n % 10;
		n /= 10;
		if (n == 0) break;
		reverse *= 10;
	}
	printf("The inverted integer is %d\n", reverse);
}
