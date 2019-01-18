/*
 * File: 16.9-Madlibs.c
 * --------------------
 * This program plays Madlibs with the user.
 */

#include <stdio.h>
#include <string.h>

#include "simpio.h"
#include "strlib.h"
#include "genlib.h"
#include "mscanner.h"

/* input filename in console */

//#define FileName  "hamlet.mad"
//#define FileName  "formlet.txt"

/* constants */

#define MaxCount  100
#define MaxSize   1000

/* function prototypes */

/* main program */

main()
{
	char chars[MaxSize];
	char ch;
	strings filename;
	strings token;
	strings tmp, replace;
	strings strs[MaxCount];
	FILE *infile;
	errno_t err;
	int i, j, len;

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
			tmp = strs[i];
			replace = GetLine();
			for (j = 0; strs[j] != NULL; j++) {
				if (StringsEqual(tmp, strs[j])) {
					strs[j] = replace;
				}
			}
		}
	}

	printf("\n\n");
	for (i = 0; strs[i] != NULL; i++) {
		printf("%s", strs[i]);
	}
}
