/*
 * File: scanner.c
 * ---------------
 * This file implements the scanner.h interface.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "genlib.h"
#include "scanner.h"

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
    int start;

    if (cpos >= buflen) Error("No more tokens");
	ch = buffer[cpos];
    if (isalnum(ch)) {
        start = cpos;
        while (cpos < buflen && isalnum(buffer[cpos])) {
            cpos++;
        }
        return (SubString(buffer, start, cpos - 1));
    } else {
        cpos++;
        return (CharToString(ch));
    }
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