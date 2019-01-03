/*
 * File: 11.6-MorseCode.c
 * ----------------------
 * This program reads in a string from the user and translates each letter in the string
 * to its equivalent in Morse code, using periods to represent dots and hyphens to represent dashes.
 * Separate words in the output by replacing each space in the input with a newline character,
 * but ignore all other punctuation characters..
 */

#include <stdio.h>
#include <ctype.h>

#include "genlib.h"
#include "simpio.h"
#include "strlib.h"
#include "scanner.h"

/* private functions declaration */

static strings MorseCodeEncrypt(strings token);
static boolean IsLegalWord(strings token);
int LetterIndex(char ch);

/* main program */

main()
{
	strings sentence;
	strings token;

	printf("This program translates a line into morse code.\n");
	printf("Enter English text:");
	sentence = GetLine();
	InitScanner(sentence);
	while (!AtEndOfLine()) {
		token = GetNextToken();
		if (IsLegalWord(token)) {
			printf("%s", MorseCodeEncrypt(token));
		}
		if (StringsEqual(token, " ")) {
			printf("\n");
		}
	}
	printf("\n");
}

static boolean IsLegalWord(strings token)
{
	int i;

	for (i = 0; i < StringsLength(token); i++) {
		if (!isalpha(IthChar(token, i))) return (FALSE);
	}
	return (TRUE);
}

static strings MorseCodeEncrypt(strings token)
{
	int i;
	int len;
	char ch;
	strings word = "";
	strings Morsecode[26] = {
		".-",             //A
		"-...",           //B
		"-.-.",           //C
		"-..",            //D
		".",              //E
		"..-.",           //F
		"--.",            //G
		"....",           //H
		"..",             //I
		".---",           //J
		"-.-",            //K
		".-..",           //L
		"--",             //M
		"-.",             //N
		"---",            //O
		".--.",           //P
		"--.-",           //Q
		".-.",            //R
		"...",            //S
		"-",              //T
		"..-",            //U
		"...-",           //V
		".--",            //W
		"-..-",           //X
		"-.--",           //Y
		"--..",           //Z
	};

	len = StringsLength(token);
	for (i = 0; i < len; i++) {
		ch = IthChar(token, i);
		word = Concat(word, Morsecode[LetterIndex(ch)]);
	}
	return (word);
}

int LetterIndex(char ch)
{
	if (isalpha(ch)) {
		return (toupper(ch) - 'A');
	}
	else {
		return (-1);
	}
}
