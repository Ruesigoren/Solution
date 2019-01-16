/*
 * File: 14.4-Acronym.c
 * --------------------
 * This program implements and tests the Acronym function.
 * To fit the discipline of the string.h interface, 
 * This function delivers its result by writing data 
 * into a character buffer supplied by the caller.
 */

#include <stdio.h>
#include <string.h>

#include "simpio.h"

/* constants */

#define Nelements  10

/* function prototypes */

void Acronym(char *str, char *buffer);

/* main program */

main()
{
	char acronym[Nelements + 1];
	char *str;

	printf("This program generates acronyms.\n");
	printf("Indicate end of input with a blank line.\n");
	while (TRUE) {
		printf("strings: ");
		str = GetLine();
		if (strcmp(str, "") == 0) break;
		Acronym(str, acronym);
		printf("The acronym is %s.\n", acronym);
	}
}

void Acronym(char *str, char *buffer)
{
	strncpy_s(buffer, Nelements + 1, str, 1);
	for (; *str != '\0'; ++str) {
		if (*str == ' ' && *(++str) != ' ') {
			strncat_s(buffer, Nelements + 1, str, 1);
		}
	}
}
