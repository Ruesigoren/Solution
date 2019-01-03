/*
 * File: 11.12-CheckerBoard.c
 * --------------------------
 * This program implements a function InitChekcerBoard that initializes a checkerboard array
 * so that it corresponds to the starting position of a checkers game.
 * and implements a second function DisplayCheckerboard that displays the current state of a checkerboard on the screen
 */

#include <stdio.h>

#include "simpio.h"
#include "genlib.h"

/* function prototyptes */

void InitCheckBoard(char board[][8]);
void DisplayCheckerBoard(char board[][8]);

/* main */

main()
{
	char board[8][8];

	InitCheckBoard(board);
	DisplayCheckerBoard(board);
}

void InitCheckBoard(char board[][8])
{
	int i, j;

	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			board[i][j] = ' ';
		}
	}
	for (i = 0; i < 8; i += 2) {
		if (i <= 2) {
			for (j = 1; j < 8; j += 2) {
				board[i][j] = 'b';
			}
		}
		if (i == 4) {
			for (j = 1; j < 8; j += 2) {
				board[i][j] = '-';
			}
		}
		if (i == 6) {
			for (j = 1; j < 8; j += 2) {
				board[i][j] = 'r';
			}
		}
	}
	for (i = 1; i < 8; i += 2) {
		if (i == 1) {
			for (j = 0; j < 8; j += 2) {
				board[i][j] = 'b';
			}
		}
		if (i == 3) {
			for (j = 0; j < 8; j += 2) {
				board[i][j] = '-';
			}
		}
		if (i >= 5) {
			for (j = 0; j < 8; j += 2) {
				board[i][j] = 'r';
			}
		}
	}
}

void DisplayCheckerBoard(char board[][8])
{
	int i, j;

	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			printf("%2c", board[i][j]);
		}
		printf("\n");
	}
}
