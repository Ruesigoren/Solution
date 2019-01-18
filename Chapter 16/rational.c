/*
 * File:rational.c
 * ---------------
 * This is the implemention of rational.h
 */

#include <stdio.h>
#include <math.h>

#include "strlib.h"
#include "simpio.h"
#include "genlib.h"
#include "rational.h"


 /* Private function prototypes */

static boolean IsZeroRatioanl(ratioanlT r);
static int GCD(int x, int y);
static void rationalReduction(ratioanlT *r);
static void Reduction(int *x, int *y);

/* public function */

ratioanlT CreateRational(int num, int den)
{
	ratioanlT r;

	if (den == 0) {
		Error("den can't be 0");
	}
	r.num = num;
	r.den = den;
	return r;
}

ratioanlT AddRational(ratioanlT r1, ratioanlT r2)
{
	ratioanlT r;

	if (IsZeroRatioanl(r1) && IsZeroRatioanl(r2)) {
		r.den = 0;
		r.num = 0;
		return r;
	}
	else if (IsZeroRatioanl(r1)){
		return r2;
	}
	else if (IsZeroRatioanl(r2)){
		return r1;
	}
	rationalReduction(&r1);
	rationalReduction(&r2);
	r.den = r1.den * r2.den;
	r.num = r1.num * r2.den + r1.den * r2.num;
	if (r.num == 0) {
		r.den = 0;
		return r;
	}
	else {
		rationalReduction(&r);
	}
	return r;
}

ratioanlT MultiplyRational(ratioanlT r1, ratioanlT r2)
{
	ratioanlT r;
	if (IsZeroRatioanl(r1) || IsZeroRatioanl(r2)) {
		r.num = 0;
		r.den = 0;
		return r;
	}
	Reduction(&r1.num, &r2.den);
	Reduction(&r1.den, &r2.num);
	r.num = r1.num * r2.num;
	r.den = r1.den * r2.den;
	return r;
}

ratioanlT GetRational(void)
{
	strings line;
	ratioanlT r;

	r.den = 0;
	r.num = 0;
	while (TRUE) {
		line = GetLine();
		if (StringsEqual(line, "0")) {
			return r;
		}
		else {
			sscanf_s(line, "%d%*[/]%d", &r.num, &r.den);
			if (r.den == 0) {
				break;
			}
			return r;
		}
	}
	printf("den can't be 0\n");
	printf("please retry.\n");
	return r;
}

void PrintRational(ratioanlT r)
{
	if (r.num == 0) {
		printf("0");
	}
	else {
		printf("%d/%d", r.num, r.den);
	}
}

/* private function */

static boolean IsZeroRatioanl(ratioanlT r)
{
	if (r.num == 0 && r.den != 0) {
		return TRUE;
	}
	return FALSE;
}

static int GCD(int x, int y)
{
	int r;
	
	if (x == 0 || y == 0) {
		Error("Illegal Operation");
	}
	while (TRUE) {
		r = x % y;
		if (r == 0) break;
		x = y;
		y = r;
	}
	return y;
}

static void rationalReduction(ratioanlT *r)
{
	int gcd;

	gcd = GCD(r->num, r->den);
	r->num /= gcd;
	r->den /= gcd;
}

static void Reduction(int *x, int *y)
{
	int gcd;

	gcd = GCD(*x, *y);
	*x /= gcd;
	*y /= gcd;
}
