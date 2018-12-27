/*
 * File: 9.8-EncodeString.c
 * ------------------------
 * This program encodes a message using a cyclic cipher.
 */

#include <ctype.h>

#include "simpio.h"
#include "strlib.h"
#include "genlib.h"

/* function prototypes */

strings EncodeString(strings str, int key);
char EncodeChar(char ch, int key);

/* main program */

main()
{
	strings str;
	int key;

	printf("This program encodes a message using a cyclic cipher.\n");
	printf("Enter the numberic key:");
	key = GetInteger();
	printf("Enter a message: ");
	str = GetLine();
	printf("Encoded message: %s\n", EncodeString(str, key));
}

strings EncodeString(strings str, int key)
{
	char ch;
	strings EnStr = "";

	for (int i = 0; i < StringsLength(str); i++) {
		ch = IthChar(str, i);
		EnStr = Concat(EnStr, CharToStrings(EncodeChar(ch, key)));
	}
	return (EnStr);
}

char EncodeChar(char ch, int key)
{
	if (key >= 26) {
		key %= 26;
	}
	if (isupper(ch)) {
		if (ch + key <= 'Z') {
			ch += key;
		}
		else if (ch + key > 'Z') {
			ch += key - 26;
		}
	}
	if (islower(ch)) {
		if (ch + key <= 'z') {
			ch += key;
		}
		else if (ch + key > 'z') {
			ch += key - 26;
		}
	}
	return (ch);
}