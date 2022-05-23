/*
 * fecha.h
 *
 *  Created on: 11 may. 2022
 *      Author: ivank
 */

#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

#endif // FECHA_H_INCLUDED


int validarFecha(eFecha fecha);
