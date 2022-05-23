/*
 * piloto.c
 *
 *  Created on: 23 may. 2022
 *      Author: ivank
 */

#include "piloto.h"
#include "funciones.h"

void inicializarIdPiloto(ePiloto pilotos[], int tam){

	if(pilotos!=NULL && tam>0){

		for(int i=0; i<tam;i++){

			pilotos[i].id = -1;
		}
	}
}

int buscarIdPiloto(ePiloto pilotos[], int tam){
	int indiceId;

	if(pilotos!=NULL && tam>0){

		for(int i=0; i<tam;i++){

			if(pilotos[i].id<0){
				indiceId=i;
				break;
			}
			else{
				indiceId=-1;
			}
		}
	}
	return indiceId;
}
