/*
 * File: 3.12-PrintTableOfVotes.c
 * ------------------------------
 * This program print the votes of each candidate;
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"


main()
{
	strings candidate;
	int votes;

	candidate = "Clinton";
	votes = 3372;
	printf("%-15.15s %4d\n", candidate, votes);

	candidate = "Brown";
	votes = 596;
	printf("%-15.15s %4d\n", candidate, votes);

	candidate = "Tsongas";
	votes = 209;
	printf("%-15.15s %4d\n", candidate, votes);

	candidate = "Other";
	votes = 74;
	printf("%-15.15s %4d\n", candidate, votes);
}