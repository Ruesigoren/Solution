/*
 * File: 9.12-MyFindString.c
 * -------------------------
 * This program implements a function MyFindString that behaves
 * in exactly the same way that FindString does..
 */

#include <ctype.h>

#include "simpio.h"
#include "strlib.h"
#include "genlib.h"


/* function prototypes */

int MyFindString(strings str, strings text, int start);


/* main program */

main()
{
	strings str, text;
	int start, result;

	printf("This program finds text in a given string.\n");
	printf("Please give a string: ");
	str = GetLine();
	printf("Please enter the text: ");
	text = GetLine();
	printf("Please enter the start position: ");
	start = GetInteger();
	result = MyFindString(str, text, start);
	if (result != -1) {
		printf("The position is %d.\n", result);
	}
	else {
		printf("Can't find \'%s\' in \'%s\'.\n", text, str);
	}


}

int MyFindString(strings str, strings text, int start)
{
	strings tar;
	int i, Lstr, Ltext;

	Lstr = StringsLength(str);
	Ltext = StringsLength(text);

	if ((start + Ltext) > Lstr) {
		return (-1);
	}
	else {
		for (i = start; (i + Ltext - 1) < Lstr; i++) {
			tar = SubStrings(str, i, i + Ltext - 1);
			if (StringsEqual(text, tar)) {
				return (i);
			}
		}				
		return (-1);
	}
}
