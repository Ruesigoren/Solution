/*
 * File: 14.3-StrCmp.c
 * -------------------
 * This program is an implementation of the function strcmp
 * that works directly with the underlying representation of
 * its argument and calls no other functions.
 */

#include <stdio.h>
#include <string.h>

#include "strlib.h"

/* function prototypes */

int myStrcmp(strings s1, strings s2);
int myStrcmpP(char *s1, char *s2);

/* main program */

main()
{
	strings s1 = "ABCDE";
	strings s2 = "AdCD";

	printf("%d\n", myStrcmp(s1, s2));
	printf("%d\n", myStrcmpP(s1, s2));
	printf("%d\n", strcmp(s1, s2));
}

int myStrcmp(strings s1, strings s2)
{
	int i;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
		if (s1[i] > s2[i]) {
			return (1);
		}
		else if (s1[i] < s2[i]) {
			return (-1);
		}
		else {
			continue;
		}
	}
	if (s1[i] == '\0' && s2[i] != '\0') {
		return (-1);

	}
	else if (s1[i] != '\0' && s2[i] == '\0') {
		return (1);
	}
	else {
		return (0);
	}
}

int myStrcmpP(char *s1, char *s2)  //Use pointer of tyep char, not pointer of type string
{
	for (; *s1 != '\0' && *s2 != '\0'; s1++, s2++) {
		printf("s1 %c s2 %c\n", *s1, *s2);	//test
		if (*s1 > *s2) {
			return (1);
		}
		else if(*s1 < *s2) {
			return (-1);
		}
		else {
			continue;
		}
	}
	if (*s1 == '\0' && *s2 != '\0') {
		return (-1);

	}
	else if (*s1 != '\0' && *s2 == '\0') {
		return (1);
	}
	else {
		return (0);
	}
}
