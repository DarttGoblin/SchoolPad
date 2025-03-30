#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Structures.h"

//	Strustures
typedef struct Date { //	Date stucture
	int year;
	int month;
	int day;
} Date;
typedef struct Student { //	Student structure
	char *firstName;
	char *lastName;
	char *formation;
	int Apogee;
	float Average;
	Date date;
} Student;
