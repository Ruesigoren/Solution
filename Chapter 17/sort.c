/*
 * File: sort.c
 * ------------
 * This file implements the sort.h interface using the merge
 * sort algorithm.
 */

#include <stdio.h>
#include "genlib.h"
#include "sort.h"

/* Private function prototypes */

static int FindSmallestInteger(int array[], int low, int high);
static void SwapIntegerElements(int array[], int p1, int p2);
static void Merge(int array[], int arr1[], int n1,
                               int arr2[], int n2);

/*
 * Function: SelectSortIntegerArray
 * --------------------------------
 * This implementation uses an algorithm called selection sort,
 * which can be described in English as follows.  With your left
 * hand, point at each element in the array in turn, starting at
 * index 0.  At each step in the cycle:
 *
 * (1)  Find the smallest element in the range between your left
 *      hand and the end of the array, and point at that element
 *      with your right hand.
 *
 * (2)  Move that element into its correct index position by
 *      switching the elements indicated by your left and right
 *      hands.
 */

void SelectSortIntegerArray(int array[], int n)
{
	int lh, rh;

	for (lh = 0; lh < n; lh++) {
		rh = FindSmallestInteger(array, lh, n - 1);
		SwapIntegerElements(array, lh, rh);
	}
}

/*
 * Function: MergeSortIntegerArray
 * -------------------------------
 * This implementation uses an algorithm called merge sort, which
 * consists of the following steps:
 *
 * (1)  Divide the array into two halves.
 * (2)  Sort each half recursively.
 * (3)  Recombine the sorted pieces by calling the Merge function.
 */

void MergeSortIntegerArray(int array[], int n)
{
    int i, n1, n2;
    int *arr1, *arr2;

    if (n > 1) {
        n1 = n / 2;
        n2 = n - n1;
        arr1 = NewArray(n1, int);
        arr2 = NewArray(n2, int);
        for (i = 0; i < n1; i++) arr1[i] = array[i];
        for (i = 0; i < n2; i++) arr2[i] = array[n1 + i];
        MergeSortIntegerArray(arr1, n1);
        MergeSortIntegerArray(arr2, n2);
        Merge(array, arr1, n1, arr2, n2);
        FreeBlock(arr1);
        FreeBlock(arr2);
    }
}

/*
 * Function: Merge
 * Usage: Merge(array, arr1, n1, arr2, n2);
 * ----------------------------------------
 * This function merges two sorted arrays (arr1 and arr2) into a
 * single array.  Because the input arrays are sorted, the Merge
 * implementation can always select the first unused element in
 * one of the input arrays to fill the next position in array.
 */

static void Merge(int array[], int arr1[], int n1,
                               int arr2[], int n2)
{
    int p, p1, p2;

    p = p1 = p2 = 0;
    while (p1 < n1 && p2 < n2) {
        if (arr1[p1] < arr2[p2]) {
            array[p++] = arr1[p1++];
        } else {
            array[p++] = arr2[p2++];
        }
    }
    while (p1 < n1) array[p++] = arr1[p1++];
    while (p2 < n2) array[p++] = arr2[p2++];
}

static int FindSmallestInteger(int array[], int low, int high)
{
    int i, spos;

    spos = low;
    for (i = low; i <= high; i++) {
        if (array[i] < array[spos]) spos = i;
    }
    return (spos);
}

/*
 * Function: SwapIntegerElements
 * Usage: SwapIntegerElements(array, p1, p2);
 * ------------------------------------------
 * This function swaps the elements in array at index
 * positions p1 and p2.
 */

static void SwapIntegerElements(int array[], int p1, int p2)
{
    int tmp;

    tmp = array[p1];
    array[p1] = array[p2];
    array[p2] = tmp;
}
