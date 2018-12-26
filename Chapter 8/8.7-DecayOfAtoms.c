/*
 * File: 8.7-DecayOfAtoms.c
 * ------------------------
 * This program simulates the decay of a sample that
 * contains 10000 atoms of radioactive material.
 */

#include <stdio.h>
#include "genlib.h"
#include "random.h"

main()
{
	int i, j, year, NumberOfAtoms;

	printf("Year    Atoms left\n");
	printf("----    ----------\n");
	Randomize();
	j = 0;
	year = 0;
	NumberOfAtoms = 10000;
	while (NumberOfAtoms > 0) {
		NumberOfAtoms = 10000 - j;
		printf("%4d    %10d\n", year, NumberOfAtoms);
		for (i = 0; i < NumberOfAtoms; i++) {
			if (rand() < RAND_MAX / 2) {
				j++;
			}
		}
		year++;
	}
}