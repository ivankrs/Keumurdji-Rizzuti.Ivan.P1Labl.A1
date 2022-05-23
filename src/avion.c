/*
 * avion.c
 *
 *  Created on: 11 may. 2022
 *      Author: ivank
 */

#include "avion.h"


void inicializarIdAvion(eAvion avion[], int tam){

	if(avion!=NULL && tam>0){

		for(int i=0; i<tam;i++){

			avion[i].id = -1;
		}
	}
}

int buscarIdAvion(eAvion avion[], int tam){
	int indiceId;

	if(avion!=NULL && tam>0){

		for(int i=0; i<tam;i++){

			if(avion[i].id<0){
				indiceId=i;
				break;
			}
			else{
				indiceId=-1;
			}
		}
	}
	return indiceId;
}


int altaAvion(int id, eAvion avion[], int tamAv, eAerolinea aerolineas[],int tamAero, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP){
	int kay=0;


	avion[id].id=id;
	if(avion!=NULL && tamAv>0 && aerolineas!=NULL && tamAero>0 && tipos!=NULL && tamT>0 && pilotos!=NULL && tamP>0){

		listarAerolineas(aerolineas, tamAero);
		avion[id].idAerolinea=ingresarInt("Ingrese el Id de Aerolineas: ", "\n¡Error! El numero debe estar entre 1000 y 1005: ", 1000, 1005);

		printf("\n");
		listarTipos(tipos, tamT);
		avion[id].idTipo=ingresarInt("Ingrese el Id de Tipos: ", "\n¡Error! El numero debe estar entre 5000 y 5004: ", 5000, 5004);
		if(( pilotos[id].id = buscarIdPiloto(pilotos, tamP) >= 0)){
			printf("\n >Informacio del Piloto: \n"
					"---------------------------\n");
			ingresarString(pilotos[id].nombre, "Ingrese el nombre del Pioloto: ", "\n¡Error! El nombre debe tener largo entre 1 y 50 letras", 1, 51);
			ingresarSexo(&pilotos[id].sexo, "Ingrese el sexo del Pioloto: ", "\n¡Error! El sexo debe estar entre 'M' y 'F': ");
			avion[id].idPiloto = pilotos[id].id;
		}
		avion[id].capacidad = ingresarInt("\nIngrese la cantidad de pasajeros: ", "\n¡Error! El numero debe estar entre 10 y 300: ", 10, 300);

		kay=1;
	}
	return kay;
}
int modificarAvion(eAvion avion[], int tamAv, eAerolinea aerolineas[],int tamAero, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP){
	int kay=0;
	int id;
	if(avion!=NULL && tamAv>0 && aerolineas!=NULL && tamAero>0 && tipos!=NULL && tamT>0 && pilotos!=NULL && tamP>0){
		listarAvion(avion, tamAv, aerolineas, tamAero, tipos, tamT, pilotos, tamP);

		id = ingresarInt("Ingrese el Id del Avion a modificar: ", "\n¡Error! El numero debe estar entre 100 y 102: ", 100, 104);
		id = id - 100;
		printf("\n\n");
		kay = altaAvion(id, avion, tamAv, aerolineas, tamAero, tipos, tamT, pilotos, tamP);

	}

	return kay;
}
int bajaAvion(eAvion avion[], int tamAv, eAerolinea aerolineas[],int tamAero, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP, int* flagAlta){
	int kay=0;
	int id;
	if(avion!=NULL && tamAv>0 && flagAlta!=NULL && aerolineas!=NULL && tamAero>0 && tipos!=NULL && tamT>0 && pilotos!=NULL && tamP>0){
		listarAvion(avion, tamAv, aerolineas, tamAero, tipos, tamT, pilotos, tamP);
		id = ingresarInt("Ingrese el Id del Avion a dar de baja: ", "\n¡Error! El numero debe estar entre 100 y 102: ", 100, 104);
		id = id - 100;
		avion[id].id = -1;
		pilotos[id].id = -1;

		for(int i=0; i<tamAv;i++){
			if(avion[id].id<0){
				*flagAlta=0;
			}
			else{
				*flagAlta=1;
				break;
			}
		}
		kay=1;
	}
	return kay;
}
int ordenarAviones(eAvion avion[], int tamAv, eAerolinea aerolineas[],int tamAero, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP){
	int kay = 0;

	if(avion!=NULL && tamAv>0 && aerolineas!=NULL && tamAero>0 && tipos!=NULL && tamT>0 && pilotos!=NULL && tamP>0){

		for(int i=0; i<tamAv-1 ;i++){

			for(int j=i+1; j<tamAv; j++){

				if(avion[j].idAerolinea < avion[i].idAerolinea){

					swapInt(&avion[i].id, &avion[j].id);
					swapInt(&avion[i].idAerolinea, &avion[j].idAerolinea);
					swapInt(&avion[i].idTipo, &avion[j].idTipo);
					swapInt(&avion[i].idPiloto, &avion[j].idPiloto);
					swapInt(&avion[i].capacidad, &avion[j].capacidad);

				}
				if(avion[j].idAerolinea == avion[i].idAerolinea && avion[j].capacidad > avion[i].capacidad){

					swapInt(&avion[i].id, &avion[j].id);
					swapInt(&avion[i].idAerolinea, &avion[j].idAerolinea);
					swapInt(&avion[i].idTipo, &avion[j].idTipo);
					swapInt(&avion[i].idPiloto, &avion[j].idPiloto);
					swapInt(&avion[i].capacidad, &avion[j].capacidad);
				}
			}
		}
		kay=1;
	}
	return kay;
}
int listarAvion(eAvion aviones[], int tamAv, eAerolinea aerolineas[], int tamAero, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP){

	int kay = 0;
	int idPiloto;
	if(aviones!=NULL && tamAv>0 && aerolineas!=NULL && tamAero>0 && tipos!=NULL && tamT>0 && pilotos!=NULL && tamP>0){
		ordenarAviones(aviones, tamAv, aerolineas, tamAero, tipos, tamT, pilotos, tamP);
		 // system("cls");
			printf("\n                *** Lista de Aviones  ***\n");
			printf(" Id Avion   Id Aerolineas   Id Tipo   Nombre Piloto   Capacidad\n");
			printf("----------------------------------------------------------------\n");
			for(int i=0; i < tamAv; i++){
				if( validarRangoEntero(aviones[i].id, 0, tamAv) &&
					validarRangoEntero(aviones[i].idAerolinea, 1000, 1005) &&
					validarRangoEntero(aviones[i].idTipo, 5000, 5004) &&
					validarRangoEntero(aviones[i].idPiloto, 0, tamAv) &&
					validarRangoEntero(aviones[i].capacidad, 10, 300)){
					idPiloto = aviones[i].idPiloto;
					printf("     %3d           %4d       %4d   %10s          %3d\n", aviones[i].id+100, aviones[i].idAerolinea, aviones[i].idTipo, pilotos[idPiloto].nombre, aviones[i].capacidad);

				}
			}
			printf("\n\n");
			kay = 1;
		}
	 return kay;
}
int listarAvionDeUnaAerolinea(eAvion aviones[], int tamAv, eAerolinea aerolineas[], int tamAero, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP){

	int kay = 0;
	int idPiloto;
	int idAero;
	if(aviones!=NULL && tamAv>0 && aerolineas!=NULL && tamAero>0 && tipos!=NULL && tamT>0 && pilotos!=NULL && tamP>0){

		listarAerolineas(aerolineas, tamAero);
		idAero=ingresarInt("Ingrese el Id de la Aerolinea: ", "\n¡Error! El numero debe estar entre 1000 y 1005: ", 1000, 1005);

		 // system("cls");
			printf("\n         *** Lista de Aviones de una Aerolinea ***\n");
			printf(" Id Avion   Id Aerolineas   Id Tipo   Nombre Piloto   Capacidad\n");
			printf("----------------------------------------------------------------\n");
			for(int i=0; i < tamAv; i++){
				if( validarRangoEntero(aviones[i].id, 0, tamAv) &&
					validarRangoEntero(aviones[i].idAerolinea, idAero, idAero) &&
					validarRangoEntero(aviones[i].idTipo, 5000, 5004) &&
					validarRangoEntero(aviones[i].idPiloto, 0, tamAv) &&
					validarRangoEntero(aviones[i].capacidad, 10, 300)){
					idPiloto = aviones[i].idPiloto;
					printf("     %3d           %4d       %4d   %10s          %3d\n", aviones[i].id+100, aviones[i].idAerolinea, aviones[i].idTipo, pilotos[idPiloto].nombre, aviones[i].capacidad);

				}
			}
			printf("\n\n");
			kay = 1;
		}
	 return kay;
}
int listarAvionDeUnTipo(eAvion aviones[], int tamAv, eAerolinea aerolineas[], int tamAero, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP){

	int kay = 0;
	int idPiloto;
	int idTipo;
	if(aviones!=NULL && tamAv>0 && aerolineas!=NULL && tamAero>0 && tipos!=NULL && tamT>0 && pilotos!=NULL && tamP>0){

		listarTipos(tipos, tamT);
		idTipo=ingresarInt("Ingrese el Id de Tipos: ", "\n¡Error! El numero debe estar entre 5000 y 5004: ", 5000, 5004);

		 // system("cls");
			printf("\n         *** Lista de Aviones de un Tipo ***\n");
			printf(" Id Avion   Id Aerolineas   Id Tipo   Nombre Piloto   Capacidad\n");
			printf("----------------------------------------------------------------\n");
			for(int i=0; i < tamAv; i++){
				if( validarRangoEntero(aviones[i].id, 0, tamAv) &&
					validarRangoEntero(aviones[i].idAerolinea, 1000, 1005) &&
					validarRangoEntero(aviones[i].idTipo, idTipo, idTipo) &&
					validarRangoEntero(aviones[i].idPiloto, 0, tamAv) &&
					validarRangoEntero(aviones[i].capacidad, 10, 300)){
					idPiloto = aviones[i].idPiloto;
					printf("     %3d           %4d       %4d   %10s          %3d\n", aviones[i].id+100, aviones[i].idAerolinea, aviones[i].idTipo, pilotos[idPiloto].nombre, aviones[i].capacidad);

				}
			}
			printf("\n\n");
			kay = 1;
		}
	 return kay;
}
int promedioJet(eAvion aviones[], int tamAv, eAerolinea aerolineas[], int tamAero, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP){
	int kay = 0;
	int cantJet = 0;
	int cantOtro = 0;
	float promedio;
	int idTipo;
	if(aviones!=NULL && tamAv>0 && aerolineas!=NULL && tamAero>0 && tipos!=NULL && tamT>0 && pilotos!=NULL && tamP>0){

		listarTipos(tipos, tamT);
		idTipo=ingresarInt("Ingrese el Id de Tipo distinto a Jet: ", "\n¡Error! El numero debe estar entre 5001 y 5004: ", 5001, 5004);
		for(int i=0; i<tamAv; i++){
			if(aviones[i].idTipo==5000){
				cantJet++;
			}
			if(aviones[i].idTipo==idTipo){
				cantOtro++;
			}
		}
		if(cantOtro>0){
			promedio = (float)(cantJet/cantOtro);
			printf("\n         *** Promedio de Jet sobre %s ***\n", tipos[idTipo-5000].descripcion);
			printf(" Total Jets  Total %s    Promedio\n",tipos[idTipo-5000].descripcion);
			printf("---------------------------------------\n");
			printf("     %02d          %02d            %4.2f\n", cantJet, cantOtro, promedio);

		}
		kay=1;
	}
	return kay;
}
int listarAvionPorAerolineas(eAvion aviones[], int tamAv, eAerolinea aerolineas[], int tamAero, eTipo tipos[], int tamT, ePiloto pilotos[], int tamP){

	int kay = 0;
	int idPiloto;
	if(aviones!=NULL && tamAv>0 && aerolineas!=NULL && tamAero>0 && tipos!=NULL && tamT>0 && pilotos!=NULL && tamP>0){



		 // system("cls");
			printf("\n         *** Lista de Aviones Lan ***\n");
			printf(" Id Avion   Id Aerolineas   Id Tipo   Nombre Piloto   Capacidad\n");
			printf("----------------------------------------------------------------\n");
			for(int i=0; i < tamAv; i++){
				if( validarRangoEntero(aviones[i].id, 0, tamAv) &&
					validarRangoEntero(aviones[i].idAerolinea, 1000, 1000) &&
					validarRangoEntero(aviones[i].idTipo, 5000, 5004) &&
					validarRangoEntero(aviones[i].idPiloto, 0, tamAv) &&
					validarRangoEntero(aviones[i].capacidad, 10, 300)){
					idPiloto = aviones[i].idPiloto;
					printf("     %3d           %4d       %4d   %10s          %3d\n", aviones[i].id+100, aviones[i].idAerolinea, aviones[i].idTipo, pilotos[idPiloto].nombre, aviones[i].capacidad);
					kay++;
				}
			}
			if(kay==0){
				printf("       ¡No hubo ingresos en esta Aerolinea!");
			}

			printf("\n");

			kay=0;
			printf("\n         *** Lista de Aviones Iberia ***\n");
			printf(" Id Avion   Id Aerolineas   Id Tipo   Nombre Piloto   Capacidad\n");
			printf("----------------------------------------------------------------\n");
			for(int i=0; i < tamAv; i++){
				if( validarRangoEntero(aviones[i].id, 0, tamAv) &&
					validarRangoEntero(aviones[i].idAerolinea, 1001, 1001) &&
					validarRangoEntero(aviones[i].idTipo, 5000, 5004) &&
					validarRangoEntero(aviones[i].idPiloto, 0, tamAv) &&
					validarRangoEntero(aviones[i].capacidad, 10, 300)){
					idPiloto = aviones[i].idPiloto;
					printf("     %3d           %4d       %4d   %10s          %3d\n", aviones[i].id+100, aviones[i].idAerolinea, aviones[i].idTipo, pilotos[idPiloto].nombre, aviones[i].capacidad);
					kay++;
				}
			}
			if(kay==0){
				printf("       ¡No hubo ingresos en esta Aerolinea!");
			}

			printf("\n");

			kay=0;
			printf("\n         *** Lista de Aviones Norwegian ***\n");
			printf(" Id Avion   Id Aerolineas   Id Tipo   Nombre Piloto   Capacidad\n");
			printf("----------------------------------------------------------------\n");
			for(int i=0; i < tamAv; i++){
				if( validarRangoEntero(aviones[i].id, 0, tamAv) &&
					validarRangoEntero(aviones[i].idAerolinea, 1002, 1002) &&
					validarRangoEntero(aviones[i].idTipo, 5000, 5004) &&
					validarRangoEntero(aviones[i].idPiloto, 0, tamAv) &&
					validarRangoEntero(aviones[i].capacidad, 10, 300)){
					idPiloto = aviones[i].idPiloto;
					printf("     %3d           %4d       %4d   %10s          %3d\n", aviones[i].id+100, aviones[i].idAerolinea, aviones[i].idTipo, pilotos[idPiloto].nombre, aviones[i].capacidad);
					kay++;
				}
			}
			if(kay==0){
				printf("       ¡No hubo ingresos en esta Aerolinea!");
			}
			printf("\n");

			kay=0;
			printf("\n         *** Lista de Aviones American ***\n");
			printf(" Id Avion   Id Aerolineas   Id Tipo   Nombre Piloto   Capacidad\n");
			printf("----------------------------------------------------------------\n");
			for(int i=0; i < tamAv; i++){
				if( validarRangoEntero(aviones[i].id, 0, tamAv) &&
					validarRangoEntero(aviones[i].idAerolinea, 1003, 1003) &&
					validarRangoEntero(aviones[i].idTipo, 5000, 5004) &&
					validarRangoEntero(aviones[i].idPiloto, 0, tamAv) &&
					validarRangoEntero(aviones[i].capacidad, 10, 300)){
					idPiloto = aviones[i].idPiloto;
					printf("     %3d           %4d       %4d   %10s          %3d\n", aviones[i].id+100, aviones[i].idAerolinea, aviones[i].idTipo, pilotos[idPiloto].nombre, aviones[i].capacidad);
					kay++;
				}
			}
			if(kay==0){
				printf("       ¡No hubo ingresos en esta Aerolinea!");
			}
			printf("\n");

			kay=0;
			printf("\n         *** Lista de Aviones Austral ***\n");
			printf(" Id Avion   Id Aerolineas   Id Tipo   Nombre Piloto   Capacidad\n");
			printf("----------------------------------------------------------------\n");
			for(int i=0; i < tamAv; i++){
				if( validarRangoEntero(aviones[i].id, 0, tamAv) &&
					validarRangoEntero(aviones[i].idAerolinea, 1004, 1004) &&
					validarRangoEntero(aviones[i].idTipo, 5000, 5004) &&
					validarRangoEntero(aviones[i].idPiloto, 0, tamAv) &&
					validarRangoEntero(aviones[i].capacidad, 10, 300)){
					idPiloto = aviones[i].idPiloto;
					printf("     %3d           %4d       %4d   %10s          %3d\n", aviones[i].id+100, aviones[i].idAerolinea, aviones[i].idTipo, pilotos[idPiloto].nombre, aviones[i].capacidad);
					kay++;
				}
			}
			if(kay==0){
				printf("       ¡No hubo ingresos en esta Aerolinea!");
			}
			printf("\n");
			kay = 1;
		}
	 return kay;
}
int listarAerolineaMasPasajeros(eAvion aviones[], int tamAv, eAerolinea aerolineas[], int tamAero){

	int kay = 0;
	int idAero;
	int cant;
	int cantU;
	int cantD;
	int cantT;
	int cantC;
	int cantTotal;

	if(aviones!=NULL && tamAv>0 && aerolineas!=NULL && tamAero>0){

		for(int i=0; i<tamAv; i++){
			if(aviones[i].idAerolinea==1000){
				cant += aviones[i].capacidad;
			}
			if(aviones[i].idAerolinea==1001){
				cantU += aviones[i].capacidad;
			}
			if(aviones[i].idAerolinea==1002){
				cantD += aviones[i].capacidad;
			}
			if(aviones[i].idAerolinea==1003){
				cantT += aviones[i].capacidad;
			}
			if(aviones[i].idAerolinea==1004){
				cantC += aviones[i].capacidad;
			}
		}
		if(cant>(cantU && cantD && cantT && cantC)){
			idAero = 1000;
			cantTotal = cant;
		}
		else if(cantU> (cant && cantD && cantT && cantC)){
			idAero = 1001;
			cantTotal = cantU;
		}
		else if(cantD> (cant && cantU && cantT && cantC)){
			idAero = 1002;
			cantTotal = cantD;
		}
		else if(cantT> (cant && cantD && cantU && cantC)){
			idAero = 1003;
			cantTotal = cantT;
		}
		else if(cantC> (cant && cantD && cantU && cantT)){
			idAero = 1004;
			cantTotal = cantC;
		}

			printf("\n         *** Informe Aerolinea con mas Pasajeros ***\n");
			printf(" Id Aerolineas   Descripcion   Capacidad Total\n");
			printf("----------------------------------------------------------------\n");

				if( validarRangoEntero(aviones[i].id, 0, tamAv) &&
					validarRangoEntero(aviones[i].idAerolinea, idAero, idAero) &&
					validarRangoEntero(aviones[i].capacidad, 10, 300)){

					printf(" %4d        %10s     %5d\n", aviones[i].idAerolinea, aerolineas[idAero].descripcion, cantTotal);

				}

			printf("\n\n");
			kay = 1;
		}
	 return kay;
}
