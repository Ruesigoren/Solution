/*
 * File: 5.11-GetYesOrNo.c
 * -----------------------
 * This Program gets yes or no from user and determines whather to play game or not.
 */

#include <stdio.h>
#include "simpio.h"
#include "genlib.h"
#include "strlib.h"

/* function prototypes */

void PlayOneGame(void);
boolean GetYesOrNo(strings prompt);

/* main program */

main()
{
	while (TRUE)
	{
		PlayOneGame();
		if (!GetYesOrNo("Would you like to play again?")) break;
	}
}

void PlayOneGame(void)
{
	printf("...play the game...\n");
}

boolean GetYesOrNo(strings prompt)
{
	strings answer;

	while (TRUE) {
		printf("%s\n", prompt);
		answer = GetLine();
		if (StringsEqual(answer, "yes")) return TRUE;
		else if (StringsEqual(answer, "no")) return FALSE;
		else printf("Please answer yes or no\n");
	}
}
