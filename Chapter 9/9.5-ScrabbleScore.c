/*
 * File: 9.5-ScrabbleScore.c
 * -------------------------
 * This program tests the ScrabbleScore function.
 */

#include <stdio.h>

#include "simpio.h"
#include "strlib.h"
#include "genlib.h"

/* function prototypes */

int ScrabbleScore(strings word);
int LetterScore(char ch);

/* main program */

main()
{
	strings word;

	printf("This program tests the ScrabbleScore function.\n");
	printf("Enter words, ending with a blank line.\n");
	while (TRUE) {
		printf("Word: ");
		word = GetLine();
		if (StringsEqual(word, "")) break;
		printf("The basic score for \'%s\' is %d.\n", word, ScrabbleScore(word));
	}
}

int ScrabbleScore(strings word)
{
	int i, score = 0;

	for (i = 0; i < StringsLength(word); i++) {
		score += LetterScore(IthChar(word, i));
	}
	return (score);
}

int LetterScore(char ch)
{
	switch (ch) {
	case 'A': case 'E': case 'I': case 'L': case 'N':
	case 'O': case 'R': case 'S': case 'T': case 'U':
		return (1);
	case 'D': case 'G':
		return (2);
	case 'B': case 'C': case 'M': case 'P':
		return (3);
	case 'F': case 'H': case 'V': case 'W': case 'Y':
		return (4);
	case 'K':
		return (5);
	case 'J': case 'X':
		return (8);
	case 'Q': case 'Z':
		return (10);
	default:
		return (0);
	}
}