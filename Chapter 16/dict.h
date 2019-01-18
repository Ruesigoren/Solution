/*
 * File: dict.h
 * --------------
 * This interface exports functions for defining and looking 
 * up words in a dictionary. The dictionary is maintained
 * in static storage private to the implementation.
 */

#ifndef _dict_h
#define _dict_h

#include "genlib.h"

/*
 * Function: InitDictionary
 * Usage: InitDicitionary ();
 * This function initializes the dictionary to be empty and must be
 * called before any of the other operations are used.
 */

void InitDictionary(void);

/*
 * Function: Define
 * Usage: Define (word, definition);
 * ------------------------------------------ 
 * This function defines the word, using the indicated definition.
 * Any previous definition for word is lost. If defining this
 * word would exceed the capacity of the dictionary, and error is
 * generated.
 */

void Define(strings word, strings definition);

/*
 * Function: Lookup
 * Usage: str = Lookup (word);
 * -------------------------------------
 * This function looks up the word in the dictionary and returns
 * its definition. If the word has not been defined, lookup 
 * returns NULL.
 */

strings Lookup(strings word);

#endif