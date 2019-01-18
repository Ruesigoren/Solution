#ifndef _rational_h
#define _rational_h

/* types */

typedef struct {
	int num;
	int den;
} ratioanlT;

ratioanlT CreateRational(int num, int den);
ratioanlT AddRational(ratioanlT r1, ratioanlT r2);
ratioanlT MultiplyRational(ratioanlT r1, ratioanlT r2);
ratioanlT GetRational(void);
void PrintRational(ratioanlT r);

#endif // !_rational_h

