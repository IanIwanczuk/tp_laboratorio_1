/*
 *
 *   UTN - Programacion - Trabajo practico numero 1.
 *
 * 					  Ian Iwanczuk
 * 						47018375
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "numeros.h"
#include "datos.h"

int main() {
	setbuf(stdout, NULL);
	float numeroUno;
	int flagUno = 0;
	float numeroDos;
	int flagDos = 0;
	float sumaNumeros;
	float restaNumeros;
	float divisionNumeros;
	float multiplicacionNumeros;
	int factorialUno;
	int flagFactUno;
	int factorialDos;
	int flagFactDos;
	int flagDivision = 1;
	int flagOperaciones = 0;
	int opcion = 0;

	do {
		if(flagUno){
			printf("\n1. Ingresar 1er operando. (A = %.2f)\n", numeroUno);
		} else {
			printf("\n1. Ingresar 1er operando. (A = X)\n");
		}
		if(flagDos){
			printf("2. Ingresar 2do operando. (B = %.2f)\n", numeroDos);
		} else {
			printf("2. Ingresar 2do operando. (B = X)\n");
		}
		printf("3. Calcular todas las operaciones.\n");
		printf("4. Mostrar los resultados.\n");
		printf("5. Salir.\n");
		printf("Ingrese una opcion: ");
		scanf("%d", &opcion);
		printf("_________________________________________\n\n");

		switch(opcion){
			case 1:
				numeroUno = PedirNumero(&flagUno, 'A');
				printf("_________________________________________\n\n");
			break;

			case 2:
				numeroDos = PedirNumero(&flagDos, 'B');
				printf("_________________________________________\n\n");
			break;

			case 3:
				if(flagUno == 1 && flagDos == 1){
					flagOperaciones = 1;
					sumaNumeros = SumarNumeros(numeroUno, numeroDos);
					restaNumeros = RestarNumeros(numeroUno, numeroDos);
					divisionNumeros = DividirNumeros(numeroUno, numeroDos, &flagDivision);
					multiplicacionNumeros = MultiplicarNumeros(numeroUno, numeroDos);
					factorialUno = FactorialConFlag(numeroUno, &flagFactUno);
					factorialDos = FactorialConFlag(numeroDos, &flagFactDos);
					printf("Ya se realizaron las operaciones.\n");
				} else {
					printf("Faltan ingresar numeros.\n");
				}
				printf("_________________________________________\n\n");
			break;

			case 4:
				if(flagOperaciones){
					MostrarResultadoSinFlag(sumaNumeros, "(A+B) = ");
					MostrarResultadoSinFlag(restaNumeros, "(A-B) = ");
					MostrarResultadoFlag(flagDivision, divisionNumeros, "(A/B) = ", "No se puede dividir por 0. (B = 0)", "");
					MostrarResultadoSinFlag(multiplicacionNumeros, "(A*B) = ");
					MostrarResultadoFlag(flagFactUno, factorialUno, "(!A) = ", "!A es demasiado grande.", "A no tiene factorial.");
					MostrarResultadoFlag(flagFactDos, factorialDos, "(!B) = ", "!B es demasiado grande.", "B no tiene factorial.");
				} else {
					printf("Falta realizar las opreaciones.\n");
				}
				printf("_________________________________________\n\n");
			break;

		}

	} while(opcion != 5);

	return 0;
}
