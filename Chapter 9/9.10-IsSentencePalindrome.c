/*
 * File: 9.10-IsSentencePalindrome.c
 * ---------------------------------
 * This program checks for palindromes by ignoring punctuation and differences in the case of letter.
 */

#include <ctype.h>

#include "simpio.h"
#include "strlib.h"
#include "genlib.h"

/* function prototypes */

strings SentenceToWord(strings sentence);
boolean IsPalindrome(strings word);
strings ReverseString(strings str);

/* main program */

main()
{
	strings word;

	printf("This program checks for palindromes.\n");
	printf("Indicate the end of the input with a blank line.\n");
	while (TRUE) {
		printf("Enter a string: ");
		word = SentenceToWord(GetLine());
		if (StringsEqual(word, "")) break;
		if (IsPalindrome(word)) {
			printf("This is a palindrome\n");
		}
		else {
			printf("This is not a palindrome\n");
		}
	}
}

strings SentenceToWord(strings sentence)
{
	strings word;
	char ch;
	strings str;

	word = "";
	for (int i = 0; i < StringsLength(sentence); i++) {
		ch = IthChar(sentence, i);
		str = CharToStrings(ch);
		if (isalpha(ch)) {
			word = Concat(word, str);
		}
		else if (StringsEqual(str, "")) 
			return (word);
		else
			continue;
	}
	return (word);
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
