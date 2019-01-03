#include <stdio.h>
#include "simpio.h"
#include "genlib.h"
#include "strlib.h"

typedef enum { north, west, south, east } directionT;

main()
{
	strings dir[4] = { "north", "west", "south", "east" };
	directionT i;

	for (i = 0; i < 4; i++) {
		printf("%s\n", dir[i]);
	}
}
