/*
 * File: 4.2-ThisOldMan.c
 * ----------------------
 * This program shows 10 bars of the song <this old man>
 */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include "strlib.h"

main()
{
	int i;
	//strings rhymingword;
	strings rhymingword = {""};  //initialize pointer variable

	for (i = 1; i <= 10; i++)
	{
		switch (i) {
		case 1: rhymingword = "thumb"; break;
		case 2: rhymingword = "shoe"; break;
		case 3: rhymingword = "knee"; break;
		case 4: rhymingword = "door"; break;
		case 5: rhymingword = "hive"; break;
		case 6: rhymingword = "sticks"; break;
		case 7: rhymingword = "heaven"; break;
		case 8: rhymingword = "pate"; break;
		case 9: rhymingword = "spine"; break;
		case 10:rhymingword = "shin"; break;
		default: break;
		}
		printf("This old man, he played %d.\n", i);
		printf("He played knick-knack on my %s.\n", rhymingword);
		printf("With a knick-knack, paddy-whack.\n");
		printf("Give your dog a bone.\n");
		printf("This old man came rolling home.\n");
		printf("\n");
	}
}