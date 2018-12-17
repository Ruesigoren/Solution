/*
 * File: 3.2-Print10Helloworld.c
 * -----------------------------
 * This program printf "Hello, world." in 10 rows.
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main()
{
	int i;
	int rows = 10;

	for (i = 0; i < rows; i++) {
		printf("hello, world.\n");
	}
}