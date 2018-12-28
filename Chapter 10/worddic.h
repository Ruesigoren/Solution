/*
 * File: worddic.h
 * ---------------
 * This file is the interface to a package that searches word
 * in a dictionary.
 */

#ifndef _worddic_h
#define _worddic_h

#include "genlib.h"

/*
 * Function: InitDictionary
 * Usage: InitDictionary();
 * ---------------------------
 * This function initializes the dictionary package and sets it up so that
 * it search words from dictionary.  After InitDictionary has been called,
 * the first call to GetNextDictionaryEntry will get the first word from the
 * dictionary, the next call will return the second word,
 * and so on.
 */

void InitDictionary(void);

/*
 * Function: GetNextDictionaryEntry
 * Usage: word = GetNextDictionaryEntry();
 * ---------------------------------------
 * This function returns the next word in the dictionary.
 */

strings GetNextDictionaryEntry(void);

/*
 * Function: AtEndOfDictionary
 * Usage: if (AtEndOfDictionary()) . . .
 * --------------------------------------
 * This function returns TRUE when the program has reached
 * the end of the dictionary.
 */

boolean AtEndOfDictionary(void);

/*
 * Function: IsEnglishWord
 * Usage: if (IsEnglish(token)) ...
 * --------------------------------
 * IsEnglishWord returns TRUE if the token is a legal english word
 */

boolean IsEnglishWord(strings token);

#endif // !_worddic.h
