/*
 * File: 10.5-WordsCounter.c
 * -------------------------
 * This program counts the number of words in a paragraph.
 * 
 * Test paragraph:

 We hold these truths to be self-evident, thay all
 men and women are created equal.
                -- Seneca Falls Declaration, 1848
 *
 */

#include <stdio.h>
#include <ctype.h>

#include "strlib.h"
#include "simpio.h"
#include "scanner.h"

/* Private function prototypes */

static boolean IsLegalWord(strings token);

/* main program */

main()
{
	strings line = "";
	strings newline;
	strings token;
	int nword = 0;

	printf("This program counts the number of words in a paragraph.\n");
	printf("End the paragraph with a blank line.\n");
	while (TRUE) {
		newline = GetLine();
		if(StringsEqual(newline, "")) {
			break;
		}
		line = Concat(line, Concat(" ", newline));
	}
	InitScanner(line);
	while (!AtEndOfLine()) {
		token = GetNextToken();
		if (IsLegalWord(token)) {
			nword++;
		}
	}
	printf("Number of words: %d\n", nword);
}

/*
 * Function: IsLegalWord
 * Usage: if (IsLegalWord(token)) ...
 * ----------------------------------
 * IsLegalWord returns TRUE if every character in the argument
 * token is alphabetic.
 */

static boolean IsLegalWord(strings token)
{
    int i;

    for (i = 0; i < StringsLength(token); i++) {
        if (!isalpha(IthChar(token, i))) return (FALSE);
    }
    return (TRUE);
}
