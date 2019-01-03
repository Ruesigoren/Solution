/*
 * File: DisplayBoard.c
 * --------------------
 * This program display the tic-tac-toe playgame board.
 */

#include <stdio.h>
#include "simpio.h"

 /* Private function declarations */

static void DisplayBoard(char board[3][3]);

/* main program */

main()
{
	char board[3][3] = { 
		{'X','O','X'},
		{'\0','X','O'},
		{'X','\0','O'}
	};

	DisplayBoard(board);
}

/*
 * Function: DisplayBoard
 * Usage: DisplayBoard(*board[3][3]);
 * ---------------------------------
 * This function displays the playgame board.
 */

static void DisplayBoard(char board[3][3])
{
	int row, column;

	for (row = 0; row < 3; row++) {
		if (row != 0) printf("---+---+---\n");
		for (column = 0; column < 3; column++) {
			if (column != 0) printf("|");
			printf(" %c ", board[row][column]);
		}
		printf("\n");
	}
}
