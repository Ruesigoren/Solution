/*
 * File: 15.7-WordFrequency.c
 * --------------------------
 * This program reads a file and keeps track of the number of times
 * each word appears in that file.
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "simpio.h"
#include "strlib.h"
#include "genlib.h"
#include "scanner.h"
#include "sort.h"

/* constants */

#define FileName  "malvolio.txt"
#define MaxSize  10000
#define MaxCount 1000

/* function prototypes */

static boolean IsLegalWord(char *token);

/* main program */

main()
{
	FILE *infile;
	errno_t err;
	char chars[MaxSize];
	strings strs[MaxCount];
	strings words[MaxCount];
	int wfreq[MaxCount];
	int freq;
	char ch;
	strings token;
	int i, j, n, cpos;

	err = fopen_s(&infile, FileName, "r");
	if (err) {
		printf("Can't open the file %s.\n", FileName);
	}
	else {
		for (i = 0; (ch = getc(infile)) != EOF; i++) {
			chars[i] = ch;
		}
		chars[i] = '\0';
	}
	InitScanner(chars);
	i = 0;
	while (!AtEndOfLine()) {
		token = GetNextToken();
		if (IsLegalWord(token)) {
			strs[i] = ConvertToLowerCase(token);
			i++;
		}
	}
	strs[i] = NULL;
	n = i;;
	Alphabetize(strs, n);
	for (i = 0, j = 0; i < n; j++) {
		cpos = i;
		freq = 0;
		while (i < n && StringsEqual(strs[i], strs[cpos])) {
			i++;
			freq++;
		}
		words[j] = strs[cpos];
		wfreq[j] = freq;
	}
	n = j;
	printf("Word frequence table:\n");
	for (i = 0; i < n; i++) {
		printf("%-20s%d\n", words[i], wfreq[i]);
	}
}

static boolean IsLegalWord(char *token)
{
	int len;
	int i;

	len = strlen(token);
	for (i = 0; i < len; i++) {
		if (!isalpha(token[i])) return (FALSE);
	}
	return (TRUE);
}
