/*
 * File: 14.6-EncodeString.c
 * -------------------------
 * This program implements the cipher program described in exercise 8 of Chapter 9, 
 * but it uses the ANSI string library rather than strlib.h.
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "simpio.h"

/*
 * Constant
 * --------
 * MaxLength -- Maximum length of a string
 */

#define MaxLength 40

/* function prototypes */

void EncodeString(char *string, char *enstring, int key);

/* main program */

main()
{
	char Enstr[MaxLength + 1];;
	char *Str;
	int key;

	printf("This program encodes a message using a cyclic cipher.\n");
	printf("Enter the numberic key:");
	key = GetInteger();
	printf("Enter a message: ");
	Str = GetLine();
	EncodeString(Str, Enstr, key);
	printf("Encoded message: %s\n", Enstr);
}

void EncodeString(char *string, char *enstring, int key)
{
	int len;

	len = strlen(string);
	key %= 26;
	strncpy_s(enstring, MaxLength + 1, string, len);
	for (; *enstring != '\0'; ++enstring) {
		if (islower(*enstring)) {
			if (*enstring + key > 'z') {
				*enstring += key - 26;
			}
			else {
				*enstring += key;
			}
		}
		else {
			if (*enstring + key > 'Z') {
				*enstring += key - 26;
			}
			else {
				*enstring += key;
			}
		}
	}
}
