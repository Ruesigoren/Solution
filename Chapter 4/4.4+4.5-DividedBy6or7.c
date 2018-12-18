/*
 * File: 4.4+4.5-DividedBy6or7.c
 * -----------------------------
 * 4.4 This program finds numbers from 1 to 100 which can be divided by either 6 or 7.
 * 4.5 This program finds numbers from 1 to 100 which can be divided by either 6 or 7, but not both.
 */

#include <stdio.h>

main()
{
	int i;

	for (i = 1; i <= 100; i++) {
		/* right but not easy to understand */

		//if (!((i % 6) && (i % 7))) {
		//	if (!((i % 6) || (i % 7))) {}
		//	else printf("%-3d", i);
		//}

		/* right but redundant */

		//if (((i % 6) == 0) && ((i % 7) != 0) ||
		//	((i % 6) != 0) && ((i % 7) == 0))
		//	printf("%-3d", i);

		/* right and elegant */

		/* 4.4 */
		//if (!(i % 6) || !(i % 7)) {
		//	printf("%-3d", i);
		//}

		/* 4.5 */
		if (!(i % 6) && (i % 7) || 
			(i % 6) && !(i % 7)) {
			printf("%-3d", i);
		}
	}
	printf("\n");
}