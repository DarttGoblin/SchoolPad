//#include "ProjectMainFunctions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Research.h">

void Research(FILE *studentFile, int *numberOfResearches) { //    Prints a researched student information
    char next, choice, continu,  lines[1000][100], *name = (char*)malloc(100);
    int i, line_count = GetFile(studentFile, lines);
	FILE *Research;
		do {
		system("cls");
		printf("Welcome to *Research For a Student* section\n\n");
		printf("Type 'c' if you'd like to continue or 'g' if you'd like to go back : ");
		scanf(" %c", &continu);
		if (continu == 'g' || continu == 'G') {}
		else if (continu == 'c' || continu == 'C') {
			do {
				printf("\nBy which method you'd like to research for the student?\n");
				printf("Please insert one of the methods bellow\n\n");
				printf("Type 'f' if you want researching based on first name\n");
				printf("Type 'l' if you want researching based on last name\n");
				printf("Type 'a' if you want researching based on apogee number\n\nYour answer : ");
				scanf(" %c", &choice);
				if (choice == 'f' || choice == 'F') {
			    	printf("\nPlease insert the name of student you'd like to research for\nYour answer : ");
					scanf("%s", name);
					realloc(name, strlen(name) + 1);
					name[strlen(name)] = '\0';
					MallocError(name);
					strcat(name, "\n");
					bool boolean = false;
					printf("F.Name     | L.Name     | Apogee     | Formation  | Average    | Inscription.D\n");
      				printf("------------------------------------------------------------------------------\n");
					for (i = 0; i < line_count; i += 7) {
						if (strcmp(name, lines[i]) == 0) {
							lines[i][strcspn(lines[i], "\n")] = '\0'; //    Remove the newline character from the end of the string
							printf("%-10s | ", lines[i]);
							lines[i + 1][strcspn(lines[i + 1], "\n")] = '\0';
							printf("%-10s | ", lines[i + 1]);
							lines[i + 2][strcspn(lines[i + 2], "\n")] = '\0';
							printf("%-10s | ", lines[i + 2]);
							lines[i + 3][strcspn(lines[i + 3], "\n")] = '\0'; 
							printf("%-10s | ", lines[i + 3]);
							lines[i + 4][strcspn(lines[i + 4], "\n")] = '\0';
							printf("%-10s | ", lines[i + 4]);
							lines[i + 5][strcspn(lines[i + 5], "\n")] = '\0';
							printf("%-10s\n", lines[i + 5]);
							boolean = true; //	the fact that the student exists is true
						}
			    	}
			    	if (!boolean) {
			    		printf("\nThere is no student in the list has the provided name\n\n");
					}
					printf("\n");
			    	GoBack(next);
				}
				else if (choice == 'l' || choice == 'L') {
			    	printf("\nPlease insert the student's last name you'd like to research for\nYour answer : ");
					scanf("%s", name);
					realloc(name, strlen(name) + 1);
					name[strlen(name)] = '\0';
					MallocError(name);
					strcat(name, "\n");
			    	bool boolean = false;
			    	printf("F.Name     | L.Name     | Apogee     | Formation  | Average    | Inscription.D\n");
      				printf("------------------------------------------------------------------------------\n");
					for (i = 1; i < line_count; i += 7) {
						if (strcmp(name, lines[i]) == 0) {
							lines[i - 1][strcspn(lines[i - 1], "\n")] = '\0'; //    Remove the newline character from the end of the string
							printf("%-10s | ", lines[i - 1]);
							lines[i][strcspn(lines[i], "\n")] = '\0';
							printf("%-10s | ", lines[i]);
							lines[i + 1][strcspn(lines[i + 1], "\n")] = '\0';
							printf("%-10s | ", lines[i + 1]);
							lines[i + 2][strcspn(lines[i + 2], "\n")] = '\0'; 
							printf("%-10s | ", lines[i + 2]);
							lines[i + 3][strcspn(lines[i + 3], "\n")] = '\0';
							printf("%-10s | ", lines[i + 3]);
							lines[i + 4][strcspn(lines[i + 4], "\n")] = '\0';
							printf("%-10s\n", lines[i + 4]);
							boolean = true;
						}
			    	}
			    	if (!boolean) {
			    		printf("\nThere is no student in the list has the provided name\n\n");
					}
					printf("\n");
			    	GoBack(next);
				}
				else if (choice == 'a' || choice == 'A') {
				    int apogee;
				    printf("\n%d\n", *numberOfResearches);
			    	printf("Please insert the apogee of student you'd like to research for\nYour answer : ");
					scanf("%d", &apogee);
					bool boolean = false;
					Research = fopen("NumberOfResearches.txt", "w");
					fprintf(Research, "%d", ++(*numberOfResearches));
					fclose(Research);
					FILE *ResearchHistory = fopen("ResearchHistory.txt", "a");
					printf("\nF.Name     | L.Name     | Apogee     | Formation  | Average    | Inscription.D\n");
					fprintf(ResearchHistory, "Research number %d : \n\n", *numberOfResearches);
					fprintf(ResearchHistory, "F.Name     | L.Name     | Apogee     | Formation  | Average    | Inscription.D\n");
      				printf("------------------------------------------------------------------------------\n");
					fprintf(ResearchHistory, "------------------------------------------------------------------------------\n");
					for (i = 2; i < line_count; i += 7) {
						if (apogee == atoi(lines[i])) { //    Comparing the given apogee with students apogees
							lines[i - 2][strcspn(lines[i - 2], "\n")] = '\0'; //    Remove the newline character from the end of the string
							printf("%-10s | ", lines[i - 2]); //    Print to the user the student information
							fprintf(ResearchHistory, "%-10s | ", lines[i - 2]); //    Update the searching history
							lines[i - 1][strcspn(lines[i - 1], "\n")] = '\0';
							printf("%-10s | ", lines[i - 1]);
							fprintf(ResearchHistory, "%-10s | ", lines[i - 1]);
							lines[i][strcspn(lines[i], "\n")] = '\0';
							printf("%-10s | ", lines[i]);
							fprintf(ResearchHistory, "%-10s | ", lines[i]);
							lines[i + 1][strcspn(lines[i + 1], "\n")] = '\0'; 
							printf("%-10s | ", lines[i + 1]);
							fprintf(ResearchHistory, "%-10s | ", lines[i + 1]);
							lines[i + 2][strcspn(lines[i + 2], "\n")] = '\0';
							printf("%-10s | ", lines[i + 2]);
							fprintf(ResearchHistory, "%-10s | ", lines[i + 2]);
							lines[i + 3][strcspn(lines[i + 3], "\n")] = '\0';
							printf("%-10s\n", lines[i + 3]);
							fprintf(ResearchHistory, "%-10s\n", lines[i + 3]);
							boolean = true; //    fact that the given apogee exists is TRUE
							break; //    apogee is unic
						}
			    	}
			    	fprintf(ResearchHistory, "\n");
			    	if (!boolean) { //     fact that the given apogee exists is TRUE
			    		printf("\nThere is no student in the list has the provided apogee\n\n");
			    		Research = fopen("NumberOfReasearches.txt", "w");
						fprintf(Research, "%d", --(*numberOfResearches));
						fclose(Research);
					}
					fclose(ResearchHistory);
			    	printf("\n");
					GoBack(next);
				}
				else choice = 'e';
			} while (choice == 'e');
		}
		else continu = 'e';
	} while (continu == 'e');
}
