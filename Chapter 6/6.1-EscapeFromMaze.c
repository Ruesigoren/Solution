/*
 * File: 6.1-EscapeFromMaze.c
 * --------------------------
 * This is a procedure that implements the algorithm
 * suggested by the right-hand rule.
 */

#include <stdio.h>
#include "genlib.h"

/* function prototypes */

void MoveForward(void);
void TurnRight(void);
void TurnLeft(void);
boolean IfFacingWall(void);
boolean IfOutSide(void);
void FindTheRightWall(void);

/* main program */

main()
{
	FineTheRightWall();
	while (!IfOutSide()) {
		TurnRight();				//turn right to confirm hand on the right wall
		while (IfFacingWall()) {	//confirmed£¬turn left
			TurnLeft();				//if facing wall, keep turning left to find a way
		}
		MoveForward();
	}
}

void FindTheRightWall(void)
{
	int count;

	for (count = 0; count < 4; count++) {  //look around to find the wall on the right hand
		if (!IfFacingWall()) {
			TurnRight();
		}
		else {
			TurnLeft();
			break;
		}
	}
	if (count == 4) {	//if not, now is in original position, turn right and move forward until facing wall
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
