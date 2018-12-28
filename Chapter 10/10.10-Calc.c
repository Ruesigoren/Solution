/*
 * File: 10.10-Calc.c
 * ------------------
 * This program is a simple calculator.
 */

#include <stdio.h>
#include <ctype.h>

#include "strlib.h"
#include "simpio.h"
#include "modified_scanner.h"

/* main program */

main()
{
	strings token;
	strings line = "";
	strings newline;
	double operand1;
	double operand2;
	strings operator;

	printf("This program implements a simple calculator.\n");
	printf("When the > prompt appears, enter a expression.\n");
	printf("Consisting of integer constants and operators.\n");
	printf("+,-,*,/,and %%.To stop, enter a blank line.\n");
	while (TRUE) {
		printf("> ");
		newline = GetLine();
		if (StringsEqual(newline, "")) {
			break;
		}
		InitScanner(newline);
		while (!AtEndOfLine()) {
			token = GetNextToken();
			if (isop(IthChar(token, 0))) {
				if (StringsEqual(token, "+")) {
					operand1 = StringsToReal(GetNextToken());
				}
				else if (StringsEqual(token, "-")) {
					operand1 = -StringsToReal(GetNextToken());
				}
				else {
					Error("Illegal operator at first.");
				}
			}
			else {
				operand1 = StringsToReal(token);
			}
			while (!AtEndOfLine()) {
				operator = GetNextToken();
				operand2 = StringsToReal(GetNextToken());
				if (StringsEqual(operator, "++") || StringsEqual(operator, "--") || StringsEqual(operator, "+")) {
					operand1 += operand2;
				}
				else if (StringsEqual(operator, "+-") || StringsEqual(operator, "-+") || StringsEqual(operator, "-")) {
					operand1 -= operand2;
				}
				else if (StringsEqual(operator, "*+") || StringsEqual(operator, "*")) {
					operand1 *= operand2;
				}
				else if (StringsEqual(operator, "*-")) {
					operand1 *= -operand2;
				}
				else if (StringsEqual(operator, "/+") || StringsEqual(operator, "/")) {
					if (operand2 == 0.0) {
						Error("0 can't be divisior");
					}
					operand1 /= operand2;
				}
				else if (StringsEqual(operator, "/-")) {
					if (operand2 == 0.0) {
						Error("0 can't be divisior");
					}
					operand1 /= -operand2;
				}
				else if (StringsEqual(operator, "%+") || StringsEqual(operator, "%")) {
					if (operand2 == 0.0) {
						Error("0 can't be divisior");
					}
					operand1 = (int)operand1 % (int)-operand2;
				}
				else if (StringsEqual(operator, "%-")) {
					if (operand2 == 0.0) {
						Error("0 can't be divisior");
					}
					operand1 = (int)operand1 % (int)-operand2;
				}
				else {
					Error("Illegal operator!");
				}
			}
		}
		printf("%g\n", operand1);
	}
}
