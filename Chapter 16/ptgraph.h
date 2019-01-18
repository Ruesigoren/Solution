/*
 * File: ptgraph.h
 * Version: 1.0
 * Last modified on Thu Dec  6 09:06:11 2018 by kaltics
 * ----------------------------------------------------
 */

#ifndef _ptgraph_h
#define _ptgraph_h


 /* types */

typedef struct {
	double x, y;
} pointT;

/*
 * Overview
 * --------
 *   MovePenToPoint(pt);
 *   DrawLineToPoint(pt);
 *   GetCurrentPoint();
 */


void MovePenToPoint(pointT pt);


void DrawLineToPoint(pointT pt);


pointT  GetCurrentPoint(void);

#endif
