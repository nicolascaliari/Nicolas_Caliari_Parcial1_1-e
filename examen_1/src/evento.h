/*
 * evento.h
 *
 *  Created on: 3 oct. 2022
 *      Author: nicolas
 */

#ifndef EVENTO_H_
#define EVENTO_H_
#define LOCALIDAD 30
#include "recurso.h"

typedef struct {
	int dia;
	int mes;
	int anio;
}fecha;


typedef struct {
	int idEvento;
	char localidad[LOCALIDAD];
	float fecha;
	int cantidad;
	int recursoId;
	fecha unaFecha;
	int isEmpty;
}evento;


void evento_inicializarArray(evento arrayEvento[],int limiteEvento);
int evento_imprimir(evento unEvento);
int evento_imprimirArray(evento arrayEvento[], int limiteEvento);
int evento_altaArray(evento arrayEvento[],recurso arrayRecurso[] ,tipo arrayTipo[],int limiteEvento, int limiteRecurso, int limiteTipo);
int buscarIdRecurso(recurso arrayRecurso[], int limiteRecurso, int valorBuscado);
int evento_buscarEspacioLibre(evento arrayEvento[], int limiteEvento);

#endif /* EVENTO_H_ */
