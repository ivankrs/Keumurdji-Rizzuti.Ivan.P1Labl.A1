/*
 * funciones.h
 *
 *  Created on: 11 may. 2022
 *      Author: ivank
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>




/**
 *\brief -Crea lineas '='.
 */
void lineas(void);
/**
 * \brief -Muestra por pantalla un menu de opciones, y permite el ingreso de un caracter char, opcion.
 * \return devuelve el numero int ingresado, opcion.
 */
char menu(char* msj);

int ingresarInt(char* msj, char* msjError, int rangoBajo, int rangoAlto);
int validarRangoEntero(int valor, int inferior, int superior);
/**
 * \brief -Valida que el caracter que ingrese sea una letra y la convierte en minuscula.
 * \param letra -Caracter a validar y convierte a minuscula.
 * \return -Devuelve letra en minuscula.
 */
char validarLetraMinus(char letra);
/**
 * \brief -Una funcion usada para confirmar la salida del programa, validando si quiere realmente salir o no.
 * \param p -El puntero a char, donde se guarda el caracter ingresado por el usuario.
 */
void confirmarSalida(char* p);


#endif /* FUNCIONES_H_ */
