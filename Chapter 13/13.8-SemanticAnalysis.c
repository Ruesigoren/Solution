/*
 * File: 13.8-SemanticAnalysis.c
 * -----------------------------
 * This program reads simple data declarations and responds with 
 * the amount of memory that would be allocated to that variable.
 * This program limits declarations to a single asterisk and subscript for each variable,
 * And one statment per line.
 */

#include <stdio.h>
#include <ctype.h>

#include "simpio.h"
#include "strlib.h"
#include "scanner.h"

/* gloable varibales */

strings typename[] = { "char", "short", "int", "long", "float", "double",
                       "char*", "short*", "int*", "long*", "float*", "double*" };
int typenamelen = sizeof(typename) / sizeof(typename[0]);

/* function prototypes */

int MySizeof(strings type);
int TypeIndex(strings type);
void InterpretDeclaration(strings line);
strings *SaveTokensIntoArray(strings line, int *arrlen);
void AnalyzeTokens(strings *Tokens, int TokenLegnth);
int GetIndexofNextComma(strings *Tokens, int lh, int rh);

/* main program */

main()
{
	strings line;

	printf("Enter variable declarations, ending with a blank line.\n");
	while (TRUE) {
		line = GetLine();
		if (StringsEqual(line, "")) break;
		InterpretDeclaration(line);
	}
}

void InterpretDeclaration(strings line)
{
	strings *Tokens;
	int TokenLegnth;

	Tokens = SaveTokensIntoArray(line, &TokenLegnth);
	AnalyzeTokens(Tokens, TokenLegnth);
}

strings *SaveTokensIntoArray(strings line, int *arrlen)
{
	strings *Tokens;
	strings token;
	int i, n = 0;

	/* determine the length of array which tokens are saved */

	InitScanner(line);
	while (!AtEndOfLine()) {
		token = GetNextToken();
		if (!StringsEqual(token, " ")) {
			n++;
		}
	}
	*arrlen = n;
	//printf("%d\n", *arrlen);  //test

	/* save tokens to a new array */
	Tokens = NewArray(n, strings);
	InitScanner(line);
	for (i = 0; i < n; i++) {
		while (!AtEndOfLine()) {
			token = GetNextToken();
			if (!StringsEqual(token, " ")) {
				Tokens[i] = token;
				break;
			}
		}
	}
	/*
	for (int i = 0; i < n; i++) {  //test print
		printf("%s\n", Tokens[i]); //
	} 
	*/
	return (Tokens);
}

void AnalyzeTokens(strings *Tokens, int TokenLegnth)
{
	strings type, var, varlen;	//var -- name of variable
								//varlen -- length of variable name
	int i, cpos, comma = 0;		//cpos -- current position
								//comma -- the position of comma

	for (i = 0; i < TokenLegnth - 1; ) {
		cpos = comma + 1;
		type = Tokens[0];
		comma = GetIndexofNextComma(Tokens, comma + 1, TokenLegnth - 1);
		if (comma == - 1) {
			printf("Require ; int the end of line.\n");
			break;  //don't forget break
		}
		switch (comma - cpos) {
		case 1:		//statement like: int a;
			var = Tokens[cpos];
			printf("%s rquires %d bytes\n", var, MySizeof(type));
			break;
		case 2:		//statement like: int *a;
			if (StringsEqual(Tokens[cpos], "*")) {
				type = Concat(type, "*");
			}
			var = Tokens[cpos + 1];
			printf("%s rquires %d bytes\n", var, MySizeof(type));
			break;
		case 4:		//statement like: int a[10];
			if (StringsEqual(Tokens[cpos + 1], "[") &&
				StringsEqual(Tokens[cpos + 3], "]")) {
				var = Tokens[cpos];
				varlen = Tokens[cpos + 2];
				printf("%s rquires %d bytes\n", var, StringsToInteger(varlen) * MySizeof(type));
			}
			break;
		default:
			break;
		}
		i = comma;
	}
	//printf("%s\n", type);
}

int GetIndexofNextComma(strings *Tokens, int lh, int rh)
{
	int i;

	for (i = lh; i <= rh; i++) {
		if (StringsEqual(Tokens[i], ",")) {
			return (i);
		}
	}
	for (i = lh; i <= rh; i++) {
		if (StringsEqual(Tokens[i], ";")) {
			return (i);
		}
	}
	return (-1);
}

int MySizeof(strings type)
{
	int typeindex;

	typeindex = TypeIndex(type);
	switch (typeindex) {
	case  0: return (sizeof(char));
	case  1: return (sizeof(short));
	case  2: return (sizeof(int));
	case  3: return (sizeof(long));
	case  4: return (sizeof(float));
	case  5: return (sizeof(double));
	case  6: return (sizeof(char*));
	case  7: return (sizeof(short*));
	case  8: return (sizeof(int*));
	case  9: return (sizeof(long*));
	case 10: return (sizeof(float*));
	case 11: return (sizeof(double*));
	default: return (-1);
	}
}

int TypeIndex(strings type)
{
	int i;

	for (i = 0; i < typenamelen; i++) {
		if (StringsEqual(type, typename[i])) return (i);
	}
	return (-1);
}
