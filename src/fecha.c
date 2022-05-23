/*
 * fecha.c
 *
 *  Created on: 11 may. 2022
 *      Author: ivank
 */


#include "fecha.h"
#include "funciones.h"

int validarFecha(eFecha fecha){
	int kay=0;

	if(validarRangoEntero(fecha.dia, 1, 31)){
		if(validarRangoEntero(fecha.mes, 1, 12)){
			if(fecha.mes ==4 || fecha.mes == 6 || fecha.mes == 8 || fecha.mes == 10){
				if(validarRangoEntero(fecha.dia, 1, 30)){
					kay=1;
				}
			}
			else{
				if(fecha.mes ==2){
					if(validarRangoEntero(fecha.dia, 1, 28)){
						kay=1;
					}
				}
				else{
					if(validarRangoEntero(fecha.dia, 1, 31)){
						kay=1;
					}
				}
			}
		}
		if(validarRangoEntero(fecha.anio, 2020, 2024)){
			kay++;
		}
	}
	if(kay==2){
		kay=1;
	}
	else{
		kay=0;
	}
	return kay;
}



