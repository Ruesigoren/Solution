/*
 * File: 9.1-LeftFrom.c
 * --------------------
 * This program shows the direction after turning left 90 degree.
 */

#include <ctype.h>

#include "simpio.h"
#include "genlib.h"
#include "strlib.h"

typedef enum {
	East,
	North,
	West,
	South
} directionT;

/* function prototypes */

directionT LeftFrom(directionT dir);
strings DirectionName(directionT dir);

/* main  program */

main()
{
	printf("This program tests the LeftFrom function.\n");
	printf("LeftFrom(North) = %s\n", DirectionName(LeftFrom(North)));
	printf("LeftFrom(East) = %s\n", DirectionName(LeftFrom(East)));
	printf("LeftFrom(South) = %s\n", DirectionName(LeftFrom(South)));
	printf("LeftFrom(West) = %s\n", DirectionName(LeftFrom(West)));
}

directionT LeftFrom(directionT dir)
{
	/*
	switch (dir) {
	case East: case North: case West:
		return (dir + 1);
	case South:
		return (East);
	default:
		Error("Illegal direction value");
	}
	*/
	return (dir + 1) % 4;
}

strings DirectionName(directionT dir)
{
	switch (dir) {
	case East: return ("East");
	case North: return ("North");
	case West: return ("West");
	case South: return ("South");
	default:
		Error("Illegal direction value");
	}
}
