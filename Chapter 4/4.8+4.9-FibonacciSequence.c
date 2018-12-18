/*
 * File: 4.8+4.9-FibonacciSequence.c
 * ---------------------------------
 * This program lists the Fibonacci sequence.
 * 
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

/*
 * Constant:length
 * ---------------
 * This constant controls the length of the list
 */

//#define length 15

main()
{
	int i, Fn, Fn1 = 0, Fn2 = 1;

	printf("This program lists the Fibonacci sequence.\n");

	/* 4.8 display the values in this sequence from F0 through F15 */
	/*
	for (i = 0; i <= length; i++) {
		if (i == 0) printf("%sF(%d)  = %5d\n",(i < 10)? " " : "", i, Fn1);
		else {
		    printf("%sF(%d)  = %5d\n", (i < 10) ? " " : "", i, Fn2);
			Fn = Fn1 + Fn2;
			Fn1 = Fn2;
			Fn2 = Fn;
		}
	}
	*/

	/* 4.9 display the values in this sequence that are less than 10,000.*/
	for (i = 0; Fn2 < 10000; i++) {
		if (i == 0) printf("%sF(%d)  = %5d\n", (i < 10) ? " " : "", i, Fn1);
		else {
			printf("%sF(%d)  = %5d\n", (i < 10) ? " " : "", i, Fn2);
			Fn = Fn1 + Fn2;
			Fn1 = Fn2;
			Fn2 = Fn;
		}
	}
}
