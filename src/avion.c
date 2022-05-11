/*
 * avion.c
 *
 *  Created on: 11 may. 2022
 *      Author: ivank
 */

#include "avion.h"
#include "aerolinea.h"
#include "tipo.h"
#include "funciones.h"


int altaAvion(int id, eAvion avion[], int tamAv, eAerolinea aerolineas[],int tamAero, eTipo tipos[], int tamT){
	int kay=0;
	int idAerolineas[tamAero];
	int idTipo[tamT];


	if(aerolineas!=NULL && tipos!=NULL){
		listarAerolineas(aerolineas, tamAero);
		idAerolineas[id]=ingresarInt("Ingrese el Id de Aerolineas: ", "\n¡Error! El numero debe estar entre 1000 y 1005: ", 1000, 1005);

		listarTipos(tipos, tamT);
		idTipo[id]=ingresarInt("Ingrese el Id de Tipos: ", "\n¡Error! El numero debe estar entre 5000 y 5004: ", 5000, 5004);

		avion[id].capacidad = ingresarInt("Ingrese la cantidad de pasajeros: ", "\n¡Error! El numero debe estar entre 10 y 300: ", 10, 300);

		avion[id].id=id + 100;
		avion[id].idAerolinea=idAerolineas[id];
		avion[id].idTipo=idTipo[id];

		listarAvion(avion, tamAv);



	kay=1;
	}
	return kay;
}
int modificarAvion(eAvion avion[], int tamAv, eAerolinea aerolineas[],int tamAero, eTipo tipos[], int tamT){
	int kay=0;
	int id;

	listarAvion(avion, tamAv);

	id = ingresarInt("Ingrese el Id del Avion a modificar: ", "\n¡Error! El numero debe estar entre 100 y 102: ", 100, 102);

	altaAvion(id, avion, tamAv, aerolineas, tamAero, tipos, tamT);


	return kay;
}

int listarAvion(eAvion aviones[], int tam){

	int kay = 0;

		if(aviones != NULL && tam > 0){
		 // system("cls");
			printf("\n\n   *** Lista de Aviones  ***\n");
			printf("  Id Avion   Id Aerolineas   Id Tipo   Capacidad\n");
			printf("----------------------------------------------------\n");
			for(int i=0; i < tam; i++){
				if( validarRangoEntero(aviones[i].id, 100, tam +100) &&
					validarRangoEntero(aviones[i].idAerolinea, 1000, 1005) &&
					validarRangoEntero(aviones[i].idTipo, 5000, 5004) &&
					validarRangoEntero(aviones[i].capacidad, 10, 300)){

					printf("   %3d           %4d         %4d       %3d\n", aviones[i].id, aviones[i].idAerolinea, aviones[i].idTipo, aviones[i].capacidad);
				}
			}
			printf("\n\n");
			kay = 1;
		}
	 return kay;
}
