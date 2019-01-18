/*
 * File: scanner.c
 * ---------------
 * This file implements the scanner.h interface.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "genlib.h"
#include "mscanner.h"

/*
 * Private variables
 * -----------------
 * buffer  -- Private copy of the string passed to InitScanner
 * buflen  -- Length of the buffer, saved for efficiency
 * cpos    -- Current character position in the buffer
 */

static char *buffer;
static int buflen;
static int cpos;

/* private functions */

static char *SubString(char *str, int p1, int p2);
static char *CharToString(char ch);
static int FindFirstLessThanSign(char *str, int p1, int p2);
static int FindFirstMoreThanSign(char *str, int p1, int p2);

/*
 * Function: InitScanner
 * ---------------------
 * All this function has to do is initialize the private
 * variables used in the package.
 */

void InitScanner(char *line)
{
    buffer = line;
    buflen = strlen(buffer);
    cpos = 0;
}

/*
 * Function: GetNextToken
 * ----------------------
 * The implementation of GetNextToken follows its behavioral
 * description as given in the interface: if the next character
 * is alphanumeric (i.e., a letter or digit), the function
 * searches to find an unbroken string of such characters and
 * returns the entire string.  If the current character is not
 * a letter or digit, a one-character string containing that
 * character is returned.
 */

char *GetNextToken(void)
{
    char ch;
	int pos, pos2;
    int start, end;
	int i;

    if (cpos >= buflen) Error("No more tokens");
	ch = buffer[cpos];

	if (ch == '<') {
		while (cpos < buflen) {
			start = cpos;
			pos = FindFirstMoreThanSign(buffer, start, buflen - 1);
			if (pos == -1) {
				cpos = buflen;
				return SubString(buffer, start, buflen - 1);
			}
			else {
				cpos = pos + 1;
				return SubString(buffer, start, pos);
			}
		}
	}
	else {
		while (cpos < buflen) {
			start = cpos;
			pos = FindFirstLessThanSign(buffer, start, buflen - 1);
			//printf("%d", pos);
			if (pos == -1) {
				cpos = buflen;
				return SubString(buffer, start, buflen - 1);
			}
			else {
				pos2 = FindFirstMoreThanSign(buffer, pos, buflen - 1);
				//printf("%d", pos2);
				if (pos2 == -1) {
					cpos = buflen;
					return SubString(buffer, start, buflen - 1);
				}
				else {
					for (i = pos; i < pos2; i++) {
						if (FindFirstLessThanSign(buffer, i, pos2 - 1) >= 0) {
							end = FindFirstLessThanSign(buffer, i, pos2 - 1);
							continue;
							//printf("%d", end);
						}
						break;
					}
					cpos = end;
					return SubString(buffer, start, end - 1);
				}
			}
		}
	}
	/*
	ch = buffer[cpos];
	if (ch == '<') {
		start = cpos;
		pos = cpos;
		while (pos < buflen && buffer[pos] != '>') {
			pos++;
			if (buffer[pos] == '<') {
				start = pos;
			}
		}
		/*
		if (buffer[pos] == '>') {
			cpos = pos + 1;
			return SubString(buffer, start, cpos - 1);
		}
		else {
			cpos = pos;
			return SubString(buffer, start, cpos - 1);
		}
		
		if (pos < buflen) {
			cpos = pos + 1;
			return SubString(buffer, start, pos);
		}
	}
	else {
		start = cpos;
		pos = cpos;
		while (pos < buflen && buffer[pos] != '>') {
			pos++;
			if (buffer[pos] == '<') {
				end = pos;
			}
		}
		if (buffer[pos] == '>') {
			cpos = end;
			return SubString(buffer, start, cpos - 1);
		}
		else {
			cpos = pos;
			return SubString(buffer, start, cpos - 1);
		}
	}
	*/
}

static int FindFirstLessThanSign(char *str, int p1, int p2)
{
	int len;
	int i;

	len = strlen(str);
	if (p1 > p2 || (p1 > len - 1 && p2 > len - 1)) {
		return -1;
	}
	else {
		if (p1 < 0) {
			p1 = 0;
		}
		if (p2 > len - 1) {
			p2 = len - 1;
		}
	}
	for (i = p1; i <= p2; i++) {
		if (str[i] == '<') {
			return i;
		}
	}
	return -1;
}

static int FindFirstMoreThanSign(char *str, int p1, int p2)
{
	int len;
	int i;

	len = strlen(str);
	if (p1 > p2 || (p1 > len - 1 && p2 > len - 1)) {
		return -1;
	}
	else {
		if (p1 < 0) {
			p1 = 0;
		}
		if (p2 > len - 1) {
			p2 = len - 1;
		}
	}
	for (i = p1; i <= p2; i++) {
		if (str[i] == '>') {
			return i;
		}
	}
	return -1;
}

/*
 * Function: AtEndOfLine
 * ---------------------
 * This implementation compares the current buffer position
 * against the saved length.
 */

boolean AtEndOfLine(void)
{
    return (cpos >= buflen);
}

static char *SubString(char *str, int p1, int p2)
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

static char *CharToString(char ch)
{
	char *cptr;

	cptr = (char *)malloc(2 * sizeof(char));
	cptr[0] = ch;
	cptr[1] = '\0';
	return (cptr);
}