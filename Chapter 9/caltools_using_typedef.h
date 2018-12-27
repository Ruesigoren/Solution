#ifndef _caltools_h
#define _caltools_h

#include "strlib.h"

typedef enum
{
	January = 1, Feburary, March, April, May, June, July, August, September, October, November, December
} monthT;

typedef enum
{
	Sunday, Monday, Tuesday, Wednesday, Thrusday, Friday, Saturday
} weekdayT;

/*
 * Function: MonthName
 * Usage: name = MonthName(month);
 * -------------------------------
 * MonthName converts a numeric month in the range 1-12
 * into the string name for that month.
 */

strings MonthName(monthT month);

/*
 * Function: MonthDays
 * Usage: ndays = MonthDays(month, year);
 * --------------------------------------
 * MonthDays returns the number of days in the indicated
 * month and year.  The year is required to handle leap years.
 */

int MonthDays(monthT month, int year);

/*
 * Function: FirstDayOfMonth
 * Usage: weekday = FirstDayOfMonth(month, year);
 * ----------------------------------------------
 * This function returns the day of the week on which the
 * indicated month begins.  This program simply counts
 * forward from January 1, 1900, which was a Monday.
 */

weekdayT FirstDayOfMonth(monthT month, int year);

/*
 * Function: IsLeapYear
 * Usage: if (IsLeapYear(year)) . . .
 * ----------------------------------
 * This function returns TRUE if year is a leap year.
 */

boolean IsLeapYear(int year);

#endif // !_caltools_h

#pragma once
