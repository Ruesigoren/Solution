/*
 * File: 14.7-SubString.c
 * ----------------------
 * This program implements a function that returns the substring of s 
 * beginning at position p1 and ending at position p2. 
 *
 * The function applies the following rules:
 *
 * a. If p1 is negative, it is set to 0 so that it indicates the first character in the string.
 * b. If p2 is greater than strlen (s) ¨C 1, it is set to strlen(s) ¨C 1 so that it indicates teh last character.
 * c. If p1 is ends up being greater than p2, SubString returns the empty string.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* function prototypes */

char *SubString(char *str, int p1, int p2);

/* main program */

main()
{
	char *str = "Hello World!";
	char *substr;

	substr = SubString(str, 0, 15);
	printf("%s\n", str);
	printf("%s\n", substr);
}

char *SubString(char *str, int p1, int p2)
{
	int len;
	char *sub;

	len = strlen(str);
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (p1 > p2 || (p1 > len -1 && p2 > len - 1)) {
		return NULL;
	}
	else {
		if (p1 < 0) {
			p1 = 0;
		}
		if (p2 > len - 1) {
			p2 = len - 1;
		}
	}
	str += p1;
	strncpy_s(sub, len + 1, str, p2 - p1 + 1);
	return sub;
}