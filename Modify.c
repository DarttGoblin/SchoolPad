//#include "ProjectMainFunctions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Modify.h"

void Modify(FILE *studentFile) { //	   Modify a student information
	char next, choice, lines[1000][100], newCarac[100];
	int i, j, line_count = GetFile(studentFile, lines), apogee, studentIndex, newDay, newMonth, newYear;
	float newNum;
	do {
		system("cls");
		printf("Welcome to *Modify a Student Information* section\n\n");
		printf("Type 'c' if you'd like to continue or 'g' if you'd like to go back : ");
		scanf(" %c", &choice);
		if (choice == 'g' || choice == 'G') {}
		else if (choice == 'c' || choice == 'C') {
			printf("Insert student's apogee number : ");
			scanf("%d", &apogee);
			bool boolean = false;
			for (i = 2; i < line_count; i += 7) {
				if (apogee == atoi(lines[i])) {
					boolean = true;
					studentIndex = i;
					break;
				}
    		}
    		if (!boolean) {
    			printf("\nThere is no student in the list has the provided apogee\n\n");
    			GoBack(next);
			}
			else {
				do {
					printf("\nWhich information you'd like to modify?\n");
					printf("Type 'f' if you want modifying based on first name\n");
					printf("Type 'l' if you want modifying based on last name\n");
					printf("Type 'a' if you want modifying based on apogee number\n");
					printf("Type 'd' if you want modifying based on formation\n");
					printf("Type 'n' if you want modifying based on average note\n");
					printf("Type 's' if you want modifying based on subscribtion date\n\nYour answer : ");
					scanf(" %c", &choice);
					if (choice == 'f' || choice == 'F') {
						printf("Insert the new student's first name : ");
						scanf("%s", &newCarac);
						sprintf(lines[studentIndex - 2], "%s\n", newCarac);
					}
					else if (choice == 'l' || choice == 'L') {
						printf("Insert the new student's last name : ");
						scanf("%s", &newCarac);
						sprintf(lines[studentIndex - 1], "%s\n", newCarac);
					}
					else if (choice == 'a' || choice == 'A') {
						do {
							printf("Insert the new student's apogee number : ");
							scanf("%d", &newNum);
						} while (newNum <= 0);
						sprintf(lines[studentIndex], "%d\n", newNum);
					}
					else if (choice == 'd' || choice == 'D') {
						do {
							printf("Insert the new student's formation : ");
							scanf("%s", &newCarac);
						} while (strcmp(newCarac, "SMIA") != 0 && strcmp(newCarac, "smia") != 0 &&
						strcmp(newCarac, "SMPC") != 0 && strcmp(newCarac, "smpc") != 0 &&
						strcmp(newCarac, "SMI") != 0 && strcmp(newCarac, "smi") != 0 &&
						strcmp(newCarac, "SMA") != 0 && strcmp(newCarac, "sma") != 0 &&
						strcmp(newCarac, "SMP") != 0 && strcmp(newCarac, "smp") != 0 &&
						strcmp(newCarac, "SMC") != 0 && strcmp(newCarac, "smc") != 0);
						sprintf(lines[studentIndex + 1], "%s\n", newCarac);
					}
					else if (choice == 'n' || choice == 'N') {
						do {
							printf("Insert the new student's note : ");
							scanf("%f", &newNum);
						} while (newNum < 0 || newNum > 20);
						sprintf(lines[studentIndex + 2], "%g\n", newNum);
					}
					else if (choice == 's' || choice == 'S') {
						do {
							printf("Insert the new student's subscribtion day (1-31): ");
							scanf("%d", &newDay);
							printf("Insert the new student's subscribtion month (1-12): ");
							scanf("%d", &newMonth);
							printf("Insert the new student's subscribtion year (2010-2023): ");
							scanf("%d", &newYear);
						} while (newDay <= 0 || newDay > 31 || newMonth <= 0 ||
						newMonth > 12 || newYear < 2010 || newYear > 2023);
						sprintf(lines[studentIndex + 3], "%02d/%02d/%d\n", newDay, newMonth, newYear);
					}
					else choice = 'e';
				} while (choice == 'e');
				studentFile = fopen("StudentFile.txt", "w");  // open the file again with write mode
    			OpenFile(studentFile);
    			for (i = 0; i < line_count; i++) {
    			    fputs(lines[i], studentFile);  // write the lines back to the file
    			}
    			fclose(studentFile);
    			system("cls");
				printf("The student information have been modified successefuly.\n");
				GoBack(next);
			}
		}
		else choice = 'e';
	} while (choice == 'e');
}
