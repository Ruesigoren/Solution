/*
 * File: 10.11-LabSeqTest.c
 * ------------------------
 * This programs tests the labseq.h interface.
 */

#include <stdio.h>
#include <ctype.h>

#include "genlib.h"
#include "strlib.h"
#include "simpio.h"
#include "labseq.h"

/* main program */

main()
{
	strings Label;
	strings Prefix;
	int StartNumber;

	printf("This program tests the labelseq abstraction.\n");
	printf("Prefix to use for labels: ");
	Prefix = GetLine();
	SetLabelPrefix(Prefix);
	printf("Starting number:");
	StartNumber = GetInteger();
	SetLabelnumber(StartNumber);
	for (int i = 0; i < 5; i++) {
		Label = GetNextLabel();
		printf("%s\n", Label);
	}
}
