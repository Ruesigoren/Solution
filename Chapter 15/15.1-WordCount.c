/*
 * File: 15.1-WordCount.c
 * ----------------------
 * This program reads a file and report how many lines,
 * words, and character appear in it. For the purposes of this program,
 * a word consists of a consecutive sequence of any characters except white-space characters.
 */

#include <stdio.h>
#include <ctype.h>

/*
 * Constants
 * ---------
 * FileName  -- Name of the file
 */

#define FileName    "lear.txt"
#define BufferSize   120

/* function prototypes */

void FileProcessing(FILE *infile);

/* main program */

main()
{
	FILE *infile;

	errno_t err = fopen_s(&infile, FileName, "r");
	if (err) {
		printf("The file was not opened\n");
	}
	else {
		FileProcessing(infile);
	}
}

void FileProcessing(FILE *infile)
{
	char buffer[BufferSize];
	int nline = 0;
	int nword = 0;
	int nchar = 0;
	int i;

	while (fgets(buffer, BufferSize, infile) != NULL) {
		for (i = 0; buffer[i] != '\n'; i++) {
			if (isblank(buffer[i])) nword++;
			if (isprint(buffer[i])) nchar++;
		}
		nline++;
	}
	nchar += nline;  //'\n' is not recorded, so n(char) need to plus 1 in every line 
	nword += nline;  //n(word) = n (blank) + 1, words is divided by blanks in every line
	printf("%-6s %s\n", "File:", FileName);
	printf("%-6s %4d\n", "Lines:", nline);
	printf("%-6s %4d\n", "Words:", nword);
	printf("%-6s %4d\n", "Chars:", nchar);
}
