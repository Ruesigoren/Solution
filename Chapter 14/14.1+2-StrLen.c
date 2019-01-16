/*
 * File: 14.1+2-StrLen.c
 * ---------------------
 * This program is an implementation of strlen
 * that treats its argument as an array of characters.
 */

#include <stdio.h>

#include "strlib.h"

/* function prototypes */

int myStrlen(char array[]);
int myStrlenP(char *str);

/* main program */

main()
{
	char ch[] = { 'a', 'b', 'c', 'd', '\0' };
	//char ch[] = { 'a', 'b', 'c', 'd' };	//test
	strings str = "abcd";

	printf("The length of array ch is %d\n", myStrlen(ch));
	printf("The length of array ch is %d\n", myStrlenP(ch));
	printf("The length of array ch is %d\n", StringsLength(ch));
	printf("The length of array str is %d\n", myStrlen(str));
	printf("The length of array str is %d\n", myStrlenP(str));
	printf("The length of array str is %d\n", StringsLength(str));
}

int myStrlen(char array[])
{
	int i = 0;
	
	while (array[i] != '\0') {
		i++;
	}
	return (i);
}

int myStrlenP(char *str)
{
	int i = 0;

	while (*(str + i) != '\0') {
		i++;
	}
	return (i);
}
