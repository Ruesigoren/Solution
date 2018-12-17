/*
 * File: 2.8-MathemagicianProblem.c
 * --------------------------------
 * In Norton Juster＊s children＊s story The Phantom Tollbooth, the Mathemagician
 * gives Milo the following problem to solve:
 * 4 + 9 每 2 * 16 + 1 / 3 * 6 每67 + 8 * 2 每3 + 26 每 1 / 34 + 3 / 7 + 2 每 5
 * According to Milo＊s calculations, which are corroborated by the Mathemagican,
 * this expression all works out to zero.
 * Now this program finds the answer when Mathemagician＊s expression
 * were evaluated using C＊s precedence rules.
 */

#include <stdio.h>

main()
{
	int result;

	result = 4 + 9;
	result -= 2;
	result *= 16;
	result += 1;
	result /= 3;
	result *= 6;
	result -= 67;
	result += 8;
	result *= 2;
	result -= 3;
	result += 26;
	result -= 1;
	result /= 34;
	result += 3;
	result /= 7;
	result += 2;
	result -= 5;
	printf("Milo's answer: %d\n", result);
	result = 4 + 9 - 2 * 16 + 1 / 3 * 6 - 67 + 8 * 2 - 3 + 26 - 1 / 34 + 3 / 7 + 2 - 5;
	printf("C's answer: %d\n", result);
}