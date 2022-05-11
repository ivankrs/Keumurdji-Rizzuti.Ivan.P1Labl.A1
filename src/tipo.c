/*
 * tipo.c
 *
 *  Created on: 11 may. 2022
 *      Author: ivank
 */

#include "tipo.h"
#include "avion.h"
#include "aerolinea.h"
#include "funciones.h"

int listarTipos(eTipo tipos[], int tam){

	int kay = 0;

		if(tipos != NULL && tam > 0){
		 // system("cls");
			printf("\n\n   *** Lista de Tipos  ***\n");
			printf("  Id    Descripcion\n");
			printf("-----------------------\n");
			for(int i=0; i < tam; i++){
				printf(" %4d    %10s\n", tipos[i].id, tipos[i].descripcion);
			}
			printf("\n\n");
			kay = 1;
		}
	 return kay;
}
