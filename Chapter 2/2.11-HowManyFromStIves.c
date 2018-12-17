/*
 * File: 2.11-HowManyFromStIves.c
 * ------------------------------
 *   As I was going to St.Ives,
 *   I met a man with seven wives,
 *   Each wife had seven sacks,
 *   Each sack had seven cats,
 *   Each cat had seven kits:
 *   Kits, cats, sacks, and wives,
 *   How many were going to St.Ives?
 * This program finds out how many representatives of the assembled
 * multitude - kits, cats, sacks, and wives - were coming form St.Ives
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main()
{
	int sum;
	int man, wifives, sacks, cats, kits;

	printf("This program finds how many were coming from St.Ives.\n");
	man = 1;
	wifives = man * 7;
	sacks = wifives * 7;
	cats = sacks * 7;
	kits = cats * 7;
	sum = man + wifives + sacks + cats + kits;
	printf("The result is %d.\n", sum);
}