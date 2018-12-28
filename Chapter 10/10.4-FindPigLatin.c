/*
 * File: 9.4-Findpiglatin.c
 * ------------------------
 * The English word trash has the interesting property that its Pig Latin translation, ashtray,
 * happens to be another English word.
 * This program finds them in a dictionary which contains nearly 400,000 words.
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "strlib.h"
#include "genlib.h"
#include "simpio.h"
#include "worddic.h"

/* Private function prototypes */

static char *TranslateWord(char *word);
static int FindFirstVowel(char *word);
static boolean IsVowel(char ch);
static char *SubString(char *str, int p1, int p2);
static char *Concat(char *s1, char *s2);

/* Main program */

main()
{
    char *token;
	char *tmp;

	/*
	strings *str, *str2;
	
	str2 = NewArray(5, strings);
	str = NewArray(5, strings);
	str[0] = "adsa";
	str[1] = "sdfssd";
	str[2] = "sdfs";
	str[3] = "hekk";
	str[4] = "sffwe";
	str2[0] = "wrwa";
	str2[1] = "fsfssd";
	str2[2] = "ios";
	str2[3] = "plfkk";
	str2[4] = "13we";
	//= { "adsa", "sdfssd", "sdfs", "hekk", "sffwe" };

	str[1] = CopyStrings(str2[4]);
	MergeSortStringArray(str, 5);
	for (int i = 0; i < 5; i++) {
		printf("%s\n", str[i]);
	}
	*/
	//token = TranslateWord("air");
	//printf("%s", token);
	InitDictionary();
	while (!AtEndOfDictionary()) {
		token = GetNextDictionaryEntry();
		tmp = token;
		token = TranslateWord(token);
		if (IsEnglishWord(token) && !StringsEqual(tmp, token)) {
			printf("%s -- %s\n", tmp, token);
		}
	}
}

/*
 * Function: TranslateWord
 * Usage: word = TranslateWord(word)
 * ---------------------------------
 * This function translates a word from English to Pig Latin
 * and returns the translated word.
 */

static char *TranslateWord(char *word)
{
    int vp;
    char *head, *tail;

    vp = FindFirstVowel(word);
    if (vp == -1) {
        return (word);
    } else if (vp == 0) {
        return (Concat(word, "way"));
    } else {
        head = SubString(word, 0, vp - 1);
        tail = SubString(word, vp, strlen(word) - 1);
        return (Concat(tail, Concat(head, "ay")));
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

static int FindFirstVowel(char *word)
{
	int len;
    int i;

	len = strlen(word);
    for (i = 0; i < len; i++) {
        if (IsVowel(word[i])) return (i);
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

static char *SubString(char *str, int p1, int p2)
{
	int len;
	char *sub;

	len = strlen(str);
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (p1 > p2 || (p1 > len - 1 && p2 > len - 1)) {
		return NULL;
	}
	else {
		if (p1 < 0) {
			p1 = 0;
		}
		if (p2 > len - 1) {
			p2 = len - 1;
		}
	}
	str += p1;
	strncpy_s(sub, len + 1, str, p2 - p1 + 1);
	return sub;
}

static char *Concat(char *s1, char *s2)
{
	int len1, len2;
	char *s;

	len1 = strlen(s1);
	len2 = strlen(s2);
	s = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	strcpy_s(s, len1 + len2 + 1, s1);
	strcat_s(s, len1 + len2 + 1, s2);
	return (s);
}
