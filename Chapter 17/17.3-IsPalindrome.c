/*
 * File: 17.3-IsPalindrome.c
 * -------------------------
 * This is the implementation of IsPalindrome that operates recursively.
 */

#include <stdio.h>

#include "simpio.h"
#include "genlib.h"
#include "strlib.h"

/* function prototypes */

boolean IsPalindrome(strings str);

/* main program */

main()
{
	strings str;

	while (TRUE) {
		printf("? ");
		str = GetLine();
		if (StringsEqual(str, "")) break;
		if (IsPalindrome(str)) {
			printf("Yes, It's Palindrome.\n");
		}
		else {
			printf("No, It isn't a Palindrome.\n");
		}
	}
}

boolean IsPalindrome(strings str)
{
	int len;

	len = StringsLength(str);
	if (len == 1) return TRUE;
	if (len == 2) {
		if (str[0] == str[1]) return TRUE;
		return FALSE;
	}
	if (len >= 3) {
		if (str[0] == str[len - 1]) return IsPalindrome(SubStrings(str, 1, len - 2));
		return FALSE;
	}
}
