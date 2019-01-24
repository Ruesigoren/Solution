/*
 * File: 17.4-Towers of Hanoi.c
 * ----------------------------
 * This program displays the individual steps required
 * to transfer a tower of N disks from Tower A to Tower B.
 */

#include <stdio.h>

/* global variables */

int steps = 1;

/* function prototypes */

void Transfer(int n, char From, char To);
char Tmp(char From, char To);

/* main program */

main()
{
	int n = 8;	//8 disks
	char from = 'A';	//A tower
	char to = 'C';		//C tower

	Transfer(n, from, to);
}

void Transfer(int n, char From, char To)
{
	if (n == 1) {
		printf("Step %d: %c -> %c\n", steps, From, To);
		steps++;
	}
	else {
		Transfer(n - 1, From, Tmp(From, To));
		printf("Step %d: %c -> %c\n", steps, From, To);
		steps++;
		Transfer(n - 1, Tmp(From, To), To);
	}
}

/* find the left tower */
char Tmp(char From, char To)
{
	char Tower[] = "ABC";
	int i;

	for (i = 0; i < 3; i++) {
		if (Tower[i] != From && Tower[i] != To)
			return Tower[i];
	}
}
