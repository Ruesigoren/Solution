/*
 * File: 9.13-ReplaceAll.c
 * -----------------------
 * This program edits a string by replacing all
 * instance of a pattern substring by a new string.
 */

#include <ctype.h>

#include "simpio.h"
#include "strlib.h"
#include "genlib.h"


/* function prototypes */

strings ReplaceAll(strings str, strings pattern, strings replacement);
strings ReplaceFirst(strings str, strings pattern, strings replacement);
int MyFindString(strings str, strings text, int start);

/* main program */

main()
{
	strings str, pattern, replacement;

	printf("This program edits a string by replacing all\n");
	printf("instance of a pattern substring by a new string.\n");
	printf("Enter the string to be edited:\n");
	str = GetLine();
	printf("Enter the pattern string: ");
	pattern = GetLine();
	printf("Enter the replacement string: ");
	replacement = GetLine();
	str = ReplaceAll(str, pattern, replacement);
	printf("%s\n", str);
}

strings ReplaceAll(strings str, strings pattern, strings replacement)
{
	strings copy;

	while (TRUE) {
		copy = str;
		str = ReplaceFirst(str, pattern, replacement);
		if (StringsEqual(copy, str)) {
			return (str);
		}
	}
}

strings ReplaceFirst(strings str, strings pattern, strings replacement)
{
	strings head, tail;
	int pos;

	pos = MyFindString(str, pattern, 0);
	if (pos == -1) return (str);
	head = SubStrings(str, 0, pos - 1);
	tail = SubStrings(str, pos + StringsLength(pattern),
		StringsLength(str) - 1);
	return (Concat(Concat(head, replacement), tail));
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
