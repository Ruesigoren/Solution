/*
 * File: 8.6-RandomDarts.c
 * -----------------------
 * This program simulates throwing 10000 darts and then
 * use the simulation technique to generate and display
 * an apporximate value of Pi.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "genlib.h"
#include "random.h"

main()
{
	int i, j;
	double x, y;

	Randomize();
	for (i = 0, j = 0; i < 10000; i++) {
		x = RandomReal(-1.0, 1.0);
		y = RandomReal(-1.0, 1.0);
		if (sqrt(x * x + y * y) < 1.0) {
			j++;
		}
	}
	printf("The simulation value of Pi is %f\n", j / 2500.0);
}
