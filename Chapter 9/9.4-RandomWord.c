/*
 * File: 9.4-RandomWord.c
 * ----------------------
 * This program generates 5 random words.
 */

#include <stdio.h>

#include "simpio.h"
#include "strlib.h"
#include "genlib.h"
#include "random.h"

/* function prototypes */

strings RandomWord(void);

/* Constants */

#define MinLetters 2
#define MaxLetters 8

/* main program */

main()
{
	int i;

	Randomize();
	printf("This program generates 5 random words\n");
	for (i = 0; i < 5; i++) {
		printf("%s\n", RandomWord());
	}
}

strings RandomWord(void)
{
	int i, strlen;
	char ch;
	strings word = "";

	strlen = RandomInteger(MinLetters, MaxLetters);
	for (i = 0; i < strlen; i++) {
		ch = RandomInteger('A', 'Z');
		word = Concat(word, CharToStrings(ch));
	}
	return (word);
}
