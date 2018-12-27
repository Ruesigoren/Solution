/*
 * File: 9.7-EqualIgnoringCase.c
 * -----------------------------
 * This program implements function EqualIgnoringCase which
 * returns TRUE if the string s1 and s2 are the same,
 * not counting difference in the case of a letter
 */

#include <ctype.h>

#include "simpio.h"
#include "strlib.h"
#include "genlib.h"

/* function prototypes */

boolean EqualIgnoringCase(strings s1, strings s2);

/* main program */

main()
{
	strings s1, s2;
	
	printf("Please enter 2 words:\n");
	while (TRUE) {
		printf("word1: ");
		s1 = GetLine();
		if (StringsEqual(s1, "")) break;
		printf("word2: ");
		s2 = GetLine();
		if (StringsEqual(s2, "")) break;
		if (EqualIgnoringCase(s1, s2)) {
			printf("TRUE\n");
		}
		else {
			printf("FALSE\n");
		}
	}
}

boolean EqualIgnoringCase(strings s1, strings s2)
{
	s1 = ConvertToLowerCase(s1);
	s2 = ConvertToLowerCase(s2);
	if (StringsEqual(s1, s2)) {
		return (TRUE);
	}
	else {
		return (FALSE);
	}
}