/*
 * File: 6.6-TheBodeLaw.c
 * ----------------------
 * This program using Bode's formula to calculate
 * the distances from the sun to each of the planets.
 */

#include <stdio.h>
#include "genlib.h"
#include "strlib.h"

/* constants */

#define Mercury			1
#define Venus			2
#define Earth			3
#define Mars			4
#define AsteroidBelt	5
#define Jupiter			6
#define Saturn			7
#define Uranus			8

/* function prototypes*/

double TheBodeLaw(int planet);
int PlanetCoeff(int planet);
strings PlanetName(int planet);

/* main program */

main()
{
	int planet;

	for (planet = Mercury; planet <= Uranus; planet++) {
		printf("%-14s    %4.1f %s\n",
			PlanetName(planet), TheBodeLaw(planet), "AU");
	}
}

double TheBodeLaw(int planet)
{
	double distance;

	distance = (4 + PlanetCoeff(planet)) / 10.0;
	return distance;
}

int PlanetCoeff(int planet)
{
	int i, coeff;
	
	if (planet == 1) return 1;
	if (planet == 2) return 3;
	coeff = 3;
	for (i = 3; i <= planet; i++) {
		coeff *= 2;
	}
	return coeff;
}

strings PlanetName(int planet)
{
	switch (planet) {
	case  1: return ("Mercury");
	case  2: return ("Venus");
	case  3: return ("Earth");
	case  4: return ("Mars");
	case  5: return ("Asteroid belt");
	case  6: return ("Jupiter");
	case  7: return ("Saturn");
	case  8: return ("Uranus");
	default: return ("Illegal Planet");
	}
}
