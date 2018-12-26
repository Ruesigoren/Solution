/*
 * File: 8.8+8.9-EducationalApplication.c
 * --------------------------------------
 * This program poses a series of simple arithmetic problems
 * for a student to answer.
 */

#include <stdio.h>
#include <stdlib.h>

#include "simpio.h"
#include "genlib.h"
#include "strlib.h"
#include "random.h"

/* Constants
 * ---------
 * QuenstionNumber -- This constant controls the number of questions.
 */

#define QuenstionNumber          5

/* function  prototypes */

void GiveInstruction(void);
void AskQuestion(void);
strings Operator(int sign);
void RightAnswerPrompt(void);
void WrongAnswerPrompt(void);
void WrongAnswerFinalPrompt(int rightanswer);
void QuizCompletePrompt(void);

/* main program */

main()
{
	Randomize();
	GiveInstruction();
	for (int i = 0; i < QuenstionNumber; i++) {
		AskQuestion();
	}
	QuizCompletePrompt();
}

void GiveInstruction(void)
{
	printf("Welcome to Math Quiz!\n");
}

void AskQuestion(void)
{
	int i, x, y, a, b, answer, rightanswer;
	int sign;
	strings operator;

	while (TRUE) {
		a = RandomInteger(1, 20);
		b = RandomInteger(1, 20);
		if (a >= b) {
			if (a + b <= 20) {
				x = a;
				y = b;
				break;
			}
		}
	}
	if (rand() > RAND_MAX / 2) {
		sign = 1;
	}
	else {
		sign = -1;
	}
	operator = Operator(sign);
	rightanswer = x + sign * y;
	for (i = 3; i > 0; i--) {
		printf("What is %d %s %d? ", x, operator, y);
		answer = GetInteger();
		if (answer == rightanswer) {
			RightAnswerPrompt();
			break;
		}
		else {
			if (i == 1) {
				WrongAnswerFinalPrompt(rightanswer);
				break;
			}
			WrongAnswerPrompt();
		}
	}
}

strings Operator(int sign)
{
	switch (sign) {
	case  1: return ("+");
	case -1: return ("-");
	default: break;
	}
}

void RightAnswerPrompt(void)
{
	int a;

	a = RandomInteger(1, 4);
	switch (a) {
	case  1: printf("That's the answer!\n"); break;
	case  2: printf("Correct!\n"); break;
	case  3: printf("You got it!\n"); break;
	case  4: printf("Good job!\n"); break;
	default: break;
	}
}

void WrongAnswerPrompt(void)
{
	printf("That's incorrect!Try a different answer:\n");
}

void WrongAnswerFinalPrompt(int rightanswer)
{
	printf("No, the answer is %d\n", rightanswer);
}

void QuizCompletePrompt(void)
{
	printf("Quiz completed!\n");
}
