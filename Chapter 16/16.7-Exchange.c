/*
 * File: 16.7-Exchange.c
 * ---------------------
 * This program performs these steps:
 * a. Read in the exchange.dat data file into a suitable internal data structure.
 * b. Ask the user to enter two currency names:
 *    that of the old currency being converted and of the new currency being returned.
 * c. Ask for a value in the original currency.
 * d. Display the resulting value in the second currency.
 */

#include <stdio.h>

#include "simpio.h"
#include "genlib.h"
#include "strlib.h"

/* constants */

#define FileName  "exchange.dat"
#define MaxCurrencyNumber  100
#define MaxBufferSize  50

/* types */

typedef struct {
	strings currencyname;
	double exchangerate;
} currencyT;

typedef struct{
	currencyT currency[MaxCurrencyNumber + 1];
	int ncurrency;
} currencyDB;

/* function prototypes */

static currencyDB ReadCurrencyDatabase(void);
double CurrencyConvert(currencyDB db, strings From, double FUnits, strings Into);
double SearchCurrencyRateByName(currencyDB db, strings Name);

/* main program */

main()
{
	currencyDB db;
	strings from, into;
	double fromunits;
	double intounits;

	db = ReadCurrencyDatabase();
	printf("Convert from: ");
	from = GetLine();
	printf("Into: ");
	into = GetLine();
	printf("How many units of type mark? ");
	fromunits = GetReal();
	intounits = CurrencyConvert(db, from, fromunits, into);
	printf("%g %s = %g %s\n", fromunits, from, intounits, into);
}

static currencyDB ReadCurrencyDatabase(void)
{
	FILE *infile;
	errno_t err;
	currencyDB db;
	int i = 0;
	int nscan;
	char buff[MaxBufferSize];
	char termch;

	err = fopen_s(&infile, FileName, "r");
	if (err) {
		printf("Can't open %s", FileName);
	}
	while (TRUE) {
		nscan = fscanf_s(infile, "%s %lf%c", 
			                     buff, sizeof(buff),
			                     &(db.currency[i].exchangerate),
			                     &termch, sizeof(char));
		if (nscan == EOF) break;
		//printf("%d\n", nscan);
		if (nscan != 3 || termch != '\n') {
			Error("Improper file format");
		}
		db.currency[i].currencyname = CopyStrings(buff);
		//printf("%s\n", db.currency[i].currencyname);
		//printf("%f\n", db.currency[i].exchangerate);
		i++;
	}
	db.ncurrency = i;
	return db;
}

double CurrencyConvert(currencyDB db, strings From, double FUnits, strings Into)
{
	double fromRate, intoRate;

	fromRate = SearchCurrencyRateByName(db, From);
	if (fromRate == -1) {
		Error("Unknow currency convert from");
	}
	intoRate = SearchCurrencyRateByName(db, Into);
	if (intoRate == -1) {
		Error("Unkown currency convert into");
	}
	return FUnits * fromRate / intoRate;
}

double SearchCurrencyRateByName(currencyDB db, strings Name)
{
	int i;

	for (i = 0; i < db.ncurrency; i++) {
		if (StringsEqual(Name, db.currency[i].currencyname)) {
			return db.currency[i].exchangerate;
		}
	}
	return -1;
}
