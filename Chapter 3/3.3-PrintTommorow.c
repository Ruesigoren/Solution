/*
 * File£º3.3-PrintTommorow.c
 * -------------------------
 * This progra prints "Tommorow and tommorow and tommorow" on the screen.
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main()
{
	int i;

	printf("Tommorow");
	for (i = 0; i < 2; i++) {
		printf(" and tommorow");
	}
	printf(".\n");
}