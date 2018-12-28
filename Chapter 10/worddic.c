/*
 * File: worddic.c
 * ---------------
 * This file implements the worddic.h interface.
 */

#include <stdio.h>
#include <ctype.h>

#include "genlib.h"
#include "strlib.h"
#include "worddic.h"

/* constants */

#define WordNumber  400000
#define MaxWordLength  50
//#define FileName    "worddic.dat"
#define FileName    "words_alpha.txt"

/* global varables */

static strings dict[WordNumber + 1];
static int dictlen;
static int cpos;

/* private functions */

static void MergeSortStringArray(strings array[], int n);
static void Merge(strings array[], strings arr1[], int n1,
	strings arr2[], int n2);
static int FindStringInSortedArray(strings key,
	strings array[],
	int n);

/*
 * Function: InitDictionary
 * ------------------------
 * All this function has to do is initialize the private
 * variables used in the package.
 */

void InitDictionary(void)
{
	FILE *infile;
	strings filename = FileName;
	errno_t err;
	int nscan;
	char buff[MaxWordLength + 1];
	char termch;
	int i = 0;

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
		dict[i] = CopyStrings(buff);
		i++;
	}
	dictlen = i;
	dict[i] = NULL;
	MergeSortStringArray(dict, dictlen);
	cpos = 0;
}

/*
 * Function: GetNextDictionaryEntry
 * --------------------------------
 * The implementation of GetNextToken follows its behavioral
 */

strings GetNextDictionaryEntry(void)
{
	return dict[cpos++];
}

/*
 * Function: AtEndOfDictionary
 * --------------------------------
 * This implementation compares the current buffer position
 * against the saved length.
 */

boolean AtEndOfDictionary(void)
{
	return (cpos >= dictlen);
}

/*
 * Function: IsEnglishWord
 * -----------------------
 * The implementation 
 */

boolean IsEnglishWord(strings token)
{
	int pos;

	token = ConvertToLowerCase(token);
	pos = FindStringInSortedArray(token, dict, dictlen);
	if (pos == -1) return FALSE;
	return TRUE;
}

void MergeSortStringArray(strings array[], int n)
{
	strings *arr1, *arr2;
	int n1, n2, i;

	if (n > 1) {
		n1 = n / 2;
		n2 = n - n1;
		arr1 = NewArray(n1, strings);
		arr2 = NewArray(n2, strings);
		for (i = 0; i < n1; i++) arr1[i] = array[i];
		for (i = 0; i < n2; i++) arr2[i] = array[n1 + i];
		MergeSortStringArray(arr1, n1);
		MergeSortStringArray(arr2, n2);
		Merge(array, arr1, n1, arr2, n2);
		FreeBlock(arr1);
		FreeBlock(arr2);
	}
}

static void Merge(strings array[], strings arr1[], int n1,
	strings arr2[], int n2)
{
	int p, p1, p2;

	p = p1 = p2 = 0;
	while (p1 < n1 && p2 < n2) {
		if (StringsCompare(arr1[p1], arr2[p2]) < 0) {
			array[p++] = arr1[p1++];
		}
		else {
			array[p++] = arr2[p2++];
		}
	}
	while (p1 < n1) {
		array[p++] = arr1[p1++];
	}
	while (p2 < n2) {
		array[p++] = arr2[p2++];
	}
}

static int FindStringInSortedArray(strings key,
	strings array[],
	int n)
{
	int lh, rh, mid, cmp;

	lh = 0;
	rh = n - 1;
	while (lh <= rh) {
		mid = (lh + rh) / 2;
		cmp = StringsCompare(key, array[mid]);
		if (cmp == 0) return (mid);
		if (cmp < 0) {
			rh = mid - 1;
		}
		else {
			lh = mid + 1;
		}
	}
	return (-1);
}
