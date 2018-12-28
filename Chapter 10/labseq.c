/*
 * File: labseq.c
 * --------------
 * This file implements the labseq.h interface.
 */
#include <stdio.h>
#include <ctype.h>

#include "strlib.h"
#include "labseq.h"

/*
 * Private variables
 * -----------------
 * LabelNumber  -- The order of a label
 * LabelPrefix  -- The prefix of a label
 */

static int LabelNumber = 0;
static strings LabelPrefix;

/*
 * Function: GetNextLabel
 * ----------------------
 * If doesn't get a lable prefix from user's input, the function
 * will use ¡°Lable" as the default prefix.
 */
strings GetNextLabel(void)
{
	LabelNumber++;
	if (StringsEqual(LabelPrefix, "")) {
		return (Concat("Label", IntegerToStrings(LabelNumber)));
	}
	else {
		return (Concat(LabelPrefix, IntegerToStrings(LabelNumber)));
	}
}


/*
 * Function: SetLabelPrefix
 * -------------------------
 * This implementation sets the label prefix.
 */

void SetLabelPrefix(strings prefix)
{
	LabelPrefix = prefix;
}

/*
 * Function: SetLabelnumber
 * -------------------------
 * This implementation sets the label number.
 */

void SetLabelnumber(int nextNumber)
{
	LabelNumber = nextNumber - 1;
}
