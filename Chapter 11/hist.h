/*
 * File: hist.h
 * ------------
 * This file is the interface of histogram package.
 */

#ifndef _hist_h
#define _hist_h

void SetDataNumber(int ndata);
void SetMaxandMin(int max, int min);
void SetGroupNumber(int ngroup);
void SetGroupRange(int group, int lowerlimit, int upperlimit);
int GetIntegerArray(int array[], int max, int sentinel);
void DataCount(int array[], int n);
void ClearIntegerArray(int array[], int n);
void FormatOutput(void);
void printstars(int nstars);

#endif // !_hist_h
