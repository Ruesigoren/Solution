/*
 * File: 10.7-ReverseSentence.c
 * ----------------------------
 * This program reverses a sentence.
 */

#include <stdio.h>
#include <ctype.h>

#include "strlib.h"
#include "simpio.h"
#include "scanner.h"

 /* Private function prototypes */

static boolean IsLegalWord(strings token);
static strings ReverseSentence(strings sentence);

/* main program */

main()
{
	strings sentence;

	printf("Enter a line: ");
	sentence = GetLine();
	printf("%s\n", ReverseSentence(sentence));

}

static boolean IsLegalWord(strings token)
{
	int i;
	char ch;
	int len;
	
	len = StringsLength(token);
	for (i = 0; i < len; i++) {
		ch = IthChar(token, i);
		if (!isalpha(ch)) {
			return (FALSE);
		}
	}
	return (TRUE);
}

static strings ReverseSentence(strings sentence)
{
	strings line = "";
	strings token;

	InitScanner(sentence);
	while (!AtEndOfLine()) {
		token = GetNextToken();
		if (IsLegalWord(token)) {
			line = Concat(Concat(token, " "), line);
		}
	}
	return (line);
}
