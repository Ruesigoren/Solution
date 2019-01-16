/* 
 * File: 14.8-FindString.c
 * -----------------------
 * This program implements the function FindStirng (s, text, start), 
 * which returns the index position of the first occurrence of s in text
 * after position start or returns ¨C1 if no such match occurs.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* function prototypes */

int FindString(char *s, char *text, int start);
char *SubString(char *str, int p1, int p2);

/* main program */

main()
{
	char *s = "Hello world!";
	char *text = "el";

	printf("%d\n", FindString(s, text, 1));
}

int FindString(char *s, char *text, int start)
{
	int slen, tlen;
	int p1, p2;

	slen = strlen(s);
	tlen = strlen(text);
	p1 = start;
	p2 = p1 + tlen - 1;
	for (; p2 < slen; p1++, p2++) {
		if (strcmp(text, SubString(s, p1, p2)) == 0) {
			return (p1);
		}
	}
	return (-1);
}

char *SubString(char *str, int p1, int p2)
{
	int len;
	char *sub;

	len = strlen(str);
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (p1 > p2 || (p1 > len - 1 && p2 > len - 1)) {
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