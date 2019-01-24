/*
 * File: sort.h
 * ------------
 * This file provides an interface to a simple procedure
 * for sorting an integer array into increasing order.
 */

#ifndef _sort_h
#define _sort_h

/*
 * Function: SelectSortIntegerArray
 * Usage: SelectSortIntegerArray(array, n);
 * ---------------------------------------
 * This function sorts the first n elements in array into
 * increasing numerical order.  In order to use this procedure,
 * you must declare the array in the calling program and pass
 * the effective number of elements as the parameter n.
 * In most cases, the array will have a larger allocated
 * size.
 */

void SelectSortIntegerArray(int array[], int n);

/*
 * Function: MergeSortIntegerArray
 * Usage: MergeSortIntegerArray(array, n);
 * --------------------------------------
 * This function sorts the first n elements in array into
 * increasing numerical order.  In order to use this procedure,
 * you must declare the array in the calling program and pass
 * the effective number of elements as the parameter n.
 * In most cases, the array will have a larger allocated
 * size.
 */

void MergeSortIntegerArray(int array[], int n);

#endif
