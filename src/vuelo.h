/*
 * vuelo.h
 *
 *  Created on: 11 may. 2022
 *      Author: ivank
 */

#ifndef VUELO_H_
#define VUELO_H_
#include "funciones.h"
#include "fecha.h"
#include "destino.h"
#include "avion.h"
#include "piloto.h"

typedef struct{

int id;//autoincremental
int idAvion;//Validar existe
int idDestino;//Validar existe
eFecha fecha;

}eVuelo;

#endif /* VUELO_H_ */

int altaVuelo(int id, eVuelo vuelo[], eAvion aviones[], int tamAv, eAerolinea aerolineas[], int tamAero, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP, eDestino destinos[], int tamD);
int listarVuelo(eVuelo vuelo[], int tamV);
