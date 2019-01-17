/*
 * File:ReadFile.c
 * ---------------
 * This program reads the entire contents of infile and returns it 
 * in the form of a dynamic array of strings, one for each line of the file,
 * followed by an extra element containing the value NULL to mark the end of the file.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "genlib.h"
#include "simpio.h"

/* constants */

#define bufferSize  120

/* function prototypes*/

static int strarrncpy_s(strings *arr1, int size, strings *arr2, int count);
static int strarrcpy_s(strings *arr1, int size, strings *arr2);

/* function */

strings *ReadFile(FILE *infile)
{
	strings *line, *newline;
	int size;
	strings str;
	int i;

	size = bufferSize;
	line = (strings *)malloc((size + 1)* sizeof(strings));
	for (i = 0; (str = ReadLine(infile)) != NULL; i++) {
		if (i == size) {
			size *= 2;
			newline = (strings *)malloc((size + 1) * sizeof(strings));
			strarrncpy_s(newline, size + 1, line, i);
			free(line);
			line = newline;
		}
		line[i] = str;
	}
	if (i == 0 && str == NULL) {
		free(line);
		return NULL;
	}
	line[i] = NULL;
	newline = (strings *)malloc((i + 1) * sizeof(strings));
	strarrcpy_s(newline, i + 1, line);
	free(line);
	return newline;
}

static int strarrncpy_s(strings *arr1, int size, strings *arr2, int count)
{
	strings *pstr;

	if (size <= count) {
		return 1;
	}
	for (pstr = arr1; count > 0 && *arr2 != NULL; --count) {
		*pstr++ = *arr2++;
	}
	for (; count > 0; --count) {
		*pstr++ = NULL;
	}
	return 0;
}

static int strarrcpy_s(strings *arr1, int size, strings *arr2)
{
	int s;
	strings *pstr;

	for (pstr = arr2, s = 0; *pstr != NULL; pstr++, s++);
	if (size <= s) {
		return 1;
	}
	for (pstr = arr1; size > 0; --size) {
		*pstr++ = *arr2++;
	}
	return 0;
}
