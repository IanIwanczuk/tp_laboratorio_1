#include "ArrayEmployees.h"
#include "functions.h"

int initEmployees(Employee list[], int len){
	int retorno;
	retorno = -1;
	if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(list[i].isEmpty != CARGADO){    // <---- SI LA LISTA YA ESTA CARGADA.
				list[i].isEmpty = VACIO;
				retorno = 0;
			}
		}
	}
	return retorno;
}

void EmptySpaces(Employee list[], int len, int* flagEmptyList){
	int contEmpty;
	int i;
	contEmpty = 0;
	*flagEmptyList = CARGADO;

	for(i = 0; i < len; i++){
		if(list[i].isEmpty == VACIO){
			contEmpty++;
		}
	}
	if(contEmpty == len){
		*flagEmptyList = VACIO;
	}
}

int LookForEmptySpace(Employee list[], int len, int* index){
	int retorno;
	retorno = -1;
	if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(list[i].isEmpty == VACIO){
				*index = i;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}



int findEmployeeById(Employee list[], int len, int id){
	int retorno;
	retorno = -1;
	if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(list[i].id == id && list[i].isEmpty == CARGADO){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int removeEmployee(Employee list[], int len, int id){
	int retorno;
	int index;
	retorno = -1;
	index = findEmployeeById(list, len, id);
	if(list != NULL && len > 0){
		if(findEmployeeById(list, len, id) == -1){
			index = GetOccupiedId(list, len);
		}
		list[index].isEmpty = VACIO;
		retorno = 0;
	}
	return retorno;
}



int GetEmployee(Employee list[], int len, int* countId){
	int sector;
	float salary;
	char name[51];
	char lastName[51];
	int retorno;
	int id;
	retorno = -1;
	if(list != NULL && len > 0){
		id = *countId;
		*countId = *countId + 1;

		GetString(">>> Ingrese su nombre: ", name, 51);
		while(CheckIfName(name) == 0){
			printf(">>> Error, nombre invaildo. ");
			GetString("Reingrese un nombre: ", name, 51);
		}
		SortName(name);
		GetString(">>> Ingrese su apellido: ", lastName, 51);
		while(CheckIfName(lastName) == 0){
			printf(">>> Error, apellido invaildo. ");
			GetString("Reingrese un apellido: ", lastName, 51);
		}
		SortName(lastName);
		GetFloatWithRange(">>> Ingrese su salario (5000-85000): ", "Salario invalido. ", &salary, 5000, 85000);
		sector = GetSector();

		retorno = 0;
		if(addEmployees(list, len, id, name, lastName, salary, sector) == -1){
			retorno = 1;
		}

	}
	if(retorno == 0){
		printf(">>> Se aniadio el empleado correctamente.\n");
	}
	return retorno;
}

int addEmployees(Employee list[], int len, int id, char name[], char lastName[], float salary, int sector)
{
	int retorno;
	int i;
	retorno = LookForEmptySpace(list, len, &i);
	if(list != NULL && len > 0 && name != NULL && lastName != NULL){
		if(retorno == 0){
			list[i].id = id;
			list[i].isEmpty = CARGADO;
			strcpy(list[i].lastName, lastName);
			strcpy(list[i].name, name);
			list[i].salary = salary;
			list[i].sector = sector;
		}
	}
	return retorno;
}



int printEmployees(Employee list[], int len){
	int retorno;
	retorno = -1;
	if(list != NULL && len > 0){
		retorno = 0;
		TopPartChart();
		for(int i = 0; i < len; i++){
			if(list[i].isEmpty == CARGADO){
				printOneEmployee(list[i]);
				printf("\n");
			}
		}
		BottomPartChart();
	}
	return retorno;
}

int printOneEmployee(Employee list){
	int retorno;
	retorno = 0;
	printf("| %-5d | %-20s | %-15s | %-15.2f | ", list.id, list.lastName, list.name, list.salary);

	switch(list.sector){
		case ADMIN:
			printf("%-20s |", "Administracion");
		break;
		case RECEPTION:
			printf("%-20s |", "Recepcion");
		break;
		case OFFICE:
			printf("%-20s |", "Oficina");
		break;
		case SECURITY:
			printf("%-20s |", "Seguridad");
		break;
	}
	return retorno;
}



int ModifyEmployee(Employee list[], int len, int tam){
	float salary;
	char name[tam];
	char lastName[tam];
	int dataToModify;
	int retorno;
	int index;
	int id;
	retorno = -1;
	if(list != NULL && len > 0){
		SortById(list, len);
		printEmployees(list, len);
		GetIntNoVerification(">>> Ingrese el ID del empleado a modificar: ", &id);
		if(findEmployeeById(list, len, id) == -1){
			index = GetOccupiedId(list, len);
		} else {
			index = findEmployeeById(list, len, id);
		}
		dataToModify = GetDataToModify();

		switch(dataToModify){
			case NAME:
				GetString(">>> Ingrese el nuevo nombre: ", name, tam);
				while(CheckIfName(name) == 0){
					printf(">>> Error, nombre invaildo. ");
					GetString("Reingrese un nombre: ", name, tam);
				}
				SortName(name);
				strcpy(list[index].name, name);
			break;

			case LASTNAME:
				GetString(">>> Ingrese el nuevo apellido: ", lastName, tam);
				while(CheckIfName(lastName) == 0){
					printf(">>> Error, apellido invaildo. ");
					GetString("Reingrese un apellido: ", lastName, tam);
				}
				SortName(lastName);
				strcpy(list[index].lastName, lastName);
			break;

			case SALARY:
				GetFloatWithRange(">>> Ingrese el nuevo salario (5000-85000): ", ">>> Salario invalido, reingrese un salario (5000-85000): ", &salary, 5000, 85000);
				list[index].salary = salary;
			break;

			case SECTOR:
				list[index].sector = GetSector();
			break;
		}
		retorno = 0;
	}
	if(retorno == 0){
		printf(">>> Se modificó la lista de forma exitosa.\n");
	}
	return retorno;
}

int GetDataToModify(){
	int dataToChange;
	int countRetries;
	char modification[51];
	countRetries = 0;
	dataToChange = -1;
	printf(">>> (Nombre / Apellido / Salario / Sector)\n");
	GetString(">>> Ingrese que dato desea modificar: ", modification, 51);
	while(stricmp(modification, "nombre") != 0 && stricmp(modification, "apellido") != 0 && stricmp(modification, "sector") != 0 && stricmp(modification, "salario") != 0){
		GetString(">>> Error, ingrese un dato valido: ", modification, 51);
		countRetries++;
		if(countRetries == 5){
			printf(">>> (Nombre / Apellido / Salario / Sector)\n");
			countRetries = 0;
		}
	}
	if(stricmp(modification, "nombre") == 0){
		dataToChange = NAME;
	} else if(stricmp(modification, "apellido") == 0){
		dataToChange = LASTNAME;
	} else if(stricmp(modification, "salario") == 0){
		dataToChange = SALARY;
	} else {
		dataToChange = -1;
		if(stricmp(modification, "sector") == 0){
			dataToChange = SECTOR;
		}
	}
	return dataToChange;
}

int GetSector(){
	char sectorEmployee[51];
	int sectorNumber;
	int countRetries;
	countRetries = 0;
	sectorNumber = -1;
	printf(">>> (Administracion / Recepcion / Oficinas / Seguridad)\n");
	GetString(">>> Ingrese el sector: ", sectorEmployee, 51);
	while(stricmp(sectorEmployee, "administracion") != 0 && stricmp(sectorEmployee, "recepcion") != 0 && stricmp(sectorEmployee, "oficinas") != 0 && stricmp(sectorEmployee, "seguridad") != 0){
		GetString(">>> Error, ingrese un sector valido: ", sectorEmployee, 51);
		countRetries++;
		if(countRetries == 5){
			printf(">>> (Administracion / Recepcion / Oficinas / Seguridad)\n");
			countRetries = 0;
		}
	}
	if(stricmp(sectorEmployee, "administracion") == 0){
		sectorNumber = ADMIN;
	} else if(stricmp(sectorEmployee, "recepcion") == 0){
		sectorNumber = RECEPTION;
	} else if(stricmp(sectorEmployee, "oficinas") == 0){
		sectorNumber = OFFICE;
	} else {
		sectorNumber = 1;
		if(stricmp(sectorEmployee, "seguridad") == 0){
			sectorNumber = SECURITY;
		}
	}
	return sectorNumber;
}

int GetOccupiedId(Employee list[], int len){
	int index;
	int countRetries;
	int id;
	index = -1;
	countRetries = 0;
	while(index == -1){
		GetIntNoVerification(">>> Error, se ingresó un ID invalido: ", &id);
		countRetries++;
		if(countRetries == 6){
			printEmployees(list, len);
			countRetries = 0;
		}
		index = findEmployeeById(list, len, id);
	}
	return index;
}

// CHART:
void TopPartChart(){
	printf(" _________________________________________________________________________________________\n");
	printf("| %-5s | %-20s | %-15s | %-15s | %-20s |\n", "ID", "Apellido", "Nombre", "Salario", "Sector");
	printf("|-------|----------------------|-----------------|-----------------|----------------------|\n");
}
void BottomPartChart(){
	printf("|_______|______________________|_________________|_________________|______________________|\n");
}

// INFORM Sub Menu:
void InformSubMenu(Employee list[], int len, int tam, int* mainMenuOption){
	char opcion[tam];
	int intOpcion;

	printf("_________________________________________\n"
		   "1| MOSTRAR empleados alfabeticamente. %4s\n"
		   "2| INFORMAR promedio de salarios. %8s\n"
		   "9| Main Menu. %28s\n"
		   "0| Salir. %32s\n"
		   "_|_______________________________________|\n", "|", "|", "|", "|");

	GetOption(opcion, tam, &intOpcion);
	while(intOpcion < 0 || (intOpcion > 2 && intOpcion != 9)){
		printf(">>> Error. Ingrese un numero valido.\n");
		GetOption(opcion, tam, &intOpcion);
	}
	printf("\n");

	switch (intOpcion){
		case 1:
			if(sortEmployees(list, len, 0) == -1){
				printf(">>> Ocurrio un error inesperado.\n");
			}
			printEmployees(list, len);
		break;

		case 2:
			if(AverageSalaries(list, len) == -1){
				printf(">>> Ocurrio un error inesperado.\n");
			}
		break;

		case 9:
			printf(">>> Menu PRINCIPAL.\n");
		break;

		case 0:
			*mainMenuOption = 0;
		break;
	}
}

int sortEmployees(Employee list[], int len, int order){
	int retorno;
	char ordenamiento[51];
	retorno = -1;
	if(list != NULL && len > 0){
		retorno = 1;
		order = GetOrder(ordenamiento, 51);
		if(order == ATOZ){
			retorno = 0;
			SortAtoZ(list, len);
		} else {
			if(order == ZTOA){
				SortZtoA(list, len);
				retorno = 0;
			}
		}
	}
	return retorno;
}

int GetOrder(char order[], int len){
	int ordenamiento;
	int countRetries;
	countRetries = 0;
	ordenamiento = -1;
	printf(">>> (Ascendente / Descendente)\n");
	GetString(">>> Ingrese el ordenamiento: ", order, len);
	while(stricmp(order, "ascendente") != 0 && stricmp(order, "descendente") != 0){
		GetString(">>> Error, ingrese un ordenamiento valido: ", order, len);
		countRetries++;
		if(countRetries == 5){
			printf(">>> (Ascendente / Descendente)\n");
			countRetries = 0;
		}
	}
	if(stricmp(order, "ascendente") == 0){
		ordenamiento = ATOZ;
	} else {
		if(stricmp(order, "descendente") == 0){
			ordenamiento = ZTOA;
		}
	}
	return ordenamiento;
}

void SortAtoZ(Employee list[], int len){
	Employee temp;
	int i;
	int j;

	for(i = 0; i < len - 1; i++){
		for(j = i + 1; j < len; j++){
			if(stricmp(list[i].lastName, list[j].lastName) == 1){
				temp = list[j];
				list[j] = list[i];
				list[i] = temp;
			}
		}
	}

	for(i = 0; i < len - 1; i++){
		for(j = i + 1; j < len; j++){
			if(stricmp(list[i].lastName, list[j].lastName) == 0){
				if(list[i].sector > list[j].sector){
					temp = list[j];
					list[j] = list[i];
					list[i] = temp;
				}
			}
		}
	}
	printf(">>> Se ordeno de forma ascendente.\n");
}

void SortZtoA(Employee list[], int len){
	Employee temp;
	int i;
	int j;

	for(i = 0; i < len - 1; i++){
		for(j = i + 1; j < len; j++){
			if(stricmp(list[i].lastName, list[j].lastName) == -1){
				temp = list[j];
				list[j] = list[i];
				list[i] = temp;
			}
		}
	}

	for(i = 0; i < len - 1; i++){
		for(j = i + 1; j < len; j++){
			if(stricmp(list[i].lastName, list[j].lastName) == 0){
				if(list[i].sector < list[j].sector){
					temp = list[j];
					list[j] = list[i];
					list[i] = temp;
				}
			}
		}
	}
	printf(">>> Se ordeno de forma descendente.\n");
}

void SortById(Employee list[], int len){
	Employee temp;
	int i;
	int j;
	for(i = 0; i < len - 1; i++){
		for(j = i + 1; j < len; j++){
			if(list[i].id > list[j].id){
				temp = list[j];
				list[j] = list[i];
				list[i] = temp;
			}
		}
	}
}

int AverageSalaries(Employee list[], int len){
	int retorno;
	float acumSalaries;
	int countEmployees;
	float averageSalary;
	int countAverageSalaryEmployee;
	countAverageSalaryEmployee = 0;
	countEmployees = 0;
	acumSalaries = 0;
	retorno = -1;
	if(list != NULL && len > 0){
		retorno = 0;
		for(int i = 0; i < len; i++){
			if(list[i].isEmpty == CARGADO){
				countEmployees++;
				acumSalaries += list[i].salary;
			}
		}
		averageSalary = acumSalaries / countEmployees;
		for(int i = 0; i < len; i++){
			if(list[i].isEmpty == CARGADO){
				if(list[i].salary > averageSalary){
					countAverageSalaryEmployee++;
				}
			}
		}
	}
	if(retorno == 0){
		printf(">>> Empleados totales: %d\n"
			   ">>> Suma de todos los salarios: %.2f\n"
			   ">>> Salario promedio: %.2f\n"
			   ">>> Empleados que lo superan: %d\n", countEmployees, acumSalaries, averageSalary,countAverageSalaryEmployee);
	}
	return retorno;
}
