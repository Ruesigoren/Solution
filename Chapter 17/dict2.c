/*
 * File:dict.c
 * -----------
 * This is the implements of dict.h interface.
 */

#include <stdio.h>

#include "strlib.h"
#include "genlib.h"
#include "dict2.h"

/* constants */

#define MaxEntriesNumber  200
#define MaxBufferSize  50

/* types */

typedef struct {
	strings word;
	strings definition;
} entryT;

struct dictionaryCDT {
	entryT entries[MaxEntriesNumber + 1];
	int nentries;
};


/* public functions */

dictionaryADT NewDictionary(strings filename)
{
	dictionaryADT dictionary;
	FILE *infile;
	errno_t err;
	char buff[MaxBufferSize];
	int nscan;
	char termch;
	int i = 0;

	dictionary = New(dictionaryADT);
	dictionary->nentries = 0;
	err = fopen_s(&infile, filename, "r");
	if (err) {
		Error("Cna't open %s", filename);
	}
	while (TRUE) {
		nscan = fscanf_s(infile, "%s%c", buff, sizeof(buff), &termch, sizeof(char));
		if (nscan == EOF) break;
		if (nscan != 2 || termch != '\n') {
			Error("Improper file format");
		}
		dictionary->entries[i].word = CopyStrings(buff);
		dictionary->entries[i].definition = NULL;
		i++;
	}
	dictionary->entries[i].word = NULL;
	dictionary->entries[i].definition = NULL;
	dictionary->nentries = i;

	return dictionary;
}

void FreeDictionary(dictionaryADT dictionary)
{
	FreeBlock(dictionary);
}

void Define(strings word, strings definition, dictionaryADT dictionary)
{
	int i;

	for (i = 0; i < dictionary->nentries; i++) {
		if (StringsEqual(word, dictionary->entries[i].word)) {
			dictionary->entries[i].definition = definition;
		}
	}
}

strings Lookup(strings word, dictionaryADT dictionary)
{
	int i;

	for (i = 0; i < dictionary->nentries; i++) {
		if (StringsEqual(word, dictionary->entries[i].word)) {
			return dictionary->entries[i].definition;
		}
	}
	return NULL;
}
