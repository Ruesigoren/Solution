#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main()
{
	double b, h, a;

	printf("Enter b : ");
	b = GetReal();
	printf("Enter h : ");
	h = GetReal();
	a = (b * h) / 2;
	printf("a = %g\n", a);
}