/*
 * File: 9.11-DateString.c
 * -----------------------
 * This program returns a string consisting of the day of the month, a hyphen,
 * the first three letters in the name of the month, another hyphen,
 * and the last two digits of the year.
 */

#include <ctype.h>

#include "simpio.h"
#include "strlib.h"
#include "genlib.h"

/* function prototypes */

strings DateStrings(int day, int month, int year);
strings MonthName(int month);
strings YearName(int year);

/* main program */

main()
{
	int day, month, year;

	printf("day: ");
	day = GetInteger();
	printf("month: ");
	month = GetInteger();
	printf("year: ");
	year = GetInteger();
	printf("Date:%s\n", DateStrings(day, month, year));
}

strings DateStrings(int day, int month, int year)
{
	strings Sday, Smonth, Syear;
	strings Date;

	Sday = IntegerToStrings(day);
	Smonth = MonthName(month);
	Syear = YearName(year);
	Date = Concat(Concat(Concat(Concat(Sday, "-"), Smonth), "-"), Syear);
	return (Date);
}

strings MonthName(int month)
{
	switch (month) {
	case  1: return ("Jan");
	case  2: return ("Feb");
	case  3: return ("Mar");
	case  4: return ("Apr");
	case  5: return ("May");
	case  6: return ("Jun");
	case  7: return ("Jul");
	case  8: return ("Aug");
	case  9: return ("Sep");
	case 10: return ("Oct");
	case 11: return ("Nov");
	case 12: return ("Dec");
	default: return ("Illegal month");
	}
}

strings YearName(int year)
{
	return (SubStrings(IntegerToStrings(year), 2, 3));
}
