/*
 *
 *   UTN - Programacion - Trabajo practico numero 1.
 *
 * 					  Ian Iwanczuk
 * 						47018375
 *
 */

#ifndef DATOS_H_
#define DATOS_H_
#include <stdio.h>

/// @brief Pide un numero mostrando un mensaje.
///
/// @param inf - Flag para determinar que se ingreso algo.
/// @param char - Solo para mostrar que valor se ingresa
/// (Si es 'A' o 'B').
/// @return float - Asigna el valor a la variable en el main.
float PedirNumero(int*, char);

/// @brief Muestra un numero dependiendo del falor del flag.
///
/// @param int - Flag generico hecho para que pueda valer 1,
/// 0, u otro numero (3 opciones).
/// @param float - Valor a mostrar.
/// @param char mensajeT - Mensaje si el flag es "verdadero".
/// @param char mensajeF - Mensaje si el flag es "falso".
/// @param char mensajeX - Mensaje si el flag no es ni "falso"
/// ni "verdadero" (La tercera opcion).
void MostrarResultadoFlag(int flag, float valor, char mensajeT[], char mensajeF[], char mensajeX[]);


/// @brief Utilizado para mostrar valores.
///
/// @param float - Valor a ser mostrado.
/// @param char - Mensaje con el que se va a mostrar el valor.
void MostrarResultadoSinFlag(float valor, char mensaje[]);


#endif /* DATOS_H_ */
