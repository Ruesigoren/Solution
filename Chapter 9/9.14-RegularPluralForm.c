/*
 * File: 9.14-RegularPluralForm.c
 * ------------------------------
 * This program returns the regular plural form of a word.
 */

#include <ctype.h>

#include "simpio.h"
#include "strlib.h"
#include "genlib.h"


/* function prototypes */

strings RegularPluralForm(strings word);
boolean IsConsonant(char ch);

/* main  program */

main()
{
	strings word;

	printf("This program returns the regular plural form of a word.\n");
	while (TRUE) {
		printf("Please enter a word: ");
		word = GetLine();
		if (StringsEqual(word, "")) break;
		printf("The regular plural form is %s\n", RegularPluralForm(word));
	}
}

strings RegularPluralForm(strings word)
{
	int len;
	char LastCh, Last2Ch;
	strings Last2;

	len = StringsLength(word);
    if (len == 1) {
		return (word);
	}
	else {
		LastCh = tolower(IthChar(word, len - 1));
		Last2Ch = tolower(IthChar(word, len - 2));
		Last2 = ConvertToLowerCase(SubStrings(word, len - 2, len - 1));
		switch (LastCh) {
		case 's': case 'x': case 'z':
			return (Concat(word, "es"));
		case 'y':
			if (IsConsonant(Last2Ch)) {
				return (Concat(SubStrings(word, 0, len - 2), "ies"));
			}
			else
				return (Concat(word, "s"));
		case 'h':
			if (StringsEqual(Last2, "ch") || StringsEqual(Last2, "sh")) {
				return (Concat(word, "es"));
			}
			else
				return (Concat(word, "s"));
		default:
			return (Concat(word, "s"));
		}
	}
}

boolean IsConsonant(char ch)
{
	switch (tolower(ch)) {
	case 'a': case 'e': case 'i': case 'o': case 'u':
		return (FALSE);
	default:
		return (TRUE);
	}
}
