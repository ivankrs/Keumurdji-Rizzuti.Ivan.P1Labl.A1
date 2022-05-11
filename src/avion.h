/*
 * avion.h
 *
 *  Created on: 11 may. 2022
 *      Author: ivank
 */

#ifndef AVION_H_
#define AVION_H_
#include "tipo.h"
#include "aerolinea.h"

typedef struct{

int id;//comienza de 100
int idAerolinea;
int idTipo;
int capacidad;//entre 10 y 300

}eAvion;

#endif /* AVION_H_ */


int altaAvion(int id, eAvion avion[], int tamAv, eAerolinea aerolineas[],int tamAero, eTipo tipos[], int tamT);
int modificarAvion(eAvion avion[], int tamAv, eAerolinea aerolineas[],int tamAero, eTipo tipos[], int tamT);
int bajaAvion(eAvion avion[], int tamAv);
int listarAvion(eAvion aviones[], int tam);
