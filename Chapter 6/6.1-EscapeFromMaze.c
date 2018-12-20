/*
 * File: 6.1-EscapeFromMaze.c
 * --------------------------
 * This is a procedure that implements the algorithm
 * suggested by the right-hand rule.
 */

#include <stdio.h>
#include "genlib.h"

void MoveForward(void);
void TurnRight(void);
void TurnLeft(void);
boolean IfFacingWall(void);
boolean IfOutSide(void);
void FineTheRightWall(void);

main()
{
	FineTheRightWall();
	while (!IfOutSide()) {
		TurnRight();
		while (IfFacingWall()) {  //keep hand on the right wall
			TurnLeft();
		}
		MoveForward();
	}
}

void FineTheRightWall(void)
{
	int count;

	for (count = 0; count < 4; count++) {  //look around to find the wall on right hand
		if (!IfFacingWall()) {
			TurnLeft();
		}
		else
			break;
	}
	if (count == 4) {  //if not, turn right and move forward until facing wall
		TurnRight();
		while (!IfOutSide()) {
			if (IfFacingWall()) {
				TurnLeft();
				break;
			}
			else
				MoveForward();
		}
	}
}


void MoveForward(void)
{

}

void TurnRight(void)
{

}

void TurnLeft(void)
{

}

boolean IfFacingWall(void)
{

}

boolean IfOutSide(void)
{

}
