/*
 * destino.c
 *
 *  Created on: 12 may. 2022
 *      Author: ivank
 */


#include "destino.h"
#include "funciones.h"


int listarDestinos(eDestino destinos[], int tam){
	int kay = 0;

		if(destinos != NULL && tam > 0){
		 // system("cls");
			printf("\n     *** Lista de Destinos  ***\n");
			printf("  Id    Descripcion         precio\n");
			printf("------------------------------------\n");
			for(int i=0; i < tam; i++){
				if( validarRangoEntero(destinos[i].id, 20000, 20003)&&
					validarRangoEntero(destinos[i].precio, 1, 100000000)){
					printf("%5d    %10s      $%10.2f\n", destinos[i].id, destinos[i].descripcion, destinos[i].precio);
				}
				else{
					printf("\n¡No hay Tipos registrados!\n");
				}
			}
			printf("\n\n");
			kay = 1;
		}
	 return kay;
}
