#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
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

typedef struct {
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
} Employee;

void EmptySpaces(Employee list[], int len, int* flagEmptyList);

int initEmployees(Employee list[], int len);

int addEmployees(Employee list[], int len, int id, char name[], char lastName[], float salary, int sector);
int GetEmployee(Employee list[], int len, int* countId);
int LookForEmptySpace(Employee list[], int len, int* index);

int findEmployeeById(Employee list[], int len, int id);
int removeEmployee(Employee list[], int len, int id);

int printOneEmployee(Employee list);
int printEmployees(Employee list[], int length);

int ModifyEmployee(Employee list[], int len, int tam);
int GetOccupiedId(Employee list[], int len);

void InformSubMenu(Employee list[], int len, int tam, int* mainMenuOption);
int sortEmployees(Employee list[], int len, int order);
void SortAtoZ(Employee list[], int len);
void SortZtoA(Employee list[], int len);
void SortById(Employee list[], int len);
int AverageSalaries(Employee list[], int len);

int GetOrder(char order[], int len);
int GetDataToModify(void);
int GetSector();
void TopPartChart();
void BottomPartChart();

#endif /* ARRAYEMPLOYEES_H_ */
