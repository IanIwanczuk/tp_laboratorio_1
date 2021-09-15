/*
 *
 *   UTN - Programacion - Trabajo practico numero 1.
 *
 * 					  Ian Iwanczuk
 * 						47018375
 *
 */

#include "numeros.h"

float SumarNumeros(float numUno, float numDos){
	float resultado;

	resultado = numUno + numDos;

	return resultado;
}

float RestarNumeros(float numUno, float numDos){
	float resultado;

	resultado = numUno - numDos;

	return resultado;
}

float DividirNumeros(float numUno, float numDos, int* flagDivision){
	float resultado;

	if(numDos == 0){
		*flagDivision = 0;
	} else {
		resultado = numUno / numDos;
	}

	return resultado;
}

float MultiplicarNumeros(float numUno, float numDos){
	float resultado;

	resultado = numUno * numDos;

	return resultado;
}

int FactorialConFlag(float numero, int* flagFactorial){
	int flagFact;
	int resultado;

	if(numero > 12){
		flagFact = 0;
	} else {
		if(numero == 0){
			flagFact = 1;
			resultado = 1;
		} else {
			if(numero > 0 && VerificarDecimal(numero) == 0){
				flagFact = 1;
				resultado = numero * FactorialConFlag(numero - 1, &flagFact);
			} else {
				flagFact = 2;
			}
		}
	}

	*flagFactorial = flagFact;

	return resultado;
}

int VerificarDecimal(float numero){
	int retorno;
	if(numero - (int)numero > 0)
	{
		// Decimal.
		retorno = 1;
	} else {
		// Entero.
		retorno = 0;
	}
	return retorno;
}


