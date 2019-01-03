/*
 * File: 11.1-SizeOf.c
 * -------------------
 * This programs displays the size of each types
 */

#include <stdio.h>

/* main program */

main()
{
	printf("Values of type char requires %d byte.\n", sizeof(char));
	printf("Values of type short requires %d bytes.\n", sizeof(short));
	printf("Values of type int requires %d bytes.\n", sizeof(int));
	printf("Values of type long requires %d bytes.\n", sizeof(long));
	printf("Values of type float requires %d bytes.\n", sizeof(float));
	printf("Values of type double requires %d bytes.\n", sizeof(double));
}
