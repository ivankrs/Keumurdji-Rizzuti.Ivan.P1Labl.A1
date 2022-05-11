/*
 * aerolineas.c
 *
 *  Created on: 11 may. 2022
 *      Author: ivank
 */


#include "aerolinea.h"
#include "avion.h"
#include "tipo.h"
#include "funciones.h"

int listarAerolineas(eAerolinea aerolineas[], int tam){

	int kay = 0;

		if(aerolineas != NULL && tam > 0){
		 // system("cls");
			printf("   *** Lista de Aerolineas  ***\n");
			printf("  Id    Descripcion\n");
			printf("-----------------------\n");
			for(int i=0; i < tam; i++){
				printf(" %4d    %10s\n", aerolineas[i].id, aerolineas[i].descripcion);
			}
			printf("\n\n");
			kay = 1;
		}
	 return kay;
}
