/*
 * vuelo.c
 *
 *  Created on: 12 may. 2022
 *      Author: ivank
 */


#include "vuelo.h"
#include "funciones.h"



int altaVuelo(int id, eVuelo vuelo[], eAvion aviones[], int tamAv, eAerolinea aerolineas[], int tamAero, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP, eDestino destinos[], int tamD){
	int kay=0;
	eFecha fecha;


	if(id>=0 && vuelo!=NULL && aviones!=NULL && tamAv>0  && aerolineas!=NULL && tamAero>0 && tipos!=NULL && tamT>0 && pilotos!=NULL && tamP>0 && destinos!=NULL && tamD>0){

		vuelo[id].id= id;

		listarAvion(aviones, tamAv, aerolineas, tamAero, tipos, tamT, pilotos, tamP);
		vuelo[id].idAvion = ingresarInt("Ingrese el Id del Avion: ", "\n¡Error! El numero debe estar entre 100 y 104: ", 100, 104);

		printf("\n");
		listarDestinos(destinos, tamD);
		vuelo[id].idDestino=ingresarInt("Ingrese el Id del Destino: ", "\n¡Error! El numero debe estar entre 20000 y 20003: ", 20000, 20003);

		printf("\nIngrese Fecha de vuelo:  dd/ mm/ aaaa: ");
		scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
		while(validarFecha(fecha)!=1){
			printf("\n¡Error! Ingrese una Fecha valida:  dd/ mm/ aaaa: ");
			scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
		}
		vuelo[id].fecha=fecha;

		id+=1;
		kay=1;
	}


	return kay;
}
int listarVuelo(eVuelo vuelo[], int tamV){
	int kay=0;
	if(vuelo!=NULL && tamV>0){

		printf("\n       *** Lista de Vuelos  ***\n");
		printf("Id Vuelo   Id Avion   Id Destino      Fecha\n");
		printf("----------------------------------------------\n");
		for(int i=0; i < tamV; i++){
			if( validarRangoEntero(vuelo[i].id, 0, 3) &&
				validarRangoEntero(vuelo[i].idAvion, 100, 104) &&
				validarRangoEntero(vuelo[i].idDestino, 20000, 20003)){
				printf("   %2d        %3d         %5d      %02d/%02d/%4d \n", vuelo[i].id + 10, vuelo[i].idAvion,vuelo[i].idDestino,vuelo[i].fecha.dia,vuelo[i].fecha.mes,vuelo[i].fecha.anio);
			}
		}
		printf("\n\n");
		kay=1;
	}


	return kay;
}
