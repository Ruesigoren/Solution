/*
 * file: 9-Test.c
 * --------------
 * this program define a enum type named outcomT.
 */

#include <stdio.h>
#include <ctype.h>

#include "strlib.h"
#include "random.h"

/* main program */

main()
{
	Randomize();
	typedef enum {
		Lose = -1,
		Draw = 0,
		Win = 1
	} outcomeT;

	char t1 = 37;
	int t2 = 37;
	char t3 = 'A';
	int t4 = 'A';

	printf("%d %d %d %d\n", '$', '@', '\a', 'x');
	printf("%c\n", t4);
	printf("%d\n", isdigit(53));
	printf("%d\n", toupper('5'));
	printf("%d\n", StringsLength("ABCDE"));
	printf("%d\n", StringsLength(""));
	printf("%d\n", StringsLength("\a"));
	printf("%c\n", IthChar("ABC", 2));
	printf("%s\n", Concat("12", ".00"));
	printf("%s\n", Concat(CharToStrings('2'), ".00"));
	printf("%s\n", SubStrings("ABCDE", 0, 3));
	printf("%s\n", SubStrings("ABCDE", 4, 1));
	printf("%s\n", SubStrings("ABCDE", 3, 9));
	printf("%s\n", SubStrings("ABCDE", 3, 3));

	printf("%d\n", StringsEqual("ABCDE", "abcde"));
	printf("%d\n", StringsCompare("ABCDE", "ABCDE"));
	printf("%d\n", StringsCompare("ABCDE", "ABC"));
	printf("%d\n", StringsCompare("ABCDE", "abcde"));
	printf("%d\n", FindChar('a', "ABracadabra", 0));
	printf("%d\n", FindStrings("ra", "ABracadabra", 3));
	printf("%d\n", FindStrings("is", "This is a test.", 0));
	printf("%d\n", FindStrings("This is a test.", "test", 0));

	printf("%s\n", ConvertToLowerCase("Catch-22"));
	printf("%d\n", StringsToInteger(SubStrings("Catch-22", 5, 7)));
	printf("%s\n", RealToStrings(3.140));
	printf("%s\n", Concat(IntegerToStrings(4 / 3), "pi"));
	int b = RandomInteger(1, 90);
	printf("%d\n", b);
}
