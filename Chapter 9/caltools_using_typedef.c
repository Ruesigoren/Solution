/*
 * File: catloos.c
 * ---------------
 * Using typedef
 */

#include <stdio.h>

#include "genlib.h"
#include "simpio.h"
#include "caltools_using_typedef.h"

/*
 * Function: MonthName
 * Usage: name = MonthName(month);
 * -------------------------------
 * MonthName converts a numeric month in the range 1-12
 * into the string name for that month.
 */

strings MonthName(monthT month)
{
	switch (month) {
	case  January: return ("January");
	case  Feburary: return ("Feburary");
	case  March: return ("March");
	case  April: return ("April");
	case  May: return ("May");
	case  June: return ("June");
	case  July: return ("July");
	case  August: return ("August");
	case  September: return ("September");
	case  October: return ("October");
	case  November: return ("November");
	case  December: return ("December");
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

int MonthDays(monthT month, int year)
{
	switch (month) {
	case Feburary:
		if (IsLeapYear(year)) return (29);
		return (28);
	case April: case June: case September: case November:
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

weekdayT FirstDayOfMonth(monthT month, int year)
{
	weekdayT weekday;
	int i;

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
