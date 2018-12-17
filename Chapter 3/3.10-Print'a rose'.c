/*
 * File: 3.10-Print'a rose'.c
 * --------------------------
 * This program print"a rose is a rose is a rose."on the screen
 * so that the word rose appears only once.
 */


#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

/*
 * a rose is a rose is a rose.
 * a ---- ---- ---- ---- ----.
 * a i=0  i=1  i=2  i=3  i=4 .
 * 
 * i = 0,2,4, The program prints " rose"
 * i = 1,3, The program prints " is a"
 */

main()
{
	int i;

	printf("a");
	for (i = 0; i < 5; i++) {
		if (i % 2) {
			printf(" is a");
		} else {
			printf(" rose");
		}
	}
	printf(".\n");
}
