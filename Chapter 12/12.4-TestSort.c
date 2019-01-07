/*
 * File: 12.4-TestSort.c
 * ---------------------
 * This program tests the sort.c implementation.  In this example
 * the array is considered to be a list of exam scores.  The
 * test program reads in a list of scores, sorts them, and then
 * displays the sorted list.
 */

#include <stdio.h>
#include "genlib.h"
#include "strlib.h"
#include "simpio.h"
#include "sort.h"

/*
 * Constants
 * ---------
 * MaxScores -- Maximum number of scores
 * Sentinel  -- Value used to terminate input
 */

#define MaxStrings 100
#define Sentinel   "-1"

/* Private function prototypes */

static int GetStringArray(strings array[], int max, strings sentinel);
static void PrintStringArray(strings array[], int n);

/* Main program */

main()
{
	strings Str[MaxStrings];
    //int scores[MaxScores];
    int n;

    printf("Enter strings, one per line, ending\n");
    printf("with the sentinel value %s.\n", Sentinel);
    n = GetStringArray(Str, MaxStrings, Sentinel);
	Alphabetize(Str, n);
    printf("\nThe sorted strings are:\n");
    PrintStringArray(Str, n);
}

/*
 * Function: GetIntegerArray
 * Usage: n = GetIntegerArray(array, max, sentinel);
 * -------------------------------------------------
 * This function reads elements into an integer array by
 * reading values, one per line, from the keyboard.  The end
 * of the input data is indicated by the parameter sentinel.
 * The caller is responsible for declaring the array and
 * passing it as a parameter, along with its allocated
 * size.  The value returned is the number of elements
 * actually entered and therefore gives the effective size
 * of the array, which is typically less than the allocated
 * size given by max.  If the user types in more than max
 * elements, GetIntegerArray generates an error.
 */

static int GetStringArray(strings array[], int max, strings sentinel)
{
	/*
    int n, value;

    n = 0;
    while (TRUE) {
        printf(" ? ");
        value = GetInteger();
        if (value == sentinel) break;
        if (n == max) Error("Too many input items for array");
        array[n] = value;
        n++;
    }
    return (n);
	*/

	int n;
	strings value;

	n = 0;
	while (TRUE) {
		printf(" ? ");
		value = GetLine();
		if (StringsEqual(value, "-1")) break;
		if (n == max) Error("Too many input items for array");
		array[n] = value;
		n++;
	}
	return (n);
}

/*
 * Function: PrintIntegerArray
 * Usage: PrintIntegerArray(array, n);
 * -----------------------------------
 * This function displays the first n values in array,
 * one per line, on the console.
 */

static void PrintStringArray(strings array[], int n)
{
    int i;

    for (i = 0; i < n; i++) {
        printf("%s\n", array[i]);
    }
}
