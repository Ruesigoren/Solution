/*
 * File: scanner.c
 * ---------------
 * This file implements the scanner.h interface.
 */

#include <stdio.h>
#include <ctype.h>

#include "strlib.h"
#include "modified_scanner.h"

/*
 * Private variables
 * -----------------
 * buffer  -- Private copy of the string passed to InitScanner
 * buflen  -- Length of the buffer, saved for efficiency
 * cpos    -- Current character position in the buffer
 */

static boolean uppercaseFlag = TRUE;
static boolean fliterFlag = TRUE;
static strings buffer;
static int buflen;
static int cpos;

/*
 * Function: InitScanner
 * ---------------------
 * All this function has to do is initialize the private
 * variables used in the package.
 */

void InitScanner(strings line)
{
	buffer = line;
	buflen = StringsLength(buffer);
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

strings GetNextToken(void)
{
	if (fliterFlag) {
		while (isspace(IthChar(buffer, cpos))) {
			cpos++;
		}
		return (GetToken());
	}
	else {
		return (GetToken());
	}
}

strings GetToken(void)
{
	char ch;
	int i, spos;
	strings token;

	if (cpos >= buflen) {
		Error("No more tokens");
	}
	for (i = 0; i < buflen; i++) {
		ch = IthChar(buffer, i);
		if (!(isdigit(ch) || isblank(ch) || isop(ch))) {
			Error("Illegal Input at %dth char", i);
		}
	}
	if (isop(IthChar(buffer, buflen - 1))) {
		Error("Illegal Input at end");
	}

	ch = IthChar(buffer, cpos);
	if (isop(ch)) {
		spos = cpos;
		while (cpos < buflen && isop(IthChar(buffer, cpos))) {
			cpos++;
		}
		token = SubStrings(buffer, spos, cpos - 1);
		return (ReturnUppercaseTokens(token));
	}
	else if (isdigit(ch)) {
		spos = cpos;
		while (cpos < buflen && isdigit(IthChar(buffer, cpos))) {
			cpos++;
		}
		token = SubStrings(buffer, spos, cpos - 1);
		return (ReturnUppercaseTokens(token));
	}
	else {
		cpos++;
		token = CharToStrings(ch);
		return (ReturnUppercaseTokens(token));
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
	int len;

	if (fliterFlag) {
		len = buflen;
		while (isspace(IthChar(buffer, len - 1))) {
			len--;
		}
		return (cpos >= len);
	}
	else {
		return (cpos >= buflen);
	}
}

/*
 * Function: ReturnUppercaseTokens
 * This function reverse the tokens into uppercase.
 */

strings ReturnUppercaseTokens(strings token)
{
	if (uppercaseFlag) {
		return (ConvertToUpperCase(token));
	}
	else {
		return token;
	}
}

/*
 * Function: isdigiop
 * This function determines whether a char is a digit of an operator.
 */

boolean isop(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*'
		|| ch == '/' || ch == '%') {
		return TRUE;
	}
	else {
		return FALSE;
	}
}
