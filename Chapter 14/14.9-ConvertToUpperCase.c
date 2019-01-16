/* 
 * File: 14.9-ConvertToUpperCase.c
 * -------------------------------
 * This program implements implement the function ConvertToUpperCase (s), 
 * which returns a copy of s in which all alphabetic characters have been converted to upper case.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* function prototypes */

char *ConvertToUpperCase(char *s);

/* main program */

main()
{
	char *s = "My nsfai is";

	printf("%s\n", ConvertToUpperCase(s));
}

char *ConvertToUpperCase(char *s)
{
	char *c;  //converted string
	int len;
	int i;

	len = strlen(s);
	c = (char *)malloc((len + 1) * sizeof(char));
	strcpy_s(c, len + 1, s);
	for (i = 0; c[i] != '\0'; i++) {
		if (islower(c[i])) {
			c[i] += ('A' - 'a');
		}
	}
	return c;
}
