/*
 * File: 16.2-LibraryDB.c
 * ----------------------
 * The procedure SearchBySubject takes as parameters the library database and a subject string.
 * For each book in the library that lists the subject string as one of its subject headings,
 * SearchBySubject should display the title, the name of the first author,
 * and the Library of Congress catalog number of the book.
 */

#include <stdio.h>

#include "simpio.h"
#include "genlib.h"
#include "strlib.h"

/* constants */

#define FileName  "library.dat"
#define MaxBookNumber  1000
#define MaxAuthorNumber  5
#define ISBNnumber  13
#define MaxSubjectHeadingNumber  5

/* types */

typedef struct {
	strings title;
	strings authors[MaxAuthorNumber + 1];
	strings ISBN;
	strings subjectheading[MaxSubjectHeadingNumber + 1];
	strings publisher;
	int yearofpublication;
	boolean iscirculating;
} *bookT;

typedef struct {
	strings name;
	bookT book[1000];
	int nbook;
} *libraryDB;

/* function prototypes */

static libraryDB ReadDataBase(void);
static boolean ReadOneBook(FILE *infile, libraryDB lib);
static void ReadAuthors(FILE *infile, bookT book);
static void ReadSubjectHeading(FILE *infile, bookT book);
static void SearchBySubject(libraryDB lib, strings subject);

/* main program */

main()
{
	libraryDB libdata;
	strings subject;

	libdata = ReadDataBase();
	//printf("%s\n", libdata->book[1]->authors[3]);
	while (TRUE) {
		printf("Please enter search subject: ");
		subject = GetLine();
		if (StringsEqual(subject, "")) break;
		SearchBySubject(libdata, subject);
	}
}

static libraryDB ReadDataBase(void)
{
	FILE *infile;
	errno_t err;
	libraryDB libdata;

	err = fopen_s(&infile, FileName, "r");
	if (err) {
		printf("Can't open %s\n", FileName);
	}
	libdata = New(libraryDB);
	libdata->name = ReadLine(infile);
	libdata->nbook = 0;
	while (ReadOneBook(infile, libdata)) {
		libdata->nbook++;
	}
	fclose(infile);
	return libdata;
}

static boolean ReadOneBook(FILE *infile, libraryDB lib)
{
	bookT book;
	strings line;

	book = New(bookT);
	line = ReadLine(infile);
	book->title = line;
	//printf("%s\n", book->title);
	ReadAuthors(infile, book);
	line = ReadLine(infile);
	//printf("%s\n", line);
	if (StringsLength(line) > ISBNnumber) {
		Error("Illegal ISBN");
	}
	book->ISBN = line;
	ReadSubjectHeading(infile, book);
	//printf("%s\n", book->subjectheading[3]);
	book->publisher = ReadLine(infile);
	//printf("%s\n", book->publisher);
	book->yearofpublication = StringsToInteger(ReadLine(infile));
	//printf("%d\n", book->yearofpublication);
	book->iscirculating = (boolean)StringsToInteger(ReadLine(infile));
	//printf("%d\n", book->iscirculating);
	lib->book[lib->nbook] = book;
	if (ReadLine(infile) == NULL) return FALSE;
	return TRUE;	
}

static void ReadAuthors(FILE *infile, bookT book)
{
	strings line;
	int i = 0;
	int len;
	int tmp = 0;
	int cpos = 0;

	line = ReadLine(infile);
	len = StringsLength(line);
	cpos = FindChar('/', line, cpos + 1);
	if (cpos == -1) {
		book->authors[0] = line;
	}
	else { 
		while (cpos != -1) {
			book->authors[i] = SubStrings(line, tmp, cpos - 1);
			tmp = cpos + 1;
			cpos = FindChar('/', line, cpos + 1);
			if (i == MaxAuthorNumber - 1) {
				Error("Illegal author format");
			}
			i++;
		}
		book->authors[i] = SubStrings(line, tmp, len - 1);
		book->authors[i + 1] = NULL;
	}
}

static void ReadSubjectHeading(FILE *infile, bookT book)
{
	strings line;
	int i = 0;
	int len;
	int tmp = 0;
	int cpos = 0;

	line = ReadLine(infile);
	len = StringsLength(line);
	cpos = FindChar('/', line, cpos + 1);
	if (cpos == -1) {
		book->authors[0] = line;
	}
	else {
		while (cpos != -1) {
			book->subjectheading[i] = SubStrings(line, tmp, cpos - 1);
			tmp = cpos + 1;
			cpos = FindChar('/', line, cpos + 1);
			if (i == MaxSubjectHeadingNumber - 1) {
				Error("Illegal subject heading format");
			}
			i++;
		}
		book->subjectheading[i] = SubStrings(line, tmp, len - 1);
		book->subjectheading[i + 1] = NULL;
	}
}

static void SearchBySubject(libraryDB lib, strings subject)
{
	int i, j;
	int mathchFlag = 0;
	strings tmp;

	subject = ConvertToLowerCase(subject);
	for (i = 0; i < lib->nbook + 1; i++) {
		for (j = 0; lib->book[i]->subjectheading[j] != NULL; j++) {
			tmp = lib->book[i]->subjectheading[j];
			tmp = ConvertToLowerCase(tmp);
			if (StringsEqual(tmp, subject)) {
				mathchFlag = 1;
				printf("Books:\n");
				printf("Title: %s\n", lib->book[i]->title);
				printf("First Author: %s\n", lib->book[i]->authors[0]);
				printf("ISBN: %s\n", lib->book[i]->ISBN);
			}
		}
		printf("\n");
	}
	if (mathchFlag == 0) {
		printf("Sorry, No match items.\n");
	}
}
