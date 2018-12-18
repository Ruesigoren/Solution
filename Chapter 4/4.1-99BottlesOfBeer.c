/*
 * Filename£º4.1-99BottlesOfBeer.c
 * -------------------------------
 * This program generate the lyrics of the song <99 bottles of beer>
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

/* 
 * Constant: bottlenumber
 * ----------------------
 * To change the length of lyrics, please modify this constant.
 */

#define bottlenumber 99

main()
{
	int i;

	for (i = bottlenumber; i > 0; i--)
	{
		printf("%d bottle%s of beer on the wall.\n", i, (i > 1) ? "s" : "");
		printf("%d bootle%s of beer.\n", i, (i > 1) ? "s" : "");
		printf("you take one down, pass it around.\n");
		printf("\n");
	}
}