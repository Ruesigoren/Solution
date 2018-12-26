/*
 * File: catloos.c
 * ---------------
 *
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include "caltools.h"

/*
 * Constants:
 * ----------
 * Days of the week are represented by the integers 0-6.
 * Months of the year are identified by the integers 1-12;
 * because this numeric representation for months is in
 * common use, no special constants are defined.
 */

#define Sunday     0
#define Monday     1
#define Tuesday    2
#define Wednesday  3
#define Thursday   4
#define Friday     5
#define Saturday   6

/*
 * Function: MonthName
 * Usage: name = MonthName(month);
 * -------------------------------
 * MonthName converts a numeric month in the range 1-12
 * into the string name for that month.
 */

strings MonthName(int month)
{
    switch (month) {
      case  1: return ("January");
      case  2: return ("February");
      case  3: return ("March");
      case  4: return ("April");
      case  5: return ("May");
      case  6: return ("June");
      case  7: return ("July");
      case  8: return ("August");
      case  9: return ("September");
      case 10: return ("October");
      case 11: return ("November");
      case 12: return ("December");
      default: return ("Illegal month");
    }
}

/*
 * Function: MonthDays
 * Usage: ndays = MonthDays(month, year);
 * --------------------------------------
 * MonthDays returns the number of days in the indicated
 * month and year.  The year is required to handle leap years.
 */

int MonthDays(int month, int year)
{
	switch (month) {
	case 2:
		if (IsLeapYear(year)) return (29);
		return (28);
	case 4: case 6: case 9: case 11:
		return (30);
	default:
		return (31);
	}
}

/*
 * Function: FirstDayOfMonth
 * Usage: weekday = FirstDayOfMonth(month, year);
 * ----------------------------------------------
 * This function returns the day of the week on which the
 * indicated month begins.  This program simply counts
 * forward from January 1, 1900, which was a Monday.
 */

int FirstDayOfMonth(int month, int year)
{
	int weekday, i;

	weekday = Monday;
	for (i = 1900; i < year; i++) {
		weekday = (weekday + 365) % 7;
		if (IsLeapYear(i)) weekday = (weekday + 1) % 7;
	}
	for (i = 1; i < month; i++) {
		weekday = (weekday + MonthDays(i, year)) % 7;
	}
	return (weekday);
}

/*
 * Function: IsLeapYear
 * Usage: if (IsLeapYear(year)) . . .
 * ----------------------------------
 * This function returns TRUE if year is a leap year.
 */

boolean IsLeapYear(int year)
{
	return (((year % 4 == 0) && (year % 100 != 0))
		|| (year % 400 == 0));
}
