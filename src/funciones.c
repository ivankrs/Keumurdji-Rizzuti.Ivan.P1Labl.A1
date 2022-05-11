/*
 * funciones.c
 *
 *  Created on: 11 may. 2022
 *      Author: ivank
 */


#include "funciones.h"

void lineas(void){
	int i;
	printf("\n");
	for(i=0;i<50;i++)
	{
		printf("~=");
	}
	printf("\n");
}
//MENU
char menu(char* msj){
    char opcion;


    //system("cls");
    lineas();
    printf("%s",msj);
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);

    while(!validarLetraMinus(opcion)){
    	printf("\n¡Ingrese opcion valida! (A-B-C-D-E-F-G-H-I o S): ");
    	fflush(stdin);
    	scanf("%c", &opcion);

    }
    lineas();
    printf("\n");

    //system("cls");

    return opcion;
}
char validarLetraMinus(char letra){

	if((letra >= 'a' && letra <='z') || (letra >= 'A' && letra <= 'Z')){

		letra= tolower(letra);
	}

	return letra;
}
int ingresarInt(char* msj, char* msjError, int rangoBajo, int rangoAlto){
	int numero;
	if(msj!=NULL && msjError!= NULL && rangoBajo < rangoAlto){
		printf("%s",msj);
		scanf("%d", &numero);

		while(validarRangoEntero(numero, rangoBajo, rangoAlto)!=1){
			printf("%s", msjError);
			scanf("%d", &numero);
		}
	}
	return numero;
}
int validarRangoEntero(int valor, int inferior, int superior){
    int esValido = 0;
    if(valor >= inferior && valor <= superior){
        esValido = 1;
    }
    return esValido;
}



void confirmarSalida(char* p){
    char confirma;

    while(confirma!= 's' && confirma!= 'n'){

		printf("\n¿Confirma salida?-('s'= si / 'n'= no): ");
		fflush(stdin);
		scanf("%c", &confirma);
		confirma=tolower(confirma);
    }
    *p = confirma;
}
