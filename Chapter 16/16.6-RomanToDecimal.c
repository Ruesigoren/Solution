/*
 * File: 16.6-RomanToDecimal.c
 * ---------------------------
 * This program takes a string representing a Roman numeral
 * and returns the corresponding decimal number.
 */

#include <stdio.h>

#include "simpio.h"
#include "genlib.h"
#include "strlib.h"

typedef struct {
	int M, D, C, L, X, V, I;
}RomanT;

/* function prototypes */

InitRoman(RomanT *r);
int ConvertStringToRoman(strings str, RomanT *r);
int RomanToDecimal(RomanT r);
strings DecimalToRoman(int d);
static strings ThousandsToRoman(int thousands);
static strings HundredsToRoman(int hundreds);
static strings TensToRoman(int tens);
static strings UnitsToRoman(int units);

/* main program */

main()
{
	strings line;
	strings roman;
	RomanT r;
	int i;
	int dec;

	printf("please enter a roman numeral.\n");
	while (TRUE) {
		printf("? ");
		line = GetLine();
		if (StringsLength(line) == 0) break;
		line = ConvertToUpperCase(line);
		i = ConvertStringToRoman(line, &r);
		if (i == -1) {
			printf("Unexpected alpha in Roman\n");
		}
		else {
			dec = RomanToDecimal(r);
			roman = DecimalToRoman(dec);  //check the input
			if (StringsEqual(line, roman)) {
				printf("%d\n", dec);
			}
			else {
				printf("Illegal roman numeral format\n");
			}
		}
	}
}

int ConvertStringToRoman(strings str, RomanT *r)
{
	strings s;
	int len;
	int i;

	InitRoman(r);
	len = StringsLength(str);
	for (i = 0; i < len; i++) {
		switch (IthChar(str, i)) {
		case 'M': r->M++;
			break;
		case 'D': r->D++;
			break;
		case 'C': r->C++;
			break;
		case 'L': r->L++;
			break;
		case 'X': r->X++;
			break;
		case 'V': r->V++;
			break;
		case 'I': r->I++;
			break;
		default:
			return -1;
		}
	}
	for (i = 0; i < len - 1; i++) {
		s = SubStrings(str, i, i + 1);
		if (StringsEqual(s, "CM") || StringsEqual(s, "CD")) {
			r->C -= 2;
		}
		if (StringsEqual(s, "XC") || StringsEqual(s, "XL")) {
			r->X -= 2;
		}
		if (StringsEqual(s, "IX") || StringsEqual(s, "IV")) {
			r->I -= 2;
		}
	}
	return 0;
}

InitRoman(RomanT *r)
{
	r->M = 0;
	r->D = 0;
	r->C = 0;
	r->L = 0;
	r->X = 0;
	r->V = 0;
	r->I = 0;
}

int RomanToDecimal(RomanT r)
{
	int dec;

	dec = r.M * 1000 + r.D * 500 + r.C * 100 + 
		  r.L * 50 + r.X * 10 + r.V * 5 + r.I * 1;

	return dec;
}

strings DecimalToRoman(int d)
{
	int tmp;
	int th, hu, te, un;
	strings sth, shu, ste, sun;
	strings r;

	r = New(strings);
	th = d / 1000;
	tmp = d % 1000;
	hu = tmp / 100;
	tmp = tmp % 100;
	te = tmp / 10;
	un = tmp % 10;
	sth = ThousandsToRoman(th);
	shu = HundredsToRoman(hu);
	ste = TensToRoman(te);
	sun = UnitsToRoman(un);
	r = Concat(Concat(Concat(sth, shu), ste), sun);
	return r;
}

static strings ThousandsToRoman(int thousands)
{
	strings sth;

	sth = New(strings);
	switch (thousands) {
	case 0: sth = "";
		break;
	case 1: sth = "M";
		break;
	case 2: sth = "MM";
		break;
	case 3: sth = "MMM";
		break;
	default:
		printf("Out of range\n");
		break;
	}
	return sth;
}

static strings HundredsToRoman(int hundreds)
{
	strings shu;

	shu = New(strings);
	switch (hundreds) {
	case 0: shu = "";
		break;
	case 1: shu = "C";
		break;
	case 2: shu = "CC";
		break;
	case 3: shu = "CCC";
		break;
	case 4: shu = "CD";
		break;
	case 5: shu = "D";
		break;
	case 6: shu = "DC";
		break;
	case 7: shu = "DCC";
		break;
	case 8: shu = "DCCC";
		break;
	case 9: shu = "CM";
		break;
	default:
		break;
	}
	return shu;
}

static strings TensToRoman(int tens)
{
	strings ste;

	ste = New(strings);
	switch (tens) {
	case 0: ste = "";
		break;
	case 1: ste = "X";
		break;
	case 2: ste = "XX";
		break;
	case 3: ste = "XXX";
		break;
	case 4: ste = "XL";
		break;
	case 5: ste = "L";
		break;
	case 6: ste = "LX";
		break;
	case 7: ste = "LXX";
		break;
	case 8: ste = "LXXX";
		break;
	case 9: ste = "XC";
		break;
	default:
		break;
	}
	return ste;
}

static strings UnitsToRoman(int units)
{
	strings sun;
	
	sun = New(strings);
	switch (units) {
	case 0: sun = "";
		break;
	case 1: sun = "I";
		break;
	case 2: sun = "II";
		break;
	case 3: sun = "III";
		break;
	case 4: sun = "IV";
		break;
	case 5: sun = "V";
		break;
	case 6: sun = "VI";
		break;
	case 7: sun = "VII";
		break;
	case 8: sun = "VIII";
		break;
	case 9: sun = "IX";
		break;
	default:
		break;
	}
	return sun;
}
