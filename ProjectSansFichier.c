#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
//	Functions
void GoBack(char next) { //    return to previous page, created to avoid repeated instructions
	do {
   		printf("Type 'g' to go back to menu : ");
	    scanf(" %c", &next);
   	} while (next != 'g' && next != 'G');
}
void MallocError(char *pointer) { //	Check strings mallocation
	if (!pointer) {
		printf("\nError in mallocation\n");
		exit(0);
	}
}
void WhichOrder() { //    Created to avoid repeated instruction, used in Sort function
	system("cls");
	printf("Which order you'd like to sort with?\n");
	printf("Type 'a' if you want sorting based on ascending order\n");
	printf("Type 'd' if you want sorting based on descending order\n\nYour answer : ");
}
void Clear(Student *studentList, int *length) { //	  clears the student file
	char continu, next;
	int i;
	do {
		system("cls");
		printf("Are you sure you want to clear the student list?\n");
		printf("Type c to continue or g to go back!\nYour answer : ");
		scanf(" %c", &continu);
		if (continu == 'c' || continu == 'C') {
			for (i = 0; i < *length; i++) {
				free((studentList + i)->firstName);
				free((studentList + i)->lastName);
			}
			free(studentList);
			*length = 0;
		}
		else if (continu == 'g' || continu == 'G') {}
		else continu = 'e';
	} while (continu == 'e');
}
void Print(Student *studentList, int *length) { //	Prints the student list
	char next;
	int i;
	system("cls");
 	printf("Welcome to *Print Students lists* section\n\n");
	printf("F.Name     | L.Name     | Apogee     | Formation  | Average    | Inscription.D\n");
    printf("------------------------------------------------------------------------------\n");
	for (i = 0; i < *length; i++) {
		printf("%-10s | ", (studentList + i)->firstName);
		printf("%-10s | ", (studentList + i)->lastName);
		printf("%d          | ", (studentList + i)->Apogee);
//		printf("%-10s | ", (studentList + i)->formation);
//		printf("%g          | ", (studentList + i)->Average);
//		printf("%02d/%02d/%d\n", (studentList + i)->date.day, (studentList + i)->date.month, (studentList + i)->date.year);
	}
    printf("\n");
	GoBack(next);
}
void Append(Student *studentList, int *length) { //	Append new students to the list
	char next, choice;
	int i, j, numOfStudent;
	bool boolean;
	do {
		system("cls");
		printf("Welcome to *Add Student* section\n\n");
		printf("Type 'c' if you'd like to continue or 'g' if you'd like to go back : ");
		scanf(" %c", &choice);
		if (choice == 'g' || choice == 'G') {}
		else if (choice == 'c' || choice == 'C') {
			do {
				printf("How many students you'd like to add : ");
				scanf("%d", &numOfStudent);
			} while (numOfStudent <= 0);
			realloc(studentList, (*length + numOfStudent) * sizeof(Student)); //	Reallocate the list with new size
			for (i = *length; i < *length + numOfStudent; i++) {
				printf("Insert student's first name No %d : ", i + 1);
				(studentList + i)->firstName = (char*)malloc(100);
				scanf("%s", (studentList + i)->firstName);
				realloc((studentList + i)->firstName, strlen((studentList + i)->firstName) + 1); //		Realloc to newMinimisedSize
				(studentList + i)->firstName[strlen((studentList + i)->firstName)] = '\0'; //	EndOfString
				MallocError(studentList->firstName);
				printf("Insert student's last name : ");
				(studentList + i)->lastName = (char*)malloc(100);
				scanf("%s", (studentList + i)->lastName);
				realloc((studentList + i)->lastName, strlen((studentList + i)->lastName) + 1);
				(studentList + i)->lastName[strlen((studentList + i)->lastName)] = '\0';
				MallocError(studentList->lastName);
				do { //	   loop to get a unic apogee for each student
					boolean = false;
					do {
						printf("Insert student's Apogee numbre : ");
						scanf("%d", &(studentList + i)->Apogee);
					} while ((studentList + i)->Apogee <= 0);
					for (j = 0; j < *length; j++) { //    loop to campare taken apogge with previous ones
						if ((studentList + i)->Apogee == (studentList + j)->Apogee) {
							printf("The Apogee number you entered already exists!\n");
							boolean = true; //    do while loop condition, stay false if "if condition" was skipped
							break;
						}
					}
				} while (boolean);
//				(studentList + i)->formation = (char*)malloc(100);
//				do {
//					printf("Insert student's formation from bellow\nSMIA - SMPC - SMI - SMA - SMP - SMC : ");
//					scanf("%s", (studentList + i)->formation);
//				} while
//				(strcmp((studentList + i)->formation, "SMIA") != 0 && strcmp((studentList + i)->formation, "smia") != 0 &&
//				strcmp((studentList + i)->formation, "SMPC") != 0 && strcmp((studentList + i)->formation, "smpc") != 0 &&
//				strcmp((studentList + i)->formation, "SMI") != 0 && strcmp((studentList + i)->formation, "smi") != 0 &&
//				strcmp((studentList + i)->formation, "SMA") != 0 && strcmp((studentList + i)->formation, "sma") != 0 &&
//				strcmp((studentList + i)->formation, "SMP") != 0 && strcmp((studentList + i)->formation, "smp") != 0 &&
//				strcmp((studentList + i)->formation, "SMC") != 0 && strcmp((studentList + i)->formation, "smc") != 0); //   App for FSSM student :)
//				realloc((studentList + i)->formation, strlen((studentList + i)->formation) + 1);
//				(studentList + i)->formation[strlen((studentList + i)->formation)] = '\0';
//				MallocError(studentList->formation);		
//				do {
//					printf("Insert student's inscription day (1-31) : "); scanf("%d", &(studentList + i)->date.day);
//					printf("Insert student's inscription month (1-12) : "); scanf("%d", &(studentList + i)->date.month);
//					printf("Insert student's inscription year (2010-2023) : "); scanf("%d", &(studentList + i)->date.year);
//				} while ((studentList + i)->date.day <= 0 || (studentList + i)->date.day > 31 || (studentList + i)->date.month <= 0 ||
//				(studentList + i)->date.month > 12 || (studentList + i)->date.year < 2010 || (studentList + i)->date.year > 2023);
//				do {
//					printf("Insert the average note of the student : ");
//					scanf("%f", &(studentList + i)->Average);
//				} while ((studentList + i)->Average < 0 || (studentList + i)->Average > 20);
			}
			*length += numOfStudent;
			system("cls");
			printf("Student has been appended successefully.\n");
			GoBack(next);
		}
		else choice = 'e';
	} while (choice == 'e');
}
void Research(Student *studentList, int *length) { //    Prints a researched student information
    char next, choice, method, *name = (char*)malloc(100);
	int i, Apogee;
	bool boolean = false;
    do {
    	system("cls");
		printf("Welcome to *Research for a Student* section\n\n");
		printf("Type 'c' if you'd like to continue or type g to go back to the menu : ");
		scanf(" %c", &choice);
		if (choice == 'g' || choice == 'G') {}
		else if (choice == 'c' || choice == 'C') {
			do {
				printf("Which method you'd like to search with?\nYour answer : ");
				scanf(" %c", &method);
				if (method == 'f' || method ==  'F') {
					printf("Insert the student's first name : ");
					scanf("%s", name);
					realloc(name, strlen(name) + 1);
					name[strlen(name)] = '\0';
					for (i = 0; i < *length; i++) {
					    if (strcmp(name, (studentList->firstName)) == 0) {
							printf("F.Name     | L.Name     | Apogee     | Formation  | Average    | Inscription.D\n");
							printf("------------------------------------------------------------------------------\n");
							printf("%-10s | ", (studentList + i)->firstName);
							printf("%-10s | ", (studentList + i)->lastName);
							printf("%d          | ", (studentList + i)->Apogee);
//							printf("%-10s | ", (studentList + i)->formation);
//							printf("%g          | ", (studentList + i)->Average);
//							printf("%02d/%02d/%d\n", (studentList + i)->date.day, (studentList + i)->date.month, (studentList + i)->date.year);
						    boolean = true;
				   		}
					}   
					if (!boolean) {
						printf("\nThere is no student in the list has the provided apogee\n\n");
					}
				}
				else if (method == 'a' || method ==  'A') {
					printf("Insert the student's apogee : ");
					scanf("%d", &Apogee);
					for (i = 0; i < *length; i++) {
					    if (studentList->Apogee == Apogee) {
					        printf("Welcome to *Print Students lists* section\n\n");
							printf("F.Name     | L.Name     | Apogee     | Formation  | Average    | Inscription.D\n");
							printf("------------------------------------------------------------------------------\n");
							printf("%-10s | ", (studentList + i)->firstName);
							printf("%-10s | ", (studentList + i)->lastName);
							printf("%d          | ", (studentList + i)->Apogee);
//							printf("%-10s | ", (studentList + i)->formation);
//							printf("%g          | ", (studentList + i)->Average);
//							printf("%02d/%02d/%d\n", (studentList + i)->date.day, (studentList + i)->date.month, (studentList + i)->date.year);
						    boolean = true;
						    break;
				   		}
					}   
					if (!boolean) {
						printf("\nThere is no student in the list has the provided apogee\n\n");
					}
				}
				else method = 'e';
				GoBack(next);
			} while (method == 'e');
		}
	} while (choice == 'e');
}
void Sort(Student *studentList, int *length) { //    Sort the student list by given method and given order
	int i, j, smallest, tempApogee;
	char next, choice, method, way;
	Student tempStudent;
	do {
		system("cls");
		printf("Welcome to *Sort student list* section\n\n");
		printf("Type 'c' if you'd like to continue or type g to go back to the menu : ");
		scanf(" %c", &choice);
		if (choice == 'g' || choice == 'G') {}
		else if (choice == 'c' || choice == 'C') {
			do {
				printf("In which way you want to sort the student list?\n");
				printf("Type 'f' if you'd like to sort student based on the first name\n");
				printf("Type 'a' if you'd like to sort student based on the apogee number\nYour answer : ");
				scanf(" %c", &method);
				if (method == 'f' || method == 'F') {
					do {
						printf("In which way you want the student list to be sorted with?\n");
						printf("Type 'a' if you want to sort ascending\n");
						printf("Type 'd' if you want to sort descending\nYour answer : ");
						scanf(" %c", &way);
						if (way == 'a' || way == 'A') {
                            for (i = 0; i < *length - 1; i++) {
                                smallest = i;
                                for (j = i + 1; j < *length; j++) {
                                    if (strcmp(studentList[smallest].firstName, studentList[j].firstName) > 0) {
                                        smallest = j;
                                    }
                                }
                                if (smallest != i) {
                                    tempStudent = studentList[i];
                                    studentList[i] = studentList[smallest];
                                    studentList[smallest] = tempStudent;
                                }
                            }
                        } else if (way == 'd' || way == 'D') {
                            for (i = 0; i < *length - 1; i++) {
                                smallest = i;
                                for (j = i + 1; j < *length; j++) {
                                    if (strcmp(studentList[smallest].firstName, studentList[j].firstName) < 0) {
                                        smallest = j;
                                    }
                                }
                                if (smallest != i) {
                                    tempStudent = studentList[i];
                                    studentList[i] = studentList[smallest];
                                    studentList[smallest] = tempStudent;
                                }
                            }
                        } else way = 'e';
                    } while (way == 'e');
				}
				else if (method == 'a' || method == 'A') {
				    do {
				        printf("In which way you want the student list to be sorted with?\n");
				        printf("Type 'a' if you want to sort ascending\n");
				        printf("Type 'd' if you want to sort descending\nYour answer : ");
				        scanf(" %c", &way);
				        if (way == 'a' ||way == 'A') {
				            for (i = 0; i < *length - 1; i++) { //    Sorting based on the selection method
				                smallest = i;
				                for (j = i + 1; j < *length; j++) {
				                    if ((studentList + smallest)->Apogee > (studentList + j)->Apogee) {
				                        smallest = j;
				                    }
				                }
				                tempStudent = studentList[i];
				                studentList[i] = studentList[smallest];
				                studentList[smallest] = tempStudent;
				            }
				        }
				        else if (way == 'd' || way == 'D') {
				            for (i = 0; i < *length - 1; i++) { //    Sorting based on the selection method
				                smallest = i;
				                for (j = i + 1; j < *length; j++) {
				                    if ((studentList + smallest)->Apogee < (studentList + j)->Apogee) {
				                        smallest = j;
				                    }
				                }
				                tempStudent = studentList[i];
				                studentList[i] = studentList[smallest];
				                studentList[smallest] = tempStudent;
				            }
				        }
				        else way = 'e';
				    } while (way == 'e');
				}
				else method = 'e';
			} while (method == 'e');
		}
		else choice = 'e';
	} while (choice == 'e');
}
void Modify(Student *studentList, int *length) { //	   Modify a student information
	int i, Apogee;
    bool boolean = false;
    char next, choice;
    do {
    	system("cls");
    	printf("Welcome to *Modify a Student Information* section\n\n");
		printf("Type 'c' if you'd like to continue or type g to go back to the menu : ");
		scanf(" %c", &choice);
    	if (choice == 'g' || choice == 'G') {}
    	else if (choice == 'c' || choice == 'C') {
    		printf("Insert the student's apogee number whose inmformation you want to modify : ");
		    scanf("%d", &Apogee);
		    for (i = 0; i < *length; i++) {
		        if (studentList[i].Apogee == Apogee) {
		            printf("\nCurrent Information of the student:\n");
		            printf("First Name : %s\n", studentList[i].firstName);
		            printf("Last Name : %s\n", studentList[i].lastName);
		            printf("Apogee number : %d\n", studentList[i].Apogee);
//		            printf("Formation : %s\n", studentList[i].formation);
//		            printf("Average : %f\n", studentList[i].Average);
//		            printf("Date of Inscription : %02d/%02d/%d\n", studentList[i].date.day, studentList[i].date.month, studentList[i].date.year);
		            printf("\nInsert new information:\n");
		            printf("First Name : ");
		            scanf("%s", studentList[i].firstName);
		            printf("Last Name : ");
		            scanf("%s", studentList[i].lastName);
		            printf("Apogee number : ");
		            scanf("%d", &studentList[i].Apogee);
//		            printf("Formation : ");
//		            scanf("%s", studentList[i].formation);
//		            printf("Average : ");
//		            scanf("%f", &studentList[i].Average);
//		            printf("Date of Inscription (DD/MM/YYYY) : ");
//		            scanf("%d/%d/%d", &studentList[i].date.day, &studentList[i].date.month, &studentList[i].date.year);
		            system("cls");
					printf("The student's information has been modified successfully!\n");
		            GoBack(next);
		            boolean = true;
		            break;
		        }
		    }
		    if (!boolean) {
		        printf("\nThere is no student in the list has the provided apogee\n\n");
		        GoBack(next);
		    }
		}
		else choice = 'e';
	} while (choice == 'e');
}	
void Delete(Student *studentList, int *length) { //    Remove a student from the list
    char next, choice;
	int Apogee, i, j;
    bool boolean = false;
    do {
    	system("cls");
		printf("Welcome to *Research for a Student* section\n\n");
		printf("Type 'c' if you'd like to continue or type g to go back to the menu : ");
    	scanf(" %c", &choice);
    	if (choice == 'g' || choice == 'G') {}
    	else if (choice == 'c' || choice == 'C') {
			printf("Enter the Apogee of the student to delete: ");
		    scanf("%d", &Apogee);
		
		    // Search for the student with the matching apogee
		    for (i = 0; i < *length; i++) {
		        if ((studentList + i)->Apogee == Apogee) {
		            boolean = true;
		
		            // Free memory of the student's name fields
		            free((studentList + i)->firstName);
		            free((studentList + i)->lastName);
		
		            // Shift remaining elements in the array down by one to remove deleted student
		            for (j = i; j < (*length) - 1; j++) {
		                *(studentList + j) = *(studentList + j + 1);
		            }
		            
		            // Decrement the length of the array to reflect the removed student
		            (*length)--;
		            system("cls");
					printf("Student has been removed successefully.\n");
					GoBack(next);
		            break;
		        }
		    }
		    if (!boolean) {
		        printf("\nThere is no student in the list has the provided apogee\n\n");
		        GoBack(next);
		    }
		}
		else choice = 'e';
	} while (choice == 'e');
}
void Menu(Student *studentList, int *length) { //    the main page contains the guide instructions
	char choice;
	do {
		system("cls"); //	Clears the console from old outputs
		printf("Please, Insert one of the options below : \n\n");
		printf("Type 'a' if you'd like to add one student or more.\n");
		printf("Type 'm' if you'd like to modify a student's informtion.\n");
		printf("Type 'p' if you'd like to print the students list.\n");
		printf("Type 's' if you'd like to sort the students list.\n");
		printf("Type 'r' if you'd like to research for a student.\n");
		printf("Type 'd' if you'd like to delete a student.\n");
		printf("Type 'c' if you'd like to clear the students list.\n");
		printf("Type 'e' if you'd like to exit.\n\n");
		printf("Your answer : ");
		scanf(" %c", &choice);
		if (choice == 'e' || choice == 'E') exit(0);
		else if (choice == 'a' || choice == 'A') {
			Append(studentList, length);
			Menu(studentList, length);
		} 
		else if (choice == 'p' || choice == 'P') {
			Print(studentList, length);
			Menu(studentList, length);
		}
		else if (choice == 'm' || choice == 'M') {
			Modify(studentList, length);
			Menu(studentList, length);
		}
		else if (choice == 's' || choice == 'S') {
			Sort(studentList, length);
			Menu(studentList, length);
		}
		else if (choice == 'r' || choice == 'R') {
			Research(studentList, length);
			Menu(studentList, length);
		}
		else if (choice == 'd' || choice == 'D') {
			Delete(studentList, length);
			Menu(studentList, length);
		}
		else if (choice == 'c' || choice == 'C') {
			Clear(studentList, length);
			Menu(studentList, length);
		}
		else choice = 'n';
	} while (choice == 'n');
}
int main() { //	   main function to excute the management
	//	Student list system management (WITHOUT FILES)
	
	int length = 0;
	Student *studentList = (Student*)malloc(sizeof(Student));
	if (!studentList) {
		printf("Error in mallocation\n");
		exit(1);
	}
	Menu(studentList, &length);
	free(studentList);
	return 0;
}
