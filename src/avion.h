/*
 * avion.h
 *
 *  Created on: 11 may. 2022
 *      Author: ivank
 */

#ifndef AVION_H_
#define AVION_H_
#include "aerolinea.h"
#include "tipo.h"
#include "piloto.h"
#include "funciones.h"


typedef struct{

int id;//comienza de 100
int idAerolinea;
int idTipo;
int idPiloto;
int capacidad;//entre 10 y 300


}eAvion;

#endif /* AVION_H_ */

void inicializarIdAvion(eAvion avion[], int tam);
int buscarIdAvion(eAvion avion[], int tam);
int altaAvion(int id, eAvion avion[], int tamAv, eAerolinea aerolineas[],int tamAero, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP);
int modificarAvion(eAvion avion[], int tamAv, eAerolinea aerolineas[],int tamAero, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP);
int bajaAvion(eAvion avion[], int tamAv, eAerolinea aerolineas[],int tamAero, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP, int* flagAlta);
int ordenarAviones(eAvion avion[], int tamAv, eAerolinea aerolineas[],int tamAero, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP);
int listarAvion(eAvion aviones[], int tamAv, eAerolinea aerolineas[], int tamAero, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP);
int listarAvionDeUnaAerolinea(eAvion aviones[], int tamAv, eAerolinea aerolineas[], int tamAero, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP);
int listarAvionDeUnTipo(eAvion aviones[], int tamAv, eAerolinea aerolineas[], int tamAero, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP);
int promedioJet(eAvion aviones[], int tamAv, eAerolinea aerolineas[], int tamAero, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP);
int listarAvionPorAerolineas(eAvion aviones[], int tamAv, eAerolinea aerolineas[], int tamAero, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP);
int listarAerolineaMasPasajeros(eAvion aviones[], int tamAv, eAerolinea aerolineas[], int tamAero);
