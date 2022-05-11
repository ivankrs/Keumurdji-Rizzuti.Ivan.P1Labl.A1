/*
 * aerolinea.h
 *
 *  Created on: 11 may. 2022
 *      Author: ivank
 */

#ifndef AEROLINEA_H_
#define AEROLINEA_H_

typedef struct{

int id;// comieza en 1000
char descripcion[20];

}eAerolinea;

#endif /* AEROLINEA_H_ */

int listarAerolineas(eAerolinea aerolineas[], int tam);
