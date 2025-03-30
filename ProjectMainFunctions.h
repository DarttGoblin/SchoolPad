#ifndef ProjectMainFunctions_H
#define ProjectMainFunctions_H

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
//  Functions
int GetNumberOfSort() {
	char *buffer = (char*)malloc(100);
	FILE *NumberOfSorts = fopen("numberOfSorts.txt", "r");
	while (fgets(buffer, 5, NumberOfSorts)) {}; //    Get the number of sorts from file
	int numberOfSorts = atoi(buffer); //    converting the string given from file to integer
	return numberOfSorts;
}
int GetNumberOfResearches() {
	char *buffer = (char*)malloc(100);
	FILE *NumberOfResearches = fopen("NumberOfResearches.txt", "r");
	while (fgets(buffer, 5, NumberOfResearches)) {}; //    Get the number of researches from file
	int numberOfResearches = atoi(buffer); //    convertinbg the string given from file to integer
	return numberOfResearches;
}
void MallocError(char *pointer) { //	Check strings mallocation
	if (!pointer) {
		printf("\nError in mallocation\n");
		exit(0);
	}
}
void GoBack(char next) { //    return to previous page, created to avoid repeated instructions
	do {
   		printf("Type 'g' to go back to menu : ");
	    scanf(" %c", &next);
   	} while (next != 'g' && next != 'G');
}
void OpenFile(FILE *file) { //   Check the file opening
	if (!file) {
		printf("Error: Unable to open file.");
		exit(0);
	}
}
int GetFile(FILE *studentFile, char (*lines)[100]) { //    read and store file content avoiding repetetive instructions
	char *buffer = (char*)malloc(100);
    int line_count = 0;
    studentFile = fopen("StudentFile.txt", "r");
    OpenFile(studentFile);
    while (fgets(buffer, 100, studentFile)){
        strcpy(lines[line_count], buffer);
        line_count++;
    }
    free(buffer);
    fclose(studentFile);
    return line_count;
}
void WhichOrder() { //    Created to avoid repeated instruction, used in Sort function
	system("cls");
	printf("Which order you'd like to sort with?\n");
	printf("Type 'a' if you want sorting based on ascending order\n");
	printf("Type 'd' if you want sorting based on descending order\n\nYour answer : ");
}
int GetLength(FILE *studentFile) { //	Able to know students number directly from file
	char lines[1000][100]; //    intialisation of lines number
	return (GetFile(studentFile, lines) / 7); //    return number of students by deviding number of lines over seven (number of student information by each line)
}
void CopyContent(char (*lines)[100], int i, int smallest) { //	  Switch array lines in Sort function to avoid repeated instructions
	char tempString[100];
	sprintf(tempString, "%s", lines[i]); //	   for first name
	sprintf(lines[i], "%s", lines[smallest]);
	sprintf(lines[smallest], "%s", tempString);
	sprintf(tempString, "%s", lines[i + 1]); //    for last name
	sprintf(lines[i + 1], "%s", lines[smallest + 1]);
	sprintf(lines[smallest + 1], "%s", tempString);
	sprintf(tempString, "%s", lines[i + 2]); //    for apogee number
	sprintf(lines[i + 2], "%s", lines[smallest + 2]);
	sprintf(lines[smallest + 2], "%s", tempString);
	sprintf(tempString, "%s", lines[i + 3]); //    for formation
	sprintf(lines[i + 3], "%s", lines[smallest + 3]);
	sprintf(lines[smallest + 3], "%s", tempString);
	sprintf(tempString, "%s", lines[i + 4]); //    for average note
	sprintf(lines[i + 4], "%s", lines[smallest + 4]);
	sprintf(lines[smallest + 4], "%s", tempString);
	sprintf(tempString, "%s", lines[i + 5]); //    for birth date
	sprintf(lines[i + 5], "%s", lines[smallest + 5]);
	sprintf(lines[smallest + 5], "%s", tempString);
}
void Password() { //   permission to access
	FILE *savedPassword;
    char *buffer = (char*)malloc(100), access = 0;
    savedPassword = fopen("Password.txt", "r"); // opening password file
    while (fgets(buffer, 100, savedPassword)) {} // getting password from file
    fclose(savedPassword);
    char *inputPassword = (char*)malloc(100); // password taken from user
    do {
        printf("Insert your password, to exit insert 'e'\nYour answer : ");
        scanf("%s", inputPassword);
        realloc(inputPassword, strlen(inputPassword) + 1);
        inputPassword[strlen(inputPassword)] = '\0';
        if (strcmp(inputPassword, "e") == 0) exit(0);
        else if (strcmp(inputPassword, buffer) == 0) access = 1;
        else {
            system("cls");
            printf("The password is incorrect\n");
            access = 0;
        }
    } while (access == 0);
    free(inputPassword);
    free(buffer);
}
void ChangePassword() { //	Change current password with new one
	FILE *savedPassword;
	char next, choice, answer, *newPassword = (char*)malloc(100);
	do {
		system("cls");
		printf("Are you sure you want to change your password?\n");
		printf("Type 'y' for yes or 'n' for no : ");
		scanf(" %c", &answer);
		if (answer == 'n' || answer == 'N') {}
		else if (answer == 'y' || answer == 'Y') {
			Password(); //   Check from user by putting current password
			printf("Insert your new password.\nYour answer : ");
			scanf("%s", newPassword);
			realloc(newPassword, strlen(newPassword) + 1);
			newPassword[strlen(newPassword)] = '\0';
			savedPassword = fopen("Password.txt", "w"); //    write over in password file with the new password
			fprintf(savedPassword, "%s", newPassword);
			fclose(savedPassword);
			system("cls");
			printf("Password has been modified successefully.\n");
			GoBack(next);
		}
		else answer = 'e';
	} while (answer == 'e');
}
void LogOut() { //    Ask permission again
	char continu;
	do {
		system("cls");
		printf("Are you sure you want to log out?\n");
		printf("Type c to continue or g to go back : ");
		scanf(" %c", &continu);
		if (continu == 'g' || continu == 'G') {}
		else if (continu == 'c' || continu == 'C') {
			system("cls");
			printf("Log out have been done successfully!\n");
			Password();
		}
		else continu = 'e';
	} while (continu == 'e');
}
void Clear(FILE *studentFile) { //	  clears the student file
	char continu, next;
	do {
		system("cls");
		printf("Are you sure you want to clear the student list?\n");
		printf("Type c to continue or g to go back : ");
		scanf(" %c", &continu);
		if (continu == 'c' || continu == 'C') {
			studentFile = fopen("StudentFile.txt", "w");
			OpenFile(studentFile);
			fclose(studentFile);
			printf("The student list has been cleared successefuly.");
			GoBack(next);
		}
		else if (continu == 'g' || continu == 'G') {}
		else continu = 'e';
	} while (continu == 'e');
}
void Print(FILE *studentFile) { //	Prints the student list
	char next, text[100];
	int i;
	studentFile = fopen("StudentFile.txt", "r");
	OpenFile(studentFile);
    fseek(studentFile, 0, SEEK_END); //    Move the file pointer to the end of the file
	long size = ftell(studentFile); //    Get the current position of the file pointer, which is equal to the file size
   	if (size == 0) {
       	// File is empty
       	system("cls");
       	printf("Welcome to *Print Students lists* section\n\n");
       	printf("Students list is empty!\n\n");
   	}
	else {
		
  		// File is not empty, move the file pointer back to the beginning of the file
      	fseek(studentFile, 0, SEEK_SET);
    	system("cls");
      	printf("Welcome to *Print Students lists* section\n\n");
      	int var = 0;
      	printf("F.Name     | L.Name     | Apogee     | Formation  | Average    | Inscription.D\n");
      	printf("------------------------------------------------------------------------------\n");
       	while (fgets(text, 100, studentFile)) {
    		if (strcmp(text, "\n") == 0) {} //    Skip empty lines
			else {
    		    text[strcspn(text, "\n")] = '\0'; //    Remove the newline character from the end of the string
    		    
    		    if (var != 5) { //    Print the student information, separated by pipes
    		        printf("%-10s | ", text);
    			        var++;
    	   	 	} else {
    	   	    	printf("%-10s\n", text);
    	        	var = 0;
    	   		}
    		}
		}
    }
    fclose(studentFile);
    printf("\n");
	GoBack(next);
}
void Append(Student *studentList, FILE *studentFile) { //	Append new students to the list
	char lines[1000][100], next, choice;
	int i, j, numOfStudent, length = GetLength(studentFile), line_count = GetFile(studentFile, lines);
	bool boolean;
	do {
		system("cls");
		printf("Welcome to *Add Student* section\n\n");
		printf("Type 'c' if you'd like to continue or 'g' if you'd like to go back : ");
		scanf(" %c", &choice);
		if (choice == 'g') {}
		else if (choice == 'c' || choice == 'C') {
			do {
				printf("How many students you'd like to add : ");
				scanf("%d", &numOfStudent);
			} while (numOfStudent <= 0);
			realloc(studentList, (length + numOfStudent) * sizeof(Student)); //	Reallocate the list with new size
			for (i = length; i < length + numOfStudent; i++) {
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
					for (j = 2; j < line_count; j += 7) { //    loop to campare taken apogge with previous ones
						if ((studentList + i)->Apogee == atoi(lines[j])) {
							printf("The Apogee number you entered already exists!\n");
							boolean = true; //    do while loop condition, stay false if "if condition" was skipped
							break;
						}
					}
				} while (boolean);
				(studentList + i)->formation = (char*)malloc(100);
				do {
					printf("Insert student's formation from bellow\nSMIA - SMPC - SMI - SMA - SMP - SMC : ");
					scanf("%s", (studentList + i)->formation);
				} while
				(strcmp((studentList + i)->formation, "SMIA") != 0 && strcmp((studentList + i)->formation, "smia") != 0 &&
				strcmp((studentList + i)->formation, "SMPC") != 0 && strcmp((studentList + i)->formation, "smpc") != 0 &&
				strcmp((studentList + i)->formation, "SMI") != 0 && strcmp((studentList + i)->formation, "smi") != 0 &&
				strcmp((studentList + i)->formation, "SMA") != 0 && strcmp((studentList + i)->formation, "sma") != 0 &&
				strcmp((studentList + i)->formation, "SMP") != 0 && strcmp((studentList + i)->formation, "smp") != 0 &&
				strcmp((studentList + i)->formation, "SMC") != 0 && strcmp((studentList + i)->formation, "smc") != 0); //   App for FSSM student :)
				realloc((studentList + i)->formation, strlen((studentList + i)->formation) + 1);
				(studentList + i)->formation[strlen((studentList + i)->formation)] = '\0';
				MallocError(studentList->formation);		
				do {
					printf("Insert student's inscription day (1-31) : "); scanf("%d", &(studentList + i)->date.day);
					printf("Insert student's inscription month (1-12) : "); scanf("%d", &(studentList + i)->date.month);
					printf("Insert student's inscription year (2010-2023) : "); scanf("%d", &(studentList + i)->date.year);
				} while ((studentList + i)->date.day <= 0 || (studentList + i)->date.day > 31 || (studentList + i)->date.month <= 0 ||
				(studentList + i)->date.month > 12 || (studentList + i)->date.year < 2010 || (studentList + i)->date.year > 2023);
				do {
					printf("Insert the average note of the student : ");
					scanf("%f", &(studentList + i)->Average);
				} while ((studentList + i)->Average < 0 || (studentList + i)->Average > 20);
				studentFile = fopen("StudentFile.txt", "a"); //    Open file to append new info to it
				OpenFile(studentFile);
				fprintf(studentFile, "%s\n%s\n%d\n%s\n%g\n%02d/%02d/%d", (studentList + i)->firstName, (studentList + i)->lastName, (studentList + i)->Apogee, (studentList + i)->formation, (studentList + i)->Average, (studentList + i)->date.day, (studentList + i)->date.month, (studentList + i)->date.year);
				fprintf(studentFile, "\n\n");
				fclose(studentFile);
			}	
			system("cls");
			printf("Student has been appended successefully.\n");
			GoBack(next);
		}
		else choice = 'e';
	} while (choice == 'e');
	for (i = length; i < (length + numOfStudent); i++) { //    Free structures
		free((studentList + i)->firstName);
		free((studentList + i)->lastName);
		free((studentList + i)->formation);
	}
}
void Delete(FILE *studentFile) { //    Remove a student from the list
	char next, choice, lines[1000][100];
    int i, line_count = GetFile(studentFile, lines), apogee;
    bool boolean;
	do { //    Selecting student that would be deleted
		system("cls");
		printf("Welcome to *Delete a Student* section\n\n");
		printf("Type 'c' if you'd like to continue or type g to go back to the menu : ");
		scanf(" %c", &choice);
		if (choice == 'g' || choice == 'G') {}
		else if (choice == 'c' || choice == 'C') {
			printf("Insert student Apogee number : ");
			scanf("%d", &apogee);
			bool boolean = false;
			for (i = 2; i < line_count; i += 7) {
				if (apogee == atoi(lines[i])) {
					boolean = true;
					break;
				}
    		}
    		if (!boolean) {
    			printf("\nThere is no student in the list has the provided apogee\n\n");
    			GoBack(next);
			}
			else {
				studentFile = fopen("StudentFile.txt", "w");
	    		for (i = 0; i < line_count; i += 7) {
	        		if (atoi(lines[i + 2]) != apogee) {
	        		    fprintf(studentFile, "%s", lines[i]);
	        		    fprintf(studentFile, "%s", lines[i + 1]);
	        		    fprintf(studentFile, "%s", lines[i + 2]);
	        		    fprintf(studentFile, "%s", lines[i + 3]);
	        		    fprintf(studentFile, "%s", lines[i + 4]);
	        		    fprintf(studentFile, "%s", lines[i + 5]);
	        		    fprintf(studentFile, "%s", lines[i + 6]);
	   	     		}
	    		}
	    		fclose(studentFile);
    			system("cls");
				printf("The student has been removed successefully.\n");
				GoBack(next);
			}
		}
		else choice = 'e';
	} while (choice == 'e');
}
void CopyFile(FILE *studentFile) {
	FILE *FileCopied;
	char next, fileName[100], lines[1000][100];
	int line_count, i;
	do {
		system("cls");
		printf("Welcome to *Copy Student List* section\n\n");
		printf("Press 'c' to continue or 'g' to go back : ");
		scanf(" %c", &next);
	} while (next != 'c' && next != 'g' && next != 'C' && next != 'G');
	if (next == 'g') {}
	else {
		printf("Insert the name of the file you'd like to copy the student list to it without the extention.\nYour answer : ");
		scanf("%s", fileName);
		line_count = GetFile(studentFile, lines);
		FileCopied = fopen(strcat(fileName, " - CopiedFile.txt"), "w");
		for (i = 0; i < line_count; i++) {
			fprintf(FileCopied, "%s", lines[i]);
		}
		fclose(FileCopied);
		system("cls");
		printf("Student list has been copied successefully.\n");
		GoBack(next);
	}
}

#endif
