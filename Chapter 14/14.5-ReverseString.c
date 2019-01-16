/*
 * File: 14.5-ReverseString.c
 * --------------------------
 * This program reverses the characters in its argument.
 */

#include <stdio.h>
#include <string.h>

/* constants */

#define Nelements  100

/* function prototypes */

void  ReverseString(char *source, char *reverse);

/* main program */

main()
{
	char *carray;
	char reverse[Nelements + 1];
	//int i;

	carray = "sfjlasjlsjfdajsldf8sdfs91010jjasfkdnfllas";
	//printf("%c\n", carray[0]);  //print the value of carray[0] before calling function.
	ReverseString(carray, reverse);  //the value of pointer caaray was changed in the called function, but the value restored after calling
	//printf("%c\n", carray[0]);  //print the value of carray[0] after calling function.

	/* test
	printf("%c\n", carray[0]);  //print the value of carray[0]
	for (i = 0; *carray != '\0'; carray++) {  //print the value of carray[0] with the value of pointer caaray changed
		printf("%c ", *carray);
	}
	printf("%c", carray[0]);  //now the value of carray[0] is unpredictable
	test */

	/*
	for (i = 0; reverse[i] != '\0'; i++) {  //one way of print char array 
		printf("%c", reverse[i]);
	}
	printf("\n");
	*/
	printf("The reversed string is: %s\n", reverse);
}

void  ReverseString(char *source, char *reverse)
{
	int len;

	len = strlen(source);
	/* test
	source += len - 1;  //changed the value of source pointer
	strncpy_s(reverse, Nelements + 1, source, 1);  
	--source;
	strncpy_s(reverse, Nelements + 1, source, 1);
	test */
	strncpy_s(reverse, Nelements + 1, source + len - 1, 1);
	--len;
	for (; len > 0; --len) {
		strncat_s(reverse, Nelements + 1, source + len - 1, 1);
	}
}
