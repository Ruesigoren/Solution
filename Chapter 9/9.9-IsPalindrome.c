/*
 * File: 9.9-IsPalindrome.c
 * ------------------------
 * This program determines whether a word is palindrome.
 */

#include <ctype.h>
#include "simpio.h"
#include "strlib.h"
#include "genlib.h"

/* function prototypes */

boolean IsPalindrome(strings word);
strings ReverseString(strings str);

/* main program */

main()
{
	strings word;

	printf("This program determines whether a word is palindrome.\n");
	while (TRUE) {
		printf("Please enter a word: ");
		word = GetLine();
		if (StringsEqual(word, "")) break;
		if (IsPalindrome(word)) {
			printf("Is Palindrome\n");
		}
		else {
			printf("Not Palindrome\n");
		}
	}
}

boolean IsPalindrome(strings word)
{
	word = ConvertToLowerCase(word);
	return (StringsEqual(word, ReverseString(word)));
}

strings ReverseString(strings str)
{
	strings result;
	int i;

	result = "";
	for (i = 0; i < StringsLength(str); i++) {
		result = Concat(CharToStrings(IthChar(str, i)), result);
	}
	return (result);
}
