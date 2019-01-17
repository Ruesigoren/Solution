/*
 * File: 15.2-Greek.c
 * ------------------
 * This program reads characters form an input file and
 * displays them on the console after making the appropriate random substitutions.
 * Any uppercase character in the input should be replaced by a random uppercase character
 * and every lowercase character by a random lowercase one.
 * Nonalphabetic characters are displayed without change.
 */

#include <stdio.h>
#include <ctype.h>

#include "random.h"

/* constants */

#define FileName    "troilus.dat"

/* function prototypes */

void RandomAlpha(char *ch);

/* main program */

main()
{
	char ch;
	FILE *infile;
	//FILE *outfile;	//output file

	Randomize();
	errno_t err = fopen_s(&infile, FileName, "r");
	//fopen_s(&outfile, "trilous.txt", "w");
	if (err) {
		printf("The file was not opened\n");
	}
	else {
		while ((ch = getc(infile)) != EOF) {
			if (isalpha(ch)) {
				RandomAlpha(&ch);
			}
			putc(ch, stdout);
			//putc(ch, outfile);
		}
	}
}

void RandomAlpha(char *ch)
{
	if (islower(*ch)) {
		*ch = RandomInteger('a', 'z');
	}
	else {
		*ch = RandomInteger('A', 'Z');
	}
}
