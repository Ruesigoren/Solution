/*
 * File: 17.9-Dict2Test.c
 * ----------------------
 * This program tests the dict.h interface.
 */


#include <stdio.h>

#include "dict2.h"

/* main program */

main()
{
	dictionaryADT dict, dict2;

	dict = NewDictionary("dict.dat");
	dict2 = NewDictionary("dict2.dat");
	Define("add", "dda", dict);
	printf("%s\n", Lookup("add", dict));
	Define("axis", "hello", dict2);
	printf("%s\n", Lookup("axis", dict2));
}
