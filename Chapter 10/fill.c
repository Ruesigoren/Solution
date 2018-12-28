/*
 * File: fill.c
 * ------------
 * This file implements the fill.h interface.
 */

#include <stdio.h>
#include <ctype.h>

#include "strlib.h"
#include "labseq.h"

/*
 * Private variables
 * -----------------
 * Margin  -- The margin.
 * cpos  -- Current cursor position.
 */

static int Margin;
static int cpos;

void SetCurrentPos(int position)
{
	cpos = position;
}

void SetFillMargin(int margin)
{
	Margin = margin;
}

void PrintFilledString(strings str)
{
	int len;

	len = StringsLength(str);
	if (cpos == 1 && cpos + len > Margin + 1) {
		Error("This string is too long to print");
	}
	if (cpos + len <= Margin) {
		printf("%s,", str);
		cpos += (len + 1);
		if (cpos <= Margin) {
			printf(" ");
			cpos++;
		}
		else {
			printf("\n");
			cpos = 1;
		}
	}
	else {
		printf("\n");
		cpos = 1;
		printf("%s,", str);
		cpos += (len + 1);
		if (cpos <= Margin) {
			printf(" ");
			cpos++;
		}
		else {
			printf("\n");
			cpos = 1;
		}
	}
}