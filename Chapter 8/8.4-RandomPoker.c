/*
 * File: 8.4-RandomPoker.c
 * -----------------------
 * This program  displays the name of a card randomly
 * chose from a complete deck of 52 playing cards.
 */

#include <stdio.h>
#include <stdlib.h>

#include "genlib.h"
#include "random.h"

/*
 * Constants
 * ---------
 * NTrials -- Number of trials
 */

#define NTrials 10

/* function prototypes */

void RandomPoker(void);
strings NameOfSuit(int suit);
strings NameOfRand(int rand);

/* Main program */

main()
{
	int i;

	Randomize();
	for (i = 0; i < NTrials; i++) {
		RandomPoker();
	}
}

void RandomPoker(void)
{
	int suit, rand;

	suit = RandomInteger(1, 4);
	rand = RandomInteger(1, 13);
	printf("%5s of %s\n", NameOfRand(rand), NameOfSuit(suit));
}

strings NameOfSuit(int suit)
{
	switch (suit) {
	case  1: return ("Clubs");
	case  2: return ("Diamonds");
	case  3: return ("Hearts");
	case  4: return ("Spades");
	default: return ("Wrong Suit!");
	}
}

strings NameOfRand(int rand)
{
	switch (rand) {
	case  1: return ("Ace");
	case  2: return ("Two");
	case  3: return ("Three");
	case  4: return ("Four");
	case  5: return ("Five");
	case  6: return ("Six");
	case  7: return ("Seven");
	case  8: return ("Eight");
	case  9: return ("Nine");
	case 10: return ("Ten");
	case 11: return ("Jack");
	case 12: return ("Queen");
	case 13: return ("King");
	default: return ("Wrong Rand!");
	}
}
