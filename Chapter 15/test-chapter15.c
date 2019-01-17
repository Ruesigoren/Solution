/*
 * File:test-chapter15.c
 * ---------------------
 * This is the test codes of chapter 15.
 */

#include <stdio.h>

#include "genlib.h"

/* constants*/

#define MaxWord           25
#define MaxName           25
#define MaxLine           25
//#define MaxControlString  4

/* main program */

main()
{
	FILE *infile;
	char name[MaxName + 1];
	//char controlString[MaxControlString + 1];
	char line[MaxLine + 1];
	
	int nscan; 
	int value;
	char termch;

	/* controlString */
	//sprintf_s(controlString, sizeof(controlString), "%%%ds", MaxWord - 1);  //input/output formate
    /* %24s */															   //is useless when used secure functions
	//printf("%s\n", controlString);  //test


	//err = fopen_s(&infile, "Old File.txt", "r");
	//fscanf_s(infile, "%s", name, MaxName * sizeof(char));  
	//printf("%s\n", name);


	errno_t err = fopen_s(&infile, "NameValue.txt", "r");  //err
	if (err) {
		printf("The file fscanf.out was not opened\n");
	}
	else {
		//fscanf_s(infile, "%[^:]: %d", name, &value, sizeof(name));  //wrong!
		//nscan = fscanf_s(infile, "%[^:]: %d", name, sizeof(name), &value);  //non-numeric type, add buffer size 

		/* test for the possibility of an improperly formatted input file */
		/*
		while (TRUE) {
			nscan = fscanf_s(infile, "%[^:]: %d%c", name, sizeof(name), &value, &termch, sizeof(char));
			if (nscan == EOF) break;
			if (nscan != 3 || termch != '\n') Error("Bad input line");
		}
		*/
		while (fgets(line, MaxLine, infile) != NULL) {
			//nscan = sscanf_s(line, "%[^:]: %d%c", name, sizeof(name), &value, &termch, sizeof(char));
			nscan = sscanf_s(line, "%[^:,]: %c", name, sizeof(name), &termch, sizeof(char));
			printf("nscan = %d\n", nscan);
			printf("%s\n", name);
			if (nscan != 3 || termch != '\n') Error("Bad input line");
		}
		//printf("%s: %d\n", name, value);
	}
	
}