/*
 * File: sort.h
 * ------------
 * This file provides an interface to a simple procedure
 * for sorting an integer array into increasing order.
 */

#ifndef _sort_h
#define _sort_h

/*
 * Function: SortIntegerArray
 * Usage: SortIntegerArray(array, n);
 * ----------------------------------
 * This function sorts the first n elements in array into
 * increasing numerical order.  In order to use this procedure,
 * you must declare the array in the calling program and pass
 * the effective number of elements as the parameter n.
 * In most cases, the array will have a larger allocated
 * size.
 */

void SortIntegerArray(int array[], int n);

/*
 * Function: SortRealArray
 * Usage: SortRealArray(array, n);
 * ----------------------------------
 * This function sorts the first n elements in array into
 * increasing numerical order.  In order to use this procedure,
 * you must declare the array in the calling program and pass
 * the effective number of elements as the parameter n.
 * In most cases, the array will have a larger allocated
 * size.
 */

void SortRealArray(double array[], int n);

/*
 * Function: Alphabetize
 * Usage: Alphabetize(array, n);
 * -----------------------------
 * This function sorts an array of strings into lexicographic order.
 * In order to use this procedure, you must declare the array in
 * the calling program and pass the effective number of elements 
 *  as the parameter n. In most cases, the array will have 
 * a larger allocated size.
 */

void Alphabetize(strings array[], int n);

#endif
