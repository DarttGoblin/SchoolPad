//#include "ProjectMainFunctions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Sort.h"
#include "Functions.h"

void Sort(FILE *studentFile, int *numberOfSorts) { //    Sort the student list by given method and given order
	char decision, next, continu, orderType, lines[1000][100], tempString[100];
	int i, j, line_count = GetFile(studentFile, lines), smallest;
	FILE *SortHistory;
	do {
		system("cls");
		printf("Welcome to *Sort Students lists* section\n\n");
		printf("Type 'c' if you'd like to continue or 'g' if you'd like to go back : ");
		scanf(" %c", &continu);
		if (continu == 'g' || continu == 'G') {}
		else if (continu == 'c' || continu == 'C') {
			do {
				printf("\nIn which method you'd like to sort students list?\n");
				printf("Please insert one of the options bellow :\n\n");
				printf("Type 'f' if you want sorting based on first name\n");
				printf("Type 'l' if you want sorting based on last name\n");
				printf("Type 'a' if you want sorting based on apogee number\n");
//				printf("Type 'n' if you want sorting based on average note\n\");
//				printf("Type 'n' if you want sorting based on subscribtion date \n\nYour answer : ");
				scanf(" %c", &decision);
				if (decision == 'f' || decision == 'F') {
					do {
						WhichOrder();
						scanf(" %c", &orderType);
						if (orderType == 'a' || decision == 'A') {
				    		for (i = 0; i < line_count - 7; i += 7) {
				    			smallest = i;
				    			for (j = smallest + 7; j < line_count; j += 7) {
				    				if (strcmp(lines[smallest], lines[j]) < 0) {
				    					smallest = j;
									}
								}
								CopyContent(lines, i, smallest);
				  			}
				  			SortHistory = fopen("SortHistory.txt", "a");
				  			OpenFile(SortHistory);
				  			fprintf(SortHistory, "Sorting number %d : \n\n", *numberOfSorts);
				  			fprintf(SortHistory, "F.Name     | L.Name     | Apogee     | Formation  | Average    | Inscription.D\n");
							fprintf(SortHistory, "------------------------------------------------------------------------------\n");
			    			for (i = 0; i < line_count; i++) {
			    				fprintf(SortHistory, "%s", lines[i]);
							}
							fprintf(SortHistory, "\n");
							fclose(studentFile);
						}
						else if (orderType == 'd') {
							for (i = 0; i < line_count - 7; i += 7) {
				    			smallest = i;
				    			for (j = smallest + 7; j < line_count; j += 7) {
				    				if (strcmp(lines[smallest], lines[j]) > 0) {
				    					smallest = j;
									}
								}
								CopyContent(lines, i, smallest);
				  			}
//				  			sortHistory = fopen("SortHistory.txt", "a");
//				  			OpenFile(studentFile);
//			    			fprintf("")
//							for (i = 0; i < line_count; i++) {
//			    				fprintf(studentFile, "%s", lines[i]);
//							}
//							fclose(studentFile);
						}
			    		else orderType = 'n';
					} while (orderType == 'n');
				}
				else if (decision == 'l' || decision == 'L') {
				do {
						WhichOrder();
						scanf(" %c", &orderType);
						if (orderType == 'a' || decision == 'A') {
				    		for (i = 1; i < line_count - 7; i += 7) {
				    			smallest = i;
				    			for (j = smallest + 7; j < line_count; j += 7) {
				    				if (strcmp(lines[smallest], lines[j]) < 0) {
				    					smallest = j;
									}
								}
				  				CopyContent(lines, i - 1, smallest - 1);
				  			}
				  			studentFile = fopen("StudentFile.txt", "w");
				  			OpenFile(studentFile);
			    			for (i = 0; i < line_count; i++) {
			    				fprintf(studentFile, "%s", lines[i]);
							}
							fclose(studentFile);
						}
						else if (orderType == 'd') {
							for (i = 1; i < line_count - 7; i += 7) {
				    			smallest = i;
				    			for (j = smallest + 7; j < line_count; j += 7) {
				    				if (strcmp(lines[smallest], lines[j]) > 0) {
				    					smallest = j;
									}
								}
				  				CopyContent(lines, i - 1, smallest - 1);
				  			}
				  			studentFile = fopen("StudentFile.txt", "w");
				  			OpenFile(studentFile);
			    			for (i = 0; i < line_count; i++) {
			    				fprintf(studentFile, "%s", lines[i]);
							}
							fclose(studentFile);
						}
			    		else orderType = 'n';
					} while (orderType == 'n');
				}
				else if (decision == 'a' || decision == 'A') {
					do {
						WhichOrder();
						scanf(" %c", &orderType);
						if (orderType == 'a' || decision == 'A') {
				    		for (i = 2; i < line_count - 7; i += 7) {
				    			smallest = i;
				    			for (j = smallest + 7; j < line_count; j += 7) {
				    				if (atoi(lines[smallest]) > atoi(lines[j])) {
				    					smallest = j;
									}
								}
				  				CopyContent(lines, i - 2, smallest - 2);
				  			}
				  			studentFile = fopen("StudentFile.txt", "w");
				  			OpenFile(studentFile);
			    			for (i = 0; i < line_count; i++) {
			    				fprintf(studentFile, "%s", lines[i]);
							}
							fclose(studentFile);
						}
						else if (orderType == 'd') {
							for (i = 2; i < line_count - 7; i += 7) {
				    			smallest = i;
				    			for (j = smallest + 7; j < line_count; j += 7) {
				    				if (atoi(lines[smallest]) < atoi(lines[j])) {
				    					smallest = j;
									}
								}
				  				CopyContent(lines, i - 2, smallest - 2);
				  			}
				  			studentFile = fopen("StudentFile.txt", "w");
				  			OpenFile(studentFile);
			    			for (i = 0; i < line_count; i++) {
			    				fprintf(studentFile, "%s", lines[i]);
							}
							fclose(studentFile);
						}
			    		else orderType = 'n';
					} while (orderType == 'n');
				}	
				else if (decision == 'n' || decision == 'N') {
					do {
						WhichOrder();
						scanf(" %c", &orderType);
						if (orderType == 'a' || decision == 'A') {
				    		for (i = 4; i < line_count - 7; i += 7) {
				    			smallest = i;
				    			for (j = smallest + 7; j < line_count; j += 7) {
				    				if (atoi(lines[smallest]) > atoi(lines[j])) {
				    					smallest = j;
									}
								}
				  				CopyContent(lines, i - 4, smallest - 4);
				  			}
				  			studentFile = fopen("StudentFile.txt", "w");
				  			OpenFile(studentFile);
			    			for (i = 0; i < line_count; i++) {
			    				fprintf(studentFile, "%s", lines[i]);
							}
							fclose(studentFile);
						}
						else if (orderType == 'd') {
							for (i = 4; i < line_count - 7; i += 7) {
				    			smallest = i;
				    			for (j = smallest + 7; j < line_count; j += 7) {
				    				if (atoi(lines[smallest]) < atoi(lines[j])) {
				    					smallest = j;
									}
								}
				  				CopyContent(lines, i - 4, smallest - 4);
				  			}
				  			studentFile = fopen("StudentFile.txt", "w");
				  			OpenFile(studentFile);
			    			for (i = 0; i < line_count; i++) {
			    				fprintf(studentFile, "%s", lines[i]);
							}
							fclose(studentFile);
						}
			    		else orderType = 'n';
					} while (orderType == 'n');
				}
				else decision = 'e';
			} while (decision == 'e');
			system("cls");
			printf("The student list has been sorted successefuly.\n");
			GoBack(next);
		}
		else continu = 'e';
	} while (continu == 'e');
}
