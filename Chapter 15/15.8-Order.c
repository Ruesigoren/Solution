/*
 * File: 15.8-Order.c
 * ------------------
 * This program transforms a file containing a list of computer equipment
 * you would like to buy into a nicely formatted order form.
 */

#include <stdio.h>

#include "genlib.h"
#include "simpio.h"

/* constants */

//#define OrderFile   "order.dat"	//the file name is order.dat, input it in console
#define MaxPartNumber    6
#define MaxProductName  20

/* main program */

main()
{
	FILE *infile;
	FILE *outfile;
	errno_t err;
	strings filename;
	char partNumber[MaxPartNumber + 1];
	char productName[MaxProductName + 1];
	int unitNumber;
	double unitPrice;
	double totalPrice = 0.0;
	char termch;
	int nscan;

	while (TRUE) {
		printf("Order file: ");
		filename = GetLine();
		err = fopen_s(&infile, filename, "r");
		if (err) {
			printf("Can't open the file %s.  Try again.\n", filename);
		}
		else {
			break;
		}
	}
	fopen_s(&outfile, "order-output.txt", "w");
	while (TRUE) {
		nscan = fscanf_s(infile, "%s %[^/] %*[/] %d %*[@] %lf%c", 
			                     partNumber, sizeof(partNumber),
			                     productName, sizeof(productName),
			                     &unitNumber,
			                     &unitPrice,
			                     &termch, sizeof(char));
		if (nscan == EOF) break;
		if (nscan != 5 || termch != '\n') {
			Error("Improper file format");
		}
		printf("%-11s%-21s%2d @ %7.2f = %7.2f\n",
			partNumber, productName, unitNumber, unitPrice, unitNumber * unitPrice);
		fprintf(outfile, "%-11s%-21s%2d @ %7.2f = %7.2f\n",
			partNumber, productName, unitNumber, unitPrice, unitNumber * unitPrice);  //in order.dat  3.5" must be correct format
		totalPrice += unitNumber * unitPrice;
	}
	printf("------------------------------------------------------\n");
	fprintf(outfile, "------------------------------------------------------\n");
	printf("%-47s%7.2f\n","TOTAL", totalPrice);
	fprintf(outfile, "%-47s%7.2f\n", "TOTAL", totalPrice);
}