/*
 * File: 12.2-GuessNum.c
 * ---------------------
 * This program plays a number-guessing game with its user,
 * who is presumably an elementary-school child. The child thinks of a number and then
 * answers a series of questions from the computer until it correctly guesses the number.
 */

#include <stdio.h>

#include "simpio.h"
#include "genlib.h"
#include "strlib.h"

/* constants */

#define LH          1		//left hand
#define RH          100		//right hand

/* function prototypes */

int GuessNum(void);
boolean IsMid(int mid);
boolean IsLessThanMid(int mid);

/* main program */
main()
{
	int num;

	printf("Think of a number between 1 and 100 and I'll\n");
	printf("guess it.\n");
	num = GuessNum();
	if (num) {
		printf("I guessed the number! It's %d\n", num);
	}
	else {
		printf("The number you thought is out of range.\n");
	}
}

int GuessNum(void)
{
	int lh, rh, mid;

	lh = LH;
	rh = RH;
	while (lh <= rh) {
		mid = (lh + rh) / 2;
		if (IsMid(mid)) return (mid);
		if (IsLessThanMid(mid)) {
			rh = mid - 1;
		}
		else {
			lh = mid + 1;
		}
	}
	return (-1);
}

boolean IsMid(int mid)
{
	strings answer;
	
	while (TRUE) {
		printf("Is it %d? ", mid);
		answer = ConvertToLowerCase(GetLine());
		if (StringsEqual(answer, "yes")) {
			return (TRUE);
		}
		else if (StringsEqual(answer, "no")) {
			return (FALSE);
		}
		else {
			printf("Illegal ansewr! Please retry.\n");
		}
	}

}

boolean IsLessThanMid(int mid)
{
	strings answer;

	while (TRUE) {
		printf("Is it less than %d? ", mid);
		answer = ConvertToLowerCase(GetLine());
		if (StringsEqual(answer, "yes")) {
			return (TRUE);
		}
		else if (StringsEqual(answer, "no")) {
			return (FALSE);
		}
		else {
			printf("Illegal ansewr! Please retry.\n");
		}
	}
}
