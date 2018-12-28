/*
 * File: 10.6-LongestWord.c
 * ------------------------
 * This program finds the longest word in a line.
 */

#include <stdio.h>
#include <ctype.h>

#include "strlib.h"
#include "simpio.h"
#include "scanner.h"

 /* Private function prototypes */

static boolean IsLegalWord(strings token);
static strings GetLongerWord(strings word1, strings word2);

/* main program */

main()
{
	strings line;
	strings token;
	strings longest = "";

	printf("Enter a line: \n");
	line = GetLine();
	InitScanner(line);
	while (!AtEndOfLine()) {
		token = GetNextToken();
		if (IsLegalWord(token)) {
			longest = Concat(GetLongerWord(token, longest), "");
		}
	}
	printf("The longest word is \"%s\"\n", longest);
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

static strings GetLongerWord(strings word1, strings word2)
{
	if (StringsLength(word1) >= StringsLength(word2)) {
		return word1;
	}
	else {
		return word2;
	}
}
