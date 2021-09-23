/*
 *
 *   UTN - Programacion - Trabajo practico numero 1.
 *
 * 					  Ian Iwanczuk
 * 						47018375
 *
 */

#ifndef NUMEROS_H_
#define NUMEROS_H_
#include <stdio.h>


/// @brief Suma los dos numeros que recibe.
///
/// @param float - Primer numero.
/// @param float - Segundo numero.
/// @return float - La sumatoria de los dos numeros.
float SumarNumeros(float, float);

/// @brief Resta los dos numeros que recibe.
///
/// @param float - Primer numero ingresado.
/// @param float - Lo que le restamos al primer numero.
/// @return float - El primer numero menos el segundo.
float RestarNumeros(float, float);


/// @brief Recibe dos numeros y los divide utilizando un flag
/// por si el divisor es 0.
///
/// @param float - Primer numero (Dividendo).
/// @param float - Segundo numero (Divisor).
/// @param int - Flag para determinar si se dividio por 0.
/// @return float - Devuelve el resultado de la division, o
/// un mensaje si el divisor es 0.
float DividirNumeros(float, float, int*);


/// @brief Multiplica los dos numeros ingresados.
///
/// @param float - Primer numero.
/// @param float - Segundo numero.
/// @return float - Resultado de la multiplicacion.
float MultiplicarNumeros(float, float);


/// @brief Determina el factorial de un numero y utiliza
/// un flag.
///
/// @param float - Numero a calcular su factorial.
/// @param int - Flag para: Determinar si el numero es
/// negativo o 0.
/// @return float - Devuelve el factorial del numero ingresado,
/// o un mensaje si el nuemro es 0 o negativo.
int FactorialConFlag(float, int*);

/// @brief Funcion que sera utilizada para determinar si el
/// numero es decimal o entero.
///
/// @param float - Numero a determinar si es decimal o entero
/// @return int - Devuelve un 0 si entero y 1 si decimal.
int VerificarDecimal(float);

#endif /* NUMEROS_H_ */
