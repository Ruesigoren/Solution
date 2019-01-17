/*
 * File: 15.5-Prospero.c
 * ----------------------
 * This program displays the lines in a file in reverse order.
 */

#include <stdio.h>
#include <string.h>

#include "genlib.h"
#include "Readfile.h"


/* constants */

//#define FileName  "ipconfig.txt"
#define FileName  "Prospero.txt"

/* main program */

main()
{
	FILE *infile;
	errno_t err;
	strings *pstr, *ptmp;
	int i, size;

	err = fopen_s(&infile, FileName, "r");
	if (err) {
		printf("Can't open the file \"%s\"\n", FileName);
	}
	ptmp = pstr = ReadFile(infile);
	size = 0;
	while (*(ptmp++) != NULL) {
		size++;
	}
	ptmp--;  //while loop ended, ptmp need to minus 1
	for (i = 0; i < size; i++) {
		printf("%s\n", *(--ptmp));  //last element is NULL
	}
}