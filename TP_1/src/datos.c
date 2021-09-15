/*
 *
 *   UTN - Programacion - Trabajo practico numero 1.
 *
 * 					  Ian Iwanczuk
 * 						47018375
 *
 */

#include "datos.h"
#include <math.h>

float PedirNumero(int* flag, char X){
	float numero;
	printf("%c = ", X);
	scanf("%f", &numero);
	numero = floor(100*numero)/100;
	*flag = 1;
	return numero;
}

void MostrarResultadoFlag(int flag, float valor, char mensajeT[], char mensajeF[], char mensajeX[]){
	if(flag == 1){
		printf("%s%.2f", mensajeT, valor);
	} else if(flag == 0){
		printf("%s", mensajeF);
	} else {
		printf("%s", mensajeX);
	}
	printf("\n");
}

void MostrarResultadoSinFlag(float valor, char mensaje[]){
	printf("%s%.2f\n", mensaje, valor);
}
