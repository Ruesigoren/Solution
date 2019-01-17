/*
 * File: CopyRemovingComments.c
 * ----------------------------
 * This function copies a program form one file to another,
 * removing all comments as it does so.
 */

#include <stdio.h>

#include <genlib.h>

static void CopyRemovingComments(FILE *infile, FILE *outfile)
{
	int ch, nch;
	boolean commentFlag;

	commentFlag = FALSE;
	while ((ch = getc(infile)) != EOF) {
		if (commentFlag) {
			if (ch == '*') {
				nch = getc(infile);
				if (nch == '/') {
					commentFlag = FALSE;
				}
				else {
					ungetc(nch, infile);
				}
			}
		}
		else {
			if (ch == '/ ') {
				nch = getc(infile);
				if (nch == '*') {
					commentFlag = TRUE;
				}
				else {
					ungetc(nch, infile);
				}
			}
			if (!commentFlag) ptc(ch, outfile);
		}
	}
}