/*
 * File: 15.6-Madlibs.c
 * --------------------
 * This program plays Madlibs with the user.
 */

#include <stdio.h>
#include <string.h>

#include "simpio.h"
#include "strlib.h"
#include "genlib.h"
#include "mscanner.h"

/* constants */

//#define FileName  "hamlet.mad"
#define MaxCount  100
#define MaxSize   400

/* function prototypes */

/* main program */

main()
{
	char chars[MaxSize];
	char ch;
	strings filename;
	strings token;
	strings strs[MaxCount];
	FILE *infile;
	errno_t err;
	int i, len;

	while (TRUE) {
		printf("Input file: ");
		filename = GetLine();
		err = fopen_s(&infile, filename, "r");
		if (err) {
			printf("Can't open the file %s.  Try again.\n", filename);
		}
		else {
			break;
		}
	}
	for (i = 0; (ch = getc(infile)) != EOF; i++) {
		chars[i] = ch;
	}
	chars[i] = '\0';

	/* scan the paragraph and divide it into tokens */
	InitScanner(chars);
	i = 0;
	while (!AtEndOfLine()) {
		token = GetNextToken();
		strs[i] = token;
		i++;
	}
	strs[i] = NULL;

	for (i = 0; strs[i] != NULL; i++) {
		len = strlen(strs[i]);
		if (strs[i][0] == '<' && strs[i][len - 1] == '>') {
			printf("%s: ", SubStrings(strs[i], 1, len - 2));
			strs[i] = GetLine();
		}
	}

	printf("\n\n");
	for (i = 0; strs[i] != NULL; i++) {
		printf("%s", strs[i]);
	}
}
