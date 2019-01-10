/*
 * File: 13.2-GetDate.c
 * --------------------
 * This program reads in a date from the user in the form dd-mmm-yy
 * where dd is a one- or two-digit day, mmm is a three-letter abbreviation for a month, and yy is a two-digit year.
 */

#include <stdio.h>
#include <ctype.h>

#include "simpio.h"
#include "strlib.h"

/* constants */

strings MonthName[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                          "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

/* function prototypes */

void GetDate(int *dp, int *mp, int *yp);

/*
boolean IsLegalNum(strings token);
boolean IsLegalWord(strings token);
int MonthDays(int month, int year);
boolean IsLeapYear(int year);
*/

/* main program */

main()
{
	int day, month, year;
	
	printf("Enter a date as dd-mmm-yy: ");
	GetDate(&day, &month, &year);
	printf("Day = %d\n", day);
	printf("Month = %d\n", month);
	printf("Year = %d\n", year);
}

void GetDate(int *dp, int *mp, int *yp)
{
	strings line;
	strings day, month, year;
	//int  actualyear;

	line = GetLine();
	day = SubStrings(line, 0, 1);
	//if (!IsLegalNum(day)) printf("Illegal day input\n");
	*dp = StringsToInteger(day);

	month = SubStrings(line, 3, 5);
	//if (!IsLegalWord(month)) printf("Error -1 Illegal day input\n");

	year = SubStrings(line, 7, 8);
	//if (!IsLegalNum(year)) printf("Illegal year input\n");
	*yp = StringsToInteger(year);

	for (int i = 0; i < 12; i++) {
		if (StringsEqual(month, MonthName[i])) {
			*mp = i + 1;
			break;
		}
		if (i == 11) {
			printf("Illegal month input");
		}
	}

	/*
	if (*yp >= 90) {
		actualyear = 1900 + *yp;
	}
	else {
		actualyear = 2000 + *yp;
	}
		
	if (*dp > MonthDays(*mp, actualyear) || *dp <= 0) {
		printf("Illegal date\n");
	}
	*/
}

/*
boolean IsLegalNum(strings token)
{
	int i;

	for (i = 0; i < StringsLength(token); i++) {
		if (!isdigit(IthChar(token, i))) return (FALSE);
	}
	return (TRUE);
}
boolean IsLegalWord(strings token)
{
	int i;

	for (i = 0; i < StringsLength(token); i++) {
		if (!isalpha(IthChar(token, i))) return (FALSE);
	}
	return (TRUE);
}

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

boolean IsLeapYear(int year)
{
	return (((year % 4 == 0 && year % 100 != 0) ||
		year % 400 == 0));
}
*/