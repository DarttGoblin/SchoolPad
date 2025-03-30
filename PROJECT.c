#include "ProjectMainFunctions.h"
#include "Research.h"
#include "Modify.h"
#include "Sort.h"

void Menu(Student *studentList, FILE *studentFile) { //    the main page contains the guide instructions
	char next, choice;
	int numberOfResearches;
	do {
		system("cls"); //	Clears the console from old outputs
		printf("Please, Insert one of the options below : \n\n");
		printf("Type 'a' if you'd like to add one student or more.\n");
		printf("Type 'm' if you'd like to modify a student's informtion.\n");
		printf("Type 'p' if you'd like to print the students list.\n");
		printf("Type 's' if you'd like to sort the students list.\n");
		printf("Type 'r' if you'd like to research for a student.\n");
		printf("Type 'd' if you'd like to delete a student.\n");
		printf("Type 'f' if you'd like to copy the students list.\n");
		printf("Type 'c' if you'd like to clear the students list.\n");
		printf("Type 'x' if you'd like to change your password.\n");
		printf("Type 'l' if you'd like to log out.\n");
		printf("Type 'b' if you'd like to know about this student management application.\n");
		printf("Type 'e' if you'd like to exit.\n\n");
		printf("Your answer : ");
		scanf(" %c", &choice);
		if (choice == 'e' || choice == 'E') exit(0);
		else if (choice == 'a' || choice == 'A') {
			Append(studentList, studentFile);
			Menu(studentList, studentFile);
		} 
		else if (choice == 'p' || choice == 'P') {
			Print(studentFile);
			Menu(studentList, studentFile);
		}
		else if (choice == 'm' || choice == 'M') {
			Modify(studentFile);
			Menu(studentList, studentFile);
		}
		else if (choice == 's' || choice == 'S') {
//			numberOfSorts = GetNumberOfSort();
//			Sort(studentFile, &SortHistory);
			Menu(studentList, studentFile);
		}
		else if (choice == 'r' || choice == 'R') {
			numberOfResearches = GetNumberOfResearches();
			Research(studentFile, &numberOfResearches);
			Menu(studentList, studentFile);
		}
		else if (choice == 'd' || choice == 'D') {
			Delete(studentFile);
			Menu(studentList, studentFile);
		}
		else if (choice == 'f' || choice == 'F') {
			CopyFile(studentFile);
			Menu(studentList, studentFile);
		}
		else if (choice == 'c' || choice == 'C') {
			Clear(studentFile);
			Menu(studentList, studentFile);
		}
		else if (choice == 'x' || choice == 'X') {
			ChangePassword();
			Menu(studentList, studentFile);
		}
		else if (choice == 'l' || choice == 'L') {
			LogOut();
			Menu(studentList, studentFile);
		}
		else if (choice == 'b' || choice == 'B') {
			system("cls");
			printf("Welcome to * About Application * section\n\n");
			printf("Welcome to our student information list management application!\n");
			printf("This powerful tool is designed to help you manage all of your students'\n");
			printf("information in one convenient location.\n");
			printf("Whether you're a teacher, school administrator, or education professional,\n");
			printf("our application can help you stay organized and streamline your workflow.\n");
			printf("With our application, you can easily store and manage information such as\n");
			printf("student names, contact information, grades, attendance records, and more.\n");
			printf("You can quickly search and filter through your student list to find the\n");
			printf("information you need, and update records with just a few clicks.\n");
			printf("Our application is also designed with security in mind, so you can rest\n");
			printf("assured that all of your students' data is safe and protected.\n\n");
			GoBack(next);
			Menu(studentList, studentFile);
		}
		else choice = 'n';
	} while (choice == 'n');
}
int main() { //	   main function to excute the management
	//	Student list system management
	
	FILE *studentFile;
	FILE *savedPassword;
	Student *studentList = (Student*)malloc(sizeof(Student));
	if (!studentList) {
		printf("Error in mallocation\n");
		exit(1);
	}
	Password();
	Menu(studentList, studentFile);
	free(studentList);
	return 0;
}
