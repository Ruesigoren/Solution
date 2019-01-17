/*
 * File: 15.3-Untabify.c
 * ---------------------
 * This program reads a file name form the user and updates the file 
 * so that all the tabs are replaced by enough spaces to reach the next tab stop.
 */

#include <stdio.h>
#include <ctype.h>

#include "simpio.h"

/* constants */

//#define FileName	"untabify.txt"	//input file name in console
#define BufferSize   120

/* main program */

main()
{
	char *filename;
	char tmpname[L_tmpnam_s];
	FILE *infile, *outfile;
	errno_t err;
	char buffer[BufferSize];
	int i, j, k, m;

	while (TRUE) {
		printf("Input filename: ");
		filename = GetLine();
		err = fopen_s(&infile, filename, "r");
		if (err) {
			printf("Can't open the file %s.  Try again.\n", filename);
		}
		else {
			break;
		}
	}
	err = tmpnam_s(tmpname, L_tmpnam_s);
	if (err) {
		printf("Error occurred creating unique filename.\n");
	}
	err = fopen_s(&outfile, tmpname, "w");
	if (err) {
		printf("Can't open temporary file.\n");
	}
	while (fgets(buffer, BufferSize, infile) != NULL) {
		for (i = 0; buffer[i] != '\n'; i++) {
			if (buffer[i] == '\t') {
				k = 0;
				for (j = i - 1; j >= 0 && buffer[j] != '\t'; j--) {		//count the numnber of non-tab character
					k++;
				}
				for (m = 0; m < 8 - k; m++) {	//1 tab = 8 blanks, replace tab with blanks
					putc(' ', outfile);
				}
			}
			else {
				putc(buffer[i], outfile);
			}
		}
		putc(buffer[i], outfile);
	}
	fclose(infile);
	fclose(outfile);
	if (remove(filename) != 0 || rename(tmpname, filename) != 0) {
		printf("Unable to rename temporary file\n");
	}
}
