/*
 * piloto.h
 *
 *  Created on: 23 may. 2022
 *      Author: ivank
 */

#ifndef PILOTO_H_
#define PILOTO_H_

typedef struct{

int id;
char nombre[51];
char sexo;


}ePiloto;

#endif /* PILOTO_H_ */

void inicializarIdPiloto(ePiloto pilotos[], int tam);
int buscarIdPiloto(ePiloto pilotos[], int tam);
