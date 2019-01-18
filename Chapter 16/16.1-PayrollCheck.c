/*
 * File: 16.1-PayrollCheck.c
 * -------------------------
 * This program generates weekly payroll checks for
 * a company whose employment records are stored in 
 * a database of type employeeDB.
 */

#include <stdio.h>

#include "strlib.h"
#include "genlib.h"

/* constants */

#define MaxEmployees 100

/* types */

typedef struct {
	strings name;
	strings title;
	strings ssnum;
	double salary;
	int withholding;
} *employeeT;

typedef struct {
	employeeT staff[MaxEmployees];
	int nEmployees;
} *employeeDB;

/* Private function declarations */

static employeeDB InitEmployeeDatabase(void);
static void ListEmployees(employeeDB db);

/* main program */

main()
{
	employeeDB db;

	db = InitEmployeeDatabase();
	ListEmployees(db);
}

static employeeDB InitEmployeeDatabase(void)
{
	employeeDB db;
	employeeT emp;

	db = New(employeeDB);

	emp = New(employeeT);
	emp->name = "Ebenezer Scrooge";
	emp->title = "Partner";
	emp->ssnum = "271-82-8183";
	emp->salary = 250.00;
	emp->withholding = 1;
	db->staff[0] = emp;
	db->nEmployees = 1;

	emp = New(employeeT);  //reallocate memory
	emp->name = "Bob Cratchit";
	emp->title = "Clerk";
	emp->ssnum = "314-15-9265";
	emp->salary = 15.00;
	emp->withholding = 7;
	db->staff[1] = emp;
	db->nEmployees = 2;

	/*
	db->staff[0]->name = "Ebenezer Scrooge";  //wrong!
	db->staff[0]->title = "Partner";
	db->staff[0]->ssnum = "271-82-8183";
	db->staff[0]->salary = 250.00;
	db->staff[0]->withholding = 1;
	db->nEmployees = 1;
	*/
	return db;
}

static void ListEmployees(employeeDB db)
{
	int i;
	double gross, tax, net;

	for (i = 0; i < db->nEmployees; i++) {
		gross = db->staff[i]->salary;
		tax = (gross - db->staff[i]->withholding * 1) * 0.25;
		net = gross - tax;
		printf("\n");
		printf("+--------------------------------------------------+\n");
		printf("| Scrooge and Marley Ltd.                          |\n");
		printf("|                                                  |\n");
		printf("| Pay to the order of: %-20s%6.2f  |\n", db->staff[i]->name, net);
		printf("|                                                  |\n");
		printf("|                                                  |\n");
		printf("| %-.2f gross - %-.2f tax\t       E.Scroooge  |\n", gross, tax);
		printf("+--------------------------------------------------+\n");
		printf("\n");
	}
}
