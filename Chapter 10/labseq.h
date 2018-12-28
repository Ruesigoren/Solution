/*
 * File: labseq.h
 * --------------
 * This file is the interface to a package that generates a sequence
 * of labels.
 */

#ifndef _labseq_h
#define _labseq_h

#include "genlib.h"

/*
 * Function: GetNextLabel
 * Usage: Lable = GetNextLabel();
 * -----------------------------
 * This function returns the next label.
 */

strings GetNextLabel(void);

/*
 * Function: SetLabelPrefix
 * Usage: SetLabelPrefix(prefix);
 * -----------------------------
 * This function sets the label prefix.
 */

void SetLabelPrefix(strings prefix);

/*
 * Function: SetLabelnumber
 * Usage: SetLabelnumber(nexrNumber);
 * ---------------------------------
 * This function sets the next label number.
 */

void SetLabelnumber(int nextNumber);

#endif
