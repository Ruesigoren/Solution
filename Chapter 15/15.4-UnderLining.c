/*
 * File: 15.4-UnderLining.c
 * ------------------------
 * This program reads characters from one file to another,
 * converting text enclosed within asterisks into underlined character sequences.
 */

#include <windows.h>
#include <stdio.h>

#include "genlib.h"

/* constants */

#define fileName  "kandr.txt"
#define bufferSize  120

/* function prototypes */

void underlinePrint(char ch);

/* main program */

main()
{
	FILE *infile;
	errno_t err;
	char buffer[bufferSize];
	boolean underLineFlag;
	int i;

	err = fopen_s(&infile, fileName, "r");
	if (err) {
		printf("Can't open the file \"%s\"\n", fileName);
	}
	underLineFlag = FALSE;
	while (fgets(buffer, bufferSize, infile) != NULL) {
		for (i = 0; buffer[i] != '\n'; i++) {
			if (underLineFlag) {
				if (buffer[i] == '*') {
					if (buffer[i - 1] != ' ' &&
						buffer[i + 1] == ' ') {
						underLineFlag = FALSE;
					}
				}
				if (underLineFlag) {
					underlinePrint(buffer[i]);
				}
				else {
					i++;
					printf("%c", buffer[i]);
				}
			}
			else {
				if (buffer[i] == '*') {
					if (i == 0) {
						if (buffer[i + 1] != ' ') {
							underLineFlag = TRUE;
						}
					}
					else if (buffer[i - 1] == ' ' &&
						buffer[i + 1] != ' ') {
						underLineFlag = TRUE;
					}
				}
				if (underLineFlag) {
					i++;
					underlinePrint(buffer[i]);
				}
				else {
					printf("%c", buffer[i]);
				}
			}
		}
		printf("\n");
	}
}

void underlinePrint(char ch)
{
	HANDLE underLine;

	underLine = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(underLine, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | COMMON_LVB_UNDERSCORE);
	printf("%c", ch);
	SetConsoleTextAttribute(underLine, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
}
