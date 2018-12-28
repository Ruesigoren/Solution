/*
 * File: 10.8+10.9-TestScanner.c
 * -----------------------------
 * This program return uppercae tokens of a line.
 */

#include <stdio.h>
#include <ctype.h>

#include "strlib.h"
#include "simpio.h"
#include "10.8+10.9-scanner.h"

/* main program */

main()
{
	strings token;
	strings sentence;

	printf("Enter a line: ");
	sentence = GetLine();
	printf("The tokens are: \n");
	InitScanner(sentence);
	IgnoreSpace(TRUE);
	ReturnUppercaseTokens(TRUE);
	while (!AtEndOfLine()) {
		token = GetNextToken();
		printf("\"%s\"\n", token);
	}
}
