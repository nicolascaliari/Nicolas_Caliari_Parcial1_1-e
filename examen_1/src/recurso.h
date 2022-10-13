/*
 * recurso.h
 *
 *  Created on: 1 oct. 2022
 *      Author: nicolas
 */

#ifndef RECURSO_H_
#define RECURSO_H_
#define DESCRIPCION 1024

#include "tipo.h"



typedef struct {
	int idRecurso;
	char descripcion[DESCRIPCION];
	float precioPorHora;
	int tipoId;
	int isEmpty;
} recurso;

int recurso_bajaArray(recurso arrayRecurso[], tipo arrayTipo[], int limiteRecurso,int limiteTipo);

void recurso_inicializarArray(recurso arrayRecurso[], int limiteRecurso);

int recurso_imprimir(recurso unRecurso, tipo arrayTipo[], int limiteTipo);

int recurso_imprimirArray(recurso arrayRecurso[], tipo arrayTipo[], int limiteRecurso, int limiteTipo);

int recurso_altaArray(recurso arrayRecurso[], int limiteRecurso, tipo arrayTipo[], int limiteTipo);

int buscarEspacio(recurso arrayRecurso[], int limiteArray);

int recurso_modificarRecurso(recurso arrayRecurso[], tipo arrayTipo[], int limiteRecurso, int limiteTipo);

int recurso_buscarEspacioLibre(recurso arrayRecurso[], int limiteRecurso);

int recurso_buscarId(recurso arrayRecurso[], int limiteRecurso, int valorBuscado);

int recurso_ordenarPorIdDescripcion(recurso arrayRecurso[], int limiteRecurso);

int ordenarDescripcion(recurso arrayRecurso[], int limiteRecurso);


#endif /* RECURSO_H_ */
