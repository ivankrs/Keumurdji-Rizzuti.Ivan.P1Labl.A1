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
#define TANS 4



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
	eDestino destinos[TAM]=
	{
			{20000, "Calafate", 22250},
			{20001, "Miami", 103000},
			{20002, "Madrid", 84400},
			{20003, "Amsterdam", 95600}
	};

	eAvion aviones[TANS];/*=
	{
			{1, 1002, 5000, 0, 10},
			{0, 1001, 5001, 1, 300},
			{3, 1000, 5003, 2, 30},
			{4, 1000, 5003, 3, 35}
	};*/

	ePiloto pilotos[TANS];/*=
	{
			{0,"ivan",'M',},
			{1,"ivana",'F',},
			{2,"juan",'M',},
			{3,"juana",'F',}
	};*/

	eVuelo vuelos[TANS];/*=
	{
			{1, 102, 20003, 10,02,2021},
			{0, 101, 20001, 30,10,2021},
			{3, 100, 20002, 21,05,2021},
			{2, 103, 20000, 25,11,2021}
	};*/
	int idAvion;
	int idVuelo=0;
	int flagAlta= 0;
	char salir='x';


	setbuf(stdout,NULL);
	inicializarIdAvion(aviones, TANS);
	inicializarIdPiloto(pilotos, TANS);


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
				"j. Listar Aviones de una Aerolinea\n"
				"k. Listar Aviones de un Tipo\n"
				"l. Promedio de Aviones Jet sobre...\n"
				"m. Listar Aviones por Aerolineas\n"
				"n. Informar Aerolinea transporta mas pasajeros\n"
				"o. Mostrar Aerolinea con menos Aviones\n"
				"X. Salir\n")){

		case 'a':
			idAvion=buscarIdAvion(aviones, TANS);
			if(idAvion>=0){
				if(altaAvion(idAvion, aviones, TANS, aerolineas, TAN, tipos, TAM, pilotos, TANS)){
					printf("\n¡Se ha dado de alta con exito!\n");
				}
				flagAlta=1;
			}
			else{
				printf("\n¡No hay espacio para saguir ingresando aviones!\n");
			}

			break;

		case 'b':

			if(flagAlta){
				if(modificarAvion(aviones, TANS, aerolineas, TAN, tipos, TAM, pilotos, TANS)){
					printf("\n¡Se ha modificado con exito!\n");
				}
			}
			else{
				printf("\n¡Debe haber dado de alta para entrar a esta opcion!\n");
			}
			break;

		case 'c':
			if(flagAlta){
				if(bajaAvion(aviones, TANS, aerolineas, TAN, tipos, TAM, pilotos, TANS, &flagAlta)){
					printf("\n¡Se dio de baja con exito!\n");
				}
			}
			else{
				printf("\n¡Debe haber dado de alta para entrar a esta opcion!\n");
			}
			break;

		case 'd':
			if(flagAlta){

				listarAvion(aviones, TANS, aerolineas, TAN, tipos, TAM, pilotos, TANS);

			}
			else{
				printf("\n¡Debe haber dado de alta para entrar a esta opcion!\n");
			}
			break;

		case 'e':
			if(flagAlta){
				listarAerolineas(aerolineas, TAN);
			}
			else{
				printf("\n¡Debe haber dado de alta para entrar a esta opcion!\n");
			}
			break;

		case 'f':
			if(flagAlta){
				listarTipos(tipos, TAM);
			}
			else{
				printf("\n¡Debe haber dado de alta para entrar a esta opcion!\n");
			}
			break;

		case 'g':
			if(flagAlta){
				listarDestinos(destinos, TAM);
			}
			else{
				printf("\n¡Debe haber dado de alta para entrar a esta opcion!\n");
			}
			break;

		case 'h':
			if(flagAlta){

				if(idVuelo == 0){

					if(altaVuelo(idVuelo, vuelos, aviones, TANS, aerolineas, TAN, tipos, TAM, pilotos, TANS, destinos, TAM)){
						idVuelo=1;
						printf("\n¡Se ha dado de alta con exito!\n");
					}
				}
				else if(idVuelo < TANS){
					if(altaVuelo(idVuelo, vuelos, aviones, TANS, aerolineas, TAN, tipos, TAM, pilotos, TANS, destinos, TAM)){
						idVuelo++;
						printf("\n¡Se ha dado de alta con exito!\n");
					}
				}
				else{
						printf("\n¡No hay espacio para seguir ingresando vuelos!\n");
				}
			}
			else{
				printf("\n¡Debe haber dado de alta para entrar a esta opcion!\n");
			}
			break;

		case 'i':
			if(flagAlta && idVuelo > 0){

				listarVuelo(vuelos, TANS);
			}
			else{
				printf("\n¡Debe haber dado de alta para entrar a esta opcion!\n");
			}
			break;
		case 'j':
			if(flagAlta){
				if( !(listarAvionDeUnaAerolinea(aviones, TANS, aerolineas, TAN, tipos, TAM, pilotos, TANS))){
					printf("\n¡Ocurrio un problema!\n");
				}
			}
			else{
				printf("\n¡Debe haber dado de alta para entrar a esta opcion!\n");
			}
			break;

		case 'k':
			if(flagAlta){
				if( !(listarAvionDeUnTipo(aviones, TANS, aerolineas, TAN, tipos, TAM, pilotos, TANS))){
					printf("\n¡Ocurrio un problema!\n");
				}
			}
			else{
				printf("\n¡Debe haber dado de alta para entrar a esta opcion!\n");
			}
			break;

		case 'l':
			if(flagAlta){
				if(!(promedioJet(aviones, TANS, aerolineas, TAN, tipos, TAM, pilotos, TANS))){
					printf("\n¡Ocurrio un problema!\n");
				}
			}
			else{
				printf("\n¡Debe haber dado de alta para entrar a esta opcion!\n");
			}
			break;

		case 'm':
			if(flagAlta){
				if( !(listarAvionPorAerolineas(aviones, TANS, aerolineas, TAN, tipos, TAM, pilotos, TANS))){
					printf("\n¡Ocurrio un problema!\n");
				}
			}
			else{
				printf("\n¡Debe haber dado de alta para entrar a esta opcion!\n");
			}
			break;

		case 'n':
			if(flagAlta){
				if( !(listarAerolineaMasPasajeros(aviones, TANS, aerolineas, TAN))){
					printf("\n¡Ocurrio un problema!\n");
				}
			}
			else{
				printf("\n¡Debe haber dado de alta para entrar a esta opcion!\n");
			}
			break;

		case 'o':
			if(flagAlta){
				if( !(listarAerolineaMenosAviones(aviones, TANS, aerolineas, TAN))){
					printf("\n¡Ocurrio un problema!\n");
				}
			}
			else{
				printf("\n¡Debe haber dado de alta para entrar a esta opcion!\n");
			}
			break;

		case 'x':
			confirmarSalida(&salir);
			break;
		default :
			printf("\n  X Opcion Invalida X\n");
			break;
		}
	}while(salir!='s');



	return EXIT_SUCCESS;
}
