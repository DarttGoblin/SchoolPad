#ifndef Functions_H
#define Functions_H
#include <stdio.h>
#include "Structures.h"

int GetNumberOfSort();
int GetNumberOfResearches();
void MallocError(char *pointer);
void GoBack(char);
void OpenFile(FILE*);
int GetFile(FILE *, char**);
void WhichOrder();
int GetLength(FILE *);
void CopyContent(char**, int, int);
void Password();
void ChangePassword();
void LogOut();
void Clear(FILE *);
void Print(FILE *);
void Append(Student *, FILE *);
void Delete(FILE *);
void CopyFile(FILE *);


#endif
