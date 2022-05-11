/*
 ============================================================================
 Name        : Examen.c
 Author      : Keumurdji Rizzuti Ivan
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "funciones.h"
#include "aerolinea.h"
#include "avion.h"
#include "tipo.h"
#include "destino.h"
#include "fecha.h"
#include "vuelo.h"

#define TAM 4
#define TAN 5



int main(void) {


	eAerolinea aerolineas[TAN]=
	{
			{1000, "Lan"},
			{1001, "Iberia"},
			{1002, "Norwegian"},
			{1003, "American"},
			{1004, "Austral"}
	};
	eTipo tipos[TAM]=
	{
			{5000, "Jet"},
			{5001, "Helice"},
			{5002, "Planeador"},
			{5003, "Carga"}
	};
	/*eDestino destinos[TAM]=
	{
			{20000, "Calafate", 22250},
			{20001, "Miami", 103000},
			{20002, "Madrid", 84400},
			{20003, "Amsterdam", 95600}
	};*/

	eAvion aviones[2];

	int contadorAviones=0;
	char salir='x';


	setbuf(stdout,NULL);

	do{
		switch(menu("\n   *** Menu de Opciones ***\n\n"
				"A. Alta Avion\n"
				"B. Modificar Avion\n"
				"C. Baja Avion\n"
				"D. Listar Aviones\n"
				"E. Listar Aerolineas\n"
				"F. Listar Tipos\n"
				"G. Listar Destinos\n"
				"H. Alta Vuelo\n"
				"I. Listar Vuelo\n"
				"S. Salir\n")){
		case 'a':

			altaAvion(contadorAviones, aviones, 2, aerolineas, TAN, tipos, TAM);
			contadorAviones++;
			break;

		case 'b':
			if(contadorAviones<0){
				modificarAvion(aviones, 2, aerolineas, TAN, tipos, TAM);
			}
			else{
				printf("\n¡Debe haber dado de alta para entrar a esta opcion!\n");
			}
			break;
		case 'c':
			if(contadorAviones<0){

			}
		case 's':
			salir='s';
		}
	}while(salir!='s');



	return EXIT_SUCCESS;
}
