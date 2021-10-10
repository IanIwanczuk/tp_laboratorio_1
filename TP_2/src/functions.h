#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#define VACIO 0
#define CARGADO 1

#define OCCUPIED 0
#define FREE 1

#define ADMIN 1
#define RECEPTION 2
#define	OFFICE 3
#define SECURITY 4

#define ATOZ 1
#define ID 2
#define ZTOA 0

#define NAME 1
#define LASTNAME 2
#define SALARY 3
#define SECTOR 4

int GetString(char mensaje[], char cadena[], int tam);
void GetOption(char opcion[], int tam, int* intOpcion);
int SwapEnterFgets(char verifyArray[]);

int GetInt(char mensaje[], char errorMsg[], int* number);
int GetIntWithRange(char mensaje[], char errorMsg[], int* number, int min, int max);
int GetIntNoVerification(char mensaje[], int* number);
int GetFloatWithRange(char mensaje[], char errorMsg[], float* number, int min, int max);
int GetFloat(char mensaje[], char errorMsg[], float* number);

int CheckIfNumber(char verifyArray[]);
int CheckIfInt(char number[]);
int CheckIfName(char name[]);

int CountPeriodInString(char countArray[], int tam);
int CountMinusInString(char countArray[], int tam);
int SortName(char name[]);

#endif /* FUNCTIONS_H_ */
