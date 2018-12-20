/*
 * File: 6.6-TheBodeLaw.c
 * ----------------------
 */

#include <stdio.h>
#include "genlib.h"
#include "strlib.h"

double TheBodeLaw(int planet);
int PlanetOrder(int planet);
strings PlanetName(int planet);

main()
{
	int planet;

	for (planet = 1; planet <= 8; planet++) {
		printf("%-14s    %4.1f %s\n", PlanetName(planet), TheBodeLaw(planet), "AU");
	}
}

double TheBodeLaw(int planet)
{
	double distance;

	distance = (4 + PlanetOrder(planet)) / 10.0;
	return distance;
}
int PlanetOrder(int planet)
{
	switch (planet) {
	case 1: return (1);
	case 2: return (3);
	case 3: return (6);
	case 4: return (12);
	case 5: return (24);
	case 6: return (48);
	case 7: return (96);
	case 8: return (192);
	}
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