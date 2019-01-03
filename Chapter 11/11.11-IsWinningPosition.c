/*
 * File: 11.11-IsWinningPosition.c
 * -------------------------------
 * This program reads in the current contents of the board array and then
 * reports whether either player has won the game.
 */


#include <stdio.h>
#include <ctype.h>

#include "simpio.h"
#include "genlib.h"
#include "strlib.h"

/* function prototypes */

boolean IsWinningPosition(char board[][3], char player);
boolean IsLegalInput(strings line);
boolean IsLegalChar(char ch);
void GetBoardFromUser(char board[][3]);
strings GetLineFromUser(void);
void DisplayBoard(char board[][3]);

/* main program */

main()
{
	char board[3][3];
	int i, j;

	printf("This program tests the IsWinningPositon function.\n");
	printf("Enter the state of the board, row by row.\n");
	printf("Please use '-' instead of a blank.");
	printf("\n");
	GetBoardFromUser(board);
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (board[i][j] == '-') {
				board[i][j] = '\0';
			}
		}
	}
	printf("The play board is:\n");
	DisplayBoard(board);
	if (IsWinningPosition(board, 'X')) {
		printf("X has won\n");
	}
	else if (IsWinningPosition(board, 'O')) {
		printf("O has won\n");
	}
	else {
		printf("No one has won\n");
	}
}

boolean IsWinningPosition(char board[][3], char player)
{
	char winner[8];
	int i;

	for (i = 0; i < 3; i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
			winner[i] = board[i][0];
		}
	}
	for (i = 0; i < 3; i++) {
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
			winner[3 + i] = board[0][i];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
		winner[6] = board[0][0];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
		winner[7] = board[1][1];
	}
	for (i = 0; i < 8; i++) {
		if (player == winner[i]) {
			return (TRUE);
		}
	}
	return (FALSE);
}

void GetBoardFromUser(char board[][3])
{
	strings line;
	int i, j;

	for (i = 0; i < 3; i++) {
		line = GetLineFromUser();
		for (j = 0; j < 3; j++) {
			board[i][j] = toupper(IthChar(line, j));
		}
	}
}

strings GetLineFromUser(void)
{
	strings line;
	int len;

	while (TRUE) {
		line = GetLine();
		len = StringsLength(line);
		if (len < 3) {
			printf("Please input whole states\n");
		}
		else if (len >= 3) {
			if (!IsLegalInput(line)) {
				printf("Illegal input\n");
			}
			else if (len >= 3) {
				if (len > 3) {
					printf("Only first 3 inputs are invaild.\n");
				}
				break;
			}
		}
	}
	return (line);
}

boolean IsLegalInput(strings line)
{
	int i;

	for (i = 0; i < 3; i++) {
		if (!IsLegalChar(IthChar(line, i))) {
			return (FALSE);
		}
	}
	return (TRUE);
}

boolean IsLegalChar(char ch)
{
	char Char;

	Char = toupper(ch);
	if (Char == 'X' || Char == 'O'
		|| Char == '-') {
		return (TRUE);
	}
	else {
		return (FALSE);
	}
}

void DisplayBoard(char board[][3])
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
