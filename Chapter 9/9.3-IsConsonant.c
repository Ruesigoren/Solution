/*
 * File: 9.3-IsConsonant.c
 * -----------------------
 * This programs shows the consonants.
 */

#include <ctype.h>

#include "simpio.h"
#include "genlib.h"
#include "strlib.h"

/* function prototypes */

boolean IsConsonant(char ch);

/* main program */

main()
{
	char ch;

	printf("The English consonants are:\n");
	for (ch = 'A'; ch <= 'Z'; ch++) {
		if (IsConsonant(ch)) {
			printf("%c ", ch);
		}
	}
	printf("\n");
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
