/*
 * File: 12.1-ResistorColourCode.c
 * -------------------------------
 * This program reads in the colors of the three bands on a resistor and writes out the corresponding resistance.
 */

#include <stdio.h>
#include <math.h>

#include "simpio.h"
#include "genlib.h"
#include "strlib.h"


/*
 * Global variable
 * ---------------
 *  Colourcode -- Array containing the name of colour codes.
 *  nSize -- Number of colour codes
 */

static strings ColourCode[] = {
    "black",
    "brown",
    "red",
    "orange",
    "yellow",
    "green",
    "blue",
    "violet",
    "gray",
    "white",
};

static int Nsize = sizeof(ColourCode) / sizeof(ColourCode[0]);

 /* Private function declarations */

static int GetColourCode(strings prompt);
static int FindStringInSortedArray(strings key, strings array[], int n);

/* main program */

main()
{
	int code1, code2, code3;
	int resistance;

	code1 = GetColourCode("Colour of first band: ");
	code2 = GetColourCode("Colour of second band: ");
	code3 = GetColourCode("Colour of third band: ");

	resistance = (code1 * 10 + code2) * (int)pow(10, code3);
	printf("Resistance = %d ohms\n", resistance);
}


static int GetColourCode(strings prompt)
{
	int index;
	strings colour;

	while (TRUE) {
		printf("%s", prompt);
		colour = GetLine();
		index = FindStringInSortedArray(colour, ColourCode, Nsize);
		if (index >= 0) break;
		printf("Unknown colour  -- try again.\n");
	}
	return (index);
}

static int FindStringInSortedArray(strings key, strings array[], int n)
{
	int i;

	for (i = 0; i < n; i++) {
		if (StringsEqual(ConvertToLowerCase(key), array[i])) return (i);
	}
	return (-1);
}
