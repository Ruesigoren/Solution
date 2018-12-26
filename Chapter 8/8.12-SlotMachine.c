/*
 * File: 8.12-SlotMachine.c
 * -------------------------
 * this program simulates the slot machine.
 */

#include <stdio.h>

#include "genlib.h"
#include "random.h"
#include "simpio.h"
#include "strlib.h"

/*
 * Constants:
 * ----------
 * Symbols are represented by the integers 1-6.
 */

#define LEMON    1
#define CHERRY   2
#define ORANGE   3
#define PLUM     4
#define BELL     5
#define BAR      6

/* function prototypes */

void GiveInstructions();
void PlayGame();
int GenerateSymbol(void);
strings SymbolName(int symbol);
int CalculateBonus(int symbol1, int symbol2, int symbol3);
boolean GetYesOrNo(void);

main()
{
	Randomize();
	GiveInstructions();
	PlayGame();
}

void GiveInstructions()
{
	printf("Would you like instructions?  \n");
	printf("-- Enter yes/no to answer the quenstion or continue/quit playing.\n");
	printf("-- Abbreviations such as y/n or Y/N are also supported.\n\n");
	printf("Again: Would you like instructions?  ");
	if (GetYesOrNo()) {
	}
}

void PlayGame()
{
	int s1, s2, s3;
	int stake, bonus;

	stake = 50;
	printf("You have $%d.Would you like to play?  ", stake);
	while (GetYesOrNo()) {
		s1 = GenerateSymbol();
		s2 = GenerateSymbol();
		s3 = GenerateSymbol();
		bonus = CalculateBonus(s1, s2, s3);
		printf("%-6s    %-6s    %-6s    ", SymbolName(s1), SymbolName(s2), SymbolName(s3));
		if (bonus > 0) {
			printf("-- you win $%d\n", bonus);
		}
		else {
			printf("-- you lose\n");
		}
		stake += bonus;
		if (stake > 0) {
			printf("You have $%d.Would you like to play?  ", stake);
		} else {
			printf("You have $%d left.Game Over!\n", stake);
			break;
		}
	}

}

int GenerateSymbol(void)
{
	return (RandomInteger(1, 6));
}

strings SymbolName(int symbol)
{
	switch (symbol) {
	case 1: return ("LEMON");
	case 2: return ("CHERRY");
	case 3: return ("ORANGE");
	case 4: return ("PLUM");
	case 5: return ("BELL");
	case 6: return ("BAR");
	default: break;
	}
}

int CalculateBonus(int symbol1, int symbol2, int symbol3)
{
	if (symbol1 == LEMON) {
		return (0);
	}
	else if (symbol1 == CHERRY) {
		if (symbol2 == CHERRY) {
			if (symbol3 == CHERRY) {
				return (7);
			}
			else {
				return (5);
			}
		}
		else {
			return (2);
		}
	}
	else if (symbol1 == ORANGE && symbol2 == ORANGE) {
		if (symbol3 == ORANGE || symbol3 == BAR) {
			return (10);
		}
		else {
			return (-1);
		}
	}
	else if (symbol1 == PLUM && symbol2 == PLUM) {
		if (symbol3 == PLUM || symbol3 == BAR) {
			return (14);
		}
		else {
			return (-1);
		}
	}
	else if (symbol1 == BELL && symbol2 == BELL) {
		if (symbol3 == BELL || symbol3 == BAR) {
			return (20);
		}
		else {
			return (-1);
		}
	}
	else if (symbol1 == BAR && symbol2 == BAR && symbol3 == BAR) {
		return (250);
	}
	else {
		return (-1);
	}
}

boolean GetYesOrNo(void)
{
	strings answer;

	while (TRUE) {
		answer = GetLine();
		if (StringsEqual(answer, "yes") || StringsEqual(answer, "Y")
			|| StringsEqual(answer, "y")) return (TRUE);
		else if (StringsEqual(answer, "no") || StringsEqual(answer, "N")
			|| StringsEqual(answer, "n")) return (FALSE);
		else {
			printf("Please answer yes or no.\n");
		}
	}
}