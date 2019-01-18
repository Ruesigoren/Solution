/*
 * File:dict.c
 * -----------
 * This is the implements of dict.h interface.
 */

#include <stdio.h>

#include "strlib.h"
#include "genlib.h"
#include "dict.h"

/* constants */

#define FileName  "dict.dat"
#define MaxEntriesNumber  100
#define MaxBufferSize  50

/* types */

typedef struct {
	strings word;
	strings definition;
} entryT;

typedef struct {
	entryT entries[MaxEntriesNumber + 1];
	int nentries;
} dictDB;

/*
 * Private variables
 * -----------------
 */

static dictDB dict;

/* public functions */

void InitDictionary(void)
{
	FILE *infile;
	errno_t err;
	char buff[MaxBufferSize];
	int nscan;
	char termch;
	int i = 0;

	err = fopen_s(&infile, FileName, "r");
	if (err) {
		Error("Cna't open %s", FileName);
	}
	while (TRUE) {
		nscan = fscanf_s(infile, "%s%c", buff, sizeof(buff), &termch, sizeof(char));
		if (nscan == EOF) break;
		if (nscan != 2 || termch != '\n') {
			Error("Improper file format");
		}
		dict.entries[i].word = CopyStrings(buff);
		dict.entries[i].definition = NULL;
		i++;
	}
	dict.entries[i].word = NULL;
	dict.entries[i].definition = NULL;
	dict.nentries = i;
}

void Define(strings word, strings definition)
{
	int i;

	for (i = 0; i < dict.nentries; i++) {
		if (StringsEqual(word, dict.entries[i].word)) {
			dict.entries[i].definition = definition;
		}
	}
}

strings Lookup(strings word)
{
	int i;

	for (i = 0; i < dict.nentries; i++) {
		if (StringsEqual(word, dict.entries[i].word)) {
			return dict.entries[i].definition;
		}
	}
	return NULL;
}
