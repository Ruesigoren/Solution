/*
 * File: 16.9-DictTest.c
 * ---------------------
 * This program tests the dict.h interface.
 */


#include <stdio.h>

#include "dict.h"

/* main program */

main()
{
	InitDictionary();
	Define("add", "dda");
	printf("%s\n", Lookup("add"));
}
