/*
 * File: 14.10-HangMan.c
 * ---------------------
 * This program plays the game of hangman.
 */

#include <stdio.h>
#include <string.h>

#include "genlib.h"
#include "simpio.h"
#include "graphics.h"
#include "random.h"

/* global variables */

char *worddict[] = { "optimism", "is" , "the", "faith", "that", "leads", "to","achievement",
                     "nothing", "can", "be", "done", "without", "hope", "and", "confidence" };
int dictlen = sizeof(worddict) / sizeof(worddict[0]);

/* function prototypes */

char *GenerateWord(void);
void GuessWord(char *word);
boolean CheckGuess(char *word, char *backup, char guess);
boolean IsFindChar(char ch, char* string);
void DrawHangman(int wrongtimes);

/* main program */

main()
{
	char *word;

	printf("Let's play hangman! I will pcik a secret word.\n");
	printf("On each turn, you guess a letter.If the letter\n");
	printf("is in the sectet word, I will show you where it\n");
	printf("appears.If you make an incorrect guess, part\n");
	printf("of your body gets strung up on the scaffold.\n");
	printf("The object is to guess the word before you are\n");
	printf("hanged.\n\n");
	Randomize();
	InitGraphics();
	word = GenerateWord();
	GuessWord(word);
}

void GuessWord(char *word)
{
	char *cpyword;
	int len;
	char guessalpha;
	int guesstimes, wrongtimes = 0, temp;
	int i;
	char *line;

	len = strlen(word);
	cpyword = (char *)malloc((len + 1) * sizeof(char));
	strcpy_s(cpyword, len + 1, word);
	//printf("%s\n", cpyword);

	for (i = 0; cpyword[i] != '\0'; i++) {
		cpyword[i] = '-';
	}
	for (guesstimes = 8; guesstimes > 0; guesstimes--) {
		
		temp = guesstimes;
		printf("The word now look like this:%s\n", cpyword);
		if (guesstimes == 1) {
			printf("You have only one guesse left.\n");
		}
		else {
			printf("You have %d guesses left.\n", guesstimes);
		}
		
		printf("Your guess: "); 
		line = GetLine();	//Got trapped here because of writing down: guessalpha = getchar();
		guessalpha = line[0];
		if (CheckGuess(word, cpyword, guessalpha)) {
			guesstimes++;
		}
		if (strcmp(word, cpyword) == 0) {
			printf("You guessed the word: %s\n", cpyword);
			printf("You win.\n");
			break;
		}
		if (temp == guesstimes) {
			wrongtimes++;
		}
		DrawHangman(wrongtimes);
	}
}

boolean CheckGuess(char *word, char *backup, char guess)
{
	int i;

	if (IsFindChar(guess, word)) {
		printf("That guess is correct.\n");
		for (i = 0; word[i] != '\0'; i++) {
			if (word[i] == guess) {
				backup[i] = guess;
			}
		}
		return TRUE;
	}
	else {
		printf("\a");
		printf("There are no %c in the word.\n", guess);
		return FALSE;
	}
}

boolean IsFindChar(char ch, char *string)
{
	for (int i = 0; string[i] != '\0'; i++) {
		if (string[i] == ch) {
			return TRUE;
		}
	}
	return FALSE;
}

char *GenerateWord(void)
{
	int i;

	i = RandomInteger(0, dictlen - 1);
	i = RandomInteger(0, dictlen - 1);
	return worddict[i];
}

void DrawHangman(int wrongtimes)
{
	switch (wrongtimes) {
	case 1:
		MovePen(0, 0);
		DrawLine(0, 13.0);
		break;
	case 2:
		MovePen(0, 13.0);
		DrawLine(3.0, 0);
		DrawLine(0, -2.0);
		break;
	case 3:
		MovePen(3.0, 11.0);
		DrawArc(1.0, 90, 360);
		break;
	case 4:
		MovePen(3.0, 9.0);
		DrawLine(0, -5.0);
		break;
	case 5:
		MovePen(3.0, 8.5);
		DrawLine(-2.0, 0);
		DrawLine(0, -0.5);
		break;
	case 6:
		MovePen(3.0, 8.5);
		DrawLine(2.0, 0);
		DrawLine(0, -0.5);
		break;
	case 7:
		MovePen(3.0, 4.0);
		DrawLine(-0.5, 0);
		DrawLine(0, -4.0);
		DrawLine(-0.5, 0);
		break;
	case 8:
		MovePen(3.0, 4.0);
		DrawLine(0.5, 0);
		DrawLine(0, -4.0);
		DrawLine(0.5, 0);
		break;
	default:
		break;
	}
}
