/*
 * File: 9.2+9.3-PigLatin.c
 * ------------------------
 * This program translates a line of text from English
 * to Pig Latin.  The rules for forming Pig Latin words
 * are as follows:
 *
 * o  If the word begins with a vowel, add "way" to the
 *    end of the word.
 *
 * o  If the word begins with a consonant, extract the set
 *    of consonants up to the first vowel, move that set
 *    of consonants to the end of the word, and add "ay".
 * 
 * 9.2 Rewrite the Pig Latin program so that it uses the algorithmic strategy of
 *     going through the line character by character rather than word by word.
 *
 * 9.3 Modify the Pig Latin program so that any word that begins with a capital letter
 *     in the English line still begins with a capital letter in Pig Latin.
 */

#include <stdio.h>
#include <ctype.h>

#include "genlib.h"
#include "strlib.h"
#include "simpio.h"


/* Private function prototypes */

void TranslateLine(strings line);
boolean IsLegalWord(strings token);
strings TranslateWord(strings word);
int FindFirstVowel(strings word);
boolean IsVowel(char ch);
strings InitialCapitalization(strings word);

/* Main program */

main()
{
    strings line;

    printf("Enter a line: ");
    line = GetLine();
    TranslateLine(line);
}

/*
 * Function: TranslateLine
 * Usage: TranslateLine(line);
 * ---------------------------
 * This function takes a line of text and translates
 * the words in the line to Pig Latin, displaying the
 * translation as it goes.
 */

static void TranslateLine(strings line)
{
	int len;
	int start;
	char ch;
	strings piglatin;

	len = StringsLength(line);
	for (int i = 0; i < len; i++) {
		ch = IthChar(line, i);
		if (!isalpha(ch)) {
			printf("%c", ch);
		}
		else {
			start = i;
			while (i < len && isalpha(IthChar(line, i))) {
				i++;
			}
			piglatin = TranslateWord(SubStrings(line, start, i - 1));
			printf("%s", piglatin);
			i--;
		}
	}
    printf("\n");
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

/*
 * Function: TranslateWord
 * Usage: word = TranslateWord(word)
 * ---------------------------------
 * This function translates a word from English to Pig Latin
 * and returns the translated word.
 */

static strings TranslateWord(strings word)
{
    int vp;
    strings head, tail;

    vp = FindFirstVowel(word);
    if (vp == -1) {
        return (InitialCapitalization(word));
    } else if (vp == 0) {
        return (InitialCapitalization(Concat(word, "way")));
    } else {
        head = SubStrings(word, 0, vp - 1);
        tail = SubStrings(word, vp, StringsLength(word) - 1);
        return (InitialCapitalization(Concat(tail, Concat(head, "ay"))));
    }
}

/*
 * Function: FindFirstVowel
 * Usage: k = FindFirstVowel(word);
 * --------------------------------
 * FindFirstVowel returns the index position of the first vowel
 * in word.  If word does not contain a vowel, FindFirstVowel
 * returns -1.
 */

static int FindFirstVowel(strings word)
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

static boolean IsVowel(char ch)
{
    switch (tolower(ch)) {
      case 'a': case 'e': case 'i': case 'o': case 'u':
        return (TRUE);
      default:
        return (FALSE);
    }
}

/*
 * Function: InitialCapitalization
 * Usage: word = InitialCapitalization(word);
 * -----------------------------------------
 * This function capitalizates the initial letter of a word.
 */

strings InitialCapitalization(strings word)
{
	int len;
	char ch;
	strings result;

	len = StringsLength(word);
	result = ConvertToLowerCase(word);
	ch = toupper(IthChar(result, 0));
	result = Concat(CharToStrings(ch), SubStrings(result, 1, len - 1));
	return result;
}