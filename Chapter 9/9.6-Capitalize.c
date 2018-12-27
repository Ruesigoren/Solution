/*
 * File: 9.6-Capitalize.c
 * ----------------------
 * This program capitalizes a word.
 */

#include <ctype.h>

#include "simpio.h"
#include "strlib.h"
#include "genlib.h"

/* function prototypes */

strings Capitalize(strings word);

/* main program */

main()
{
	strings word;

	printf("This program capitalize a word.\n");
	printf("Enter words, ending with a blank line.\n");
	while (TRUE) {
		printf("Word: ");
		word = GetLine();
		if (StringsEqual(word, "")) break;
		printf("The Capitalized word is \'%s\'.\n", Capitalize(word));
	}
}

strings Capitalize(strings word)
{
	int i;
	char initial;
	strings remain = "";

	initial = IthChar(word, 0);
	for (i = 1; i < StringsLength(word); i++) {
		remain = Concat(remain, CharToStrings(tolower(IthChar(word, i))));
	}
	return (Concat(CharToStrings(toupper(initial)), remain));
}
