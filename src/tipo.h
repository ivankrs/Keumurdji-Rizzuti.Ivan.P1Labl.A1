/*
 * sector.h
 *
 *  Created on: 11 may. 2022
 *      Author: ivank
 */

#ifndef SECTOR_H_INCLUDED
#define SECTOR_H_INCLUDED

typedef struct{

int id; //comieza en 5000
char descripcion[20];

}eTipo;



#endif // SECTOR_H_INCLUDED

int listarTipos(eTipo tipos[], int tam);

