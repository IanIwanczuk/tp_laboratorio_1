#include "functions.h"

void GetOption(char opcion[], int tam, int* intOpcion){
	GetString("Ingrese una opcion: ", opcion, tam);
	*intOpcion = atoi(opcion);
	if(CheckIfNumber(opcion) == 1){
		*intOpcion = -1;
		if(CheckIfInt(opcion) == 0){
			*intOpcion = atoi(opcion);
		}
	} else {
		*intOpcion = -1;
	}
}

int GetString(char mensaje[], char cadena[], int tam){
	printf("%s", mensaje);
	fflush(stdin);
	fgets(cadena, tam, stdin);
	SwapEnterFgets(cadena);
	return 1;
}

int SwapEnterFgets(char verifyArray[]){
	int retorno;
	int largo;
	retorno = 0;
	largo = strlen(verifyArray);
	if(verifyArray[largo-1] == '\n'){
		verifyArray[largo-1] = '\0';
		retorno = 1;
	}
	return retorno;
}



int CountPeriodInString(char countArray[], int tam){
	int contPuntos = 0;
	int i;
	for(i = 0; i < tam; i++){
		if(countArray[i] == '.'){
			contPuntos++;
		}
	}
	return contPuntos;
}

int CountMinusInString(char countArray[], int tam){
	int contNegativos = 0;
	int i;
	for(i = 1; i < tam; i++){
		if(countArray[i] == '-'){
			contNegativos++;
		}
	}
	return contNegativos;
}

int SortName(char name[]){
	int retorno;
	retorno = 0;
	strlwr(name);
	name[0] = toupper(name[0]);
	retorno = 1;
	return retorno;
}


int GetInt(char mensaje[], char errorMsg[], int* number){
	char numero[51];
	int flagError;
	int retorno;
	retorno = 0;
	flagError = 1;
	GetString(mensaje, numero, 51);
	*number = atoi(numero);
	if(CheckIfNumber(numero) == 1 && CheckIfInt(numero) == 0){
		flagError = 0;
	}
	while(flagError == 1){
		GetString(errorMsg, numero, 51);
		*number = atoi(numero);
		if(CheckIfNumber(numero) == 1 && CheckIfInt(numero) == 0){
			flagError = 0;
			retorno = 1;
		}
	}
	*number = atoi(numero);
	return retorno;
}

int GetIntWithRange(char mensaje[], char errorMsg[], int* number, int min, int max){
	char numero[51];
	int flagError;
	int retorno;
	retorno = -1;
	flagError = 1;
	GetString(mensaje, numero, 51);
	*number = atoi(numero);
	if(CheckIfNumber(numero) == 1 && CheckIfInt(numero) == 0){
		flagError = 0;
		if(*number < min || *number > max){
			flagError = 1;
		}
	}
	while(flagError == 1){
		GetString(errorMsg, numero, 51);
		*number = atoi(numero);
		if(CheckIfNumber(numero) == 1 && CheckIfInt(numero) == 0){
			flagError = 1;
			if(*number >= min && *number <= max){
				flagError = 0;
			}
		}
	}
	*number = atoi(numero);
	return retorno;
}

int GetFloat(char mensaje[], char errorMsg[], float* number){
	char numero[51];
	int flagError;
	int retorno;
	retorno = 0;
	flagError = 1;
	GetString(mensaje, numero, 51);
	*number = atof(numero);
	if(CheckIfNumber(numero) == 1){
		flagError = 0;
	}
	while(flagError == 1){
		GetString(errorMsg, numero, 51);
		*number = atof(numero);
		if(CheckIfNumber(numero) == 1){
			flagError = 0;
			retorno = 1;
		}
	}
	*number = atof(numero);
	return retorno;
}

int GetFloatWithRange(char mensaje[], char errorMsg[], float* number, int min, int max){
	char numero[51];
	int flagError;
	int retorno;
	retorno = -1;
	flagError = 1;
	GetString(mensaje, numero, 51);
	*number = atof(numero);
	if(CheckIfNumber(numero) == 1){
		flagError = 0;
		if(*number < min || *number > max){
			flagError = 1;
		}
	}
	while(flagError == 1){
		printf("Error! Valor invalido. ");
		GetString(mensaje, numero, 51);
		*number = atof(numero);
		if(CheckIfNumber(numero) == 1){
			flagError = 1;
			if(*number >= min && *number <= max){
				flagError = 0;
			}
		}
	}
	*number = atof(numero);
	return retorno;
}

int GetIntNoVerification(char mensaje[], int* number){
	char numero[51];
	int retorno;
	retorno = 0;
	GetString(mensaje, numero, 51);
	*number = atoi(numero);
	return retorno;
}

int CheckIfInt(char number[]){
	int retorno;
	int largo;
	retorno = 0;
	largo = strlen(number);
	for(int i = 0; i < largo; i++){
		if(number[i] == '.'){
			retorno = -1;
			break;
		}
	}
	return retorno;
}

int CheckIfNumber(char verifyArray[]){
	int retorno;
	int contPuntos;
	int contMenos;
	retorno = 1;

	contPuntos = CountPeriodInString(verifyArray, strlen(verifyArray));
	contMenos = CountMinusInString(verifyArray, strlen(verifyArray));

	for(int i = 0; verifyArray[i] != '\0'; i++){
		if(verifyArray[i] < '-' || (verifyArray[i] > '.' && verifyArray[i] < '0') || verifyArray[i] > '9'){
			retorno = 0;
			break;
		} else {
			if(contMenos > 0 || contPuntos > 1 || (verifyArray[0] == '-' && verifyArray[1] == '.') || verifyArray[0] == '.' || (strlen(verifyArray) == 1 && verifyArray[0] == '-')){                     //
				retorno = 0;
				break;
			}
		}
	}
	if(strlen(verifyArray) == 0){
		retorno = 0;
	}
	return retorno;
}

int CheckIfName(char name[]){
	int retorno;
	int largo;
	retorno = 1;
	largo = strlen(name);
	for(int i = 0; i < largo; i++){
		if(isalpha(name[i]) == 0){
			retorno = 0;
			break;
		}
	}
	return retorno;
}




