/*
 * File: 10.1-OldStyleAbbreviation.c
 * ---------------------------------
 * This program takes a string as argument and returns a string consisting of
 * an old-style abbreviation formed by connecting in sequence the following pieces:
 * --a. The initial consonant string, up to the first vowel.
 *      If the original string begins with a vowel, use that vowel instead (see the Iowa example).
 * --b. The last letter in the word.
 * --c. A period.;
 */

#include <stdio.h>
#include <ctype.h>

#include "genlib.h"
#include "strlib.h"
#include "simpio.h"

/* function prototypes */

strings OldStyleAbbreviation(strings token);
boolean IsLegalWord(strings token);
int FindFirstVowel(strings word);
boolean IsVowel(char ch);

/* main program */

main()
{
	strings word;

	while (TRUE) {
		printf("Please enter a word:");
		word = GetLine();
		if (StringsEqual(word, "")) {
			break;
		}
		printf("The old style abbreviation of %s is %s\n", word, OldStyleAbbreviation(word));
	}
}

/*
 * Function: OldStyleAbbreviation
 * Usage: OldSytleAbbreviation(token);
 * ----------------------------------
 * This function takes a word and returns the word's
 * old style abbreviation.
 */

strings OldStyleAbbreviation(strings token)
{
	int vp, len;
	strings head, tail;

	vp = FindFirstVowel(token);
	len = StringsLength(token);
	if (vp == -1) {
		return (token);
	}
	else if(vp == 0){
		head = CharToStrings(IthChar(token, 0));
	}
	else {
		head = SubStrings(token, 0, vp - 1);
	}
	tail = CharToStrings(IthChar(token, len - 1));
	return (Concat(Concat(head, tail), "."));
}

/*
 * Function: IsLegalWord
 * Usage: if (IsLegalWord(token)) ...
 * ----------------------------------
 * IsLegalWord returns TRUE if every character in the argument
 * token is alphabetic.
 */

boolean IsLegalWord(strings token)
{
    for (int i = 0; i < StringsLength(token); i++) {
        if (!isalpha(IthChar(token, i))) return (FALSE);
    }
    return (TRUE);
}

/*
 * Function: FindFirstVowel
 * Usage: k = FindFirstVowel(word);
 * --------------------------------
 * FindFirstVowel returns the index position of the first vowel
 * in word.  If word does not contain a vowel, FindFirstVowel
 * returns -1.
 */

int FindFirstVowel(strings word)
{
	int i;

	for (i = 0; i < StringsLength(word); i++) {
		if (IsVowel(IthChar(word, i))) return (i);
	}
	return (-1);
}

/*
 * Function: IsVowel
 * Usage: if (IsVowel(ch)) . . .
 * -----------------------------
 * IsVowel returns TRUE if ch is a vowel.  This function
 * recognizes vowels in either upper or lower case.
 */

boolean IsVowel(char ch)
{
    switch (tolower(ch)) {
      case 'a': case 'e': case 'i': case 'o': case 'u':
        return (TRUE);
      default:
        return (FALSE);
    }
}
