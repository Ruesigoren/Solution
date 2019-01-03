/*
 * File: 11.2-Scores.c
 * -------------------
 * This program reads in scores from a panel of seven judges and then computes
 * the average of the five scores that remain after discarding the highest and
 * lowest.
 */

#include <stdio.h>

#include "genlib.h"
#include "simpio.h"

/*
 * Constants
 * ---------
 * NJudges -- Number of judges
 */

#define NJudges 7

/* Main program */

main()
{
    double gymnasticScores[NJudges];
    double total, average;
	double maxscore, minscore;
    int i;

    printf("Please enter a score for each judge.\n");
    for (i = 0; i < NJudges; i++) {
        printf("Score for judge #%d:  ", i + 1);
        gymnasticScores[i] = GetReal();
    }
    total = 0;
	maxscore = minscore = gymnasticScores[0];
    for (i = 0; i < NJudges; i++) {
		if (maxscore < gymnasticScores[i]) maxscore = gymnasticScores[i];
		if (minscore > gymnasticScores[i]) minscore = gymnasticScores[i];
        total += gymnasticScores[i];
    }
    average = (total - maxscore - minscore) / (NJudges - 2);
    printf("The average score is %.2f\n", average);
}
