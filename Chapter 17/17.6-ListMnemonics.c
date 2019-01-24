/*
 * File: 17.6-ListMnemonics.c
 * --------------------------
 * This programg enerates all possible letter combinations that
 * correspond to a given number, represented as a string of digits.
 */

#include <stdio.h>

#include "simpio.h"
#include "genlib.h"
#include "strlib.h"

/* function prototypes */

void ListMnemonics(strings number_string);
void Permute(strings number_string, int k);
static strings AlphaStringOfNumber(char number);

/* main program */

main()
{
	strings str;

	printf("This program displays mnemonics for a telephone number.\n");
	printf("Number: ");
	str = GetLine();
	ListMnemonics(str);
	
}

void ListMnemonics(strings number_string)
{
	Permute(number_string, 0);
}

void Permute(strings number_string, int k)
{
	char number;
	strings mnemonic;
	strings str;
	int i, len;

	len = StringsLength(number_string);
	mnemonic = CopyStrings(number_string);  //backup the string
	number = IthChar(number_string, k);
	str = AlphaStringOfNumber(number);

	if (k == len - 1) {
		for (i = 0; i < StringsLength(str); i++) {
			number_string[k] = str[i];
			printf("%s\n", number_string);
		}
	}
	else {
		for (i = 0; i < StringsLength(str); i++) {
			number_string[k] = str[i];
			Permute(number_string, k + 1);
			number_string = CopyStrings(mnemonic);  //restore the string
		}
	}
}

static strings AlphaStringOfNumber(char number)
{
	switch (number) {
	case '1': return "1";
	case '2': return "ABC";
	case '3': return "DEF";
	case '4': return "GHI";
	case '5': return "JKL";
	case '6': return "MNO";
	case '7': return "PRS";
	case '8': return "TUV";
	case '9': return "WXY";
	case '0': return "0";
	default:
		break;
	}
}
