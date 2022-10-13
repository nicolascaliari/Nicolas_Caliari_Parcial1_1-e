#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "evento.h"
#include "recurso.h"
#include "tipo.h"

static int idEvento(void);
static int idEvento(void) {
	static int Gen_idIncremental = 20000;
	return Gen_idIncremental++;
}

/**
 * \brief Inicia el campo isEmpty del array de tipo evento en 0
 * \param arrayEvento Array de tipo evento
 * \param limiteEvento Limite del array
 * \return void
 */
void evento_inicializarArray(evento arrayEvento[], int limiteEvento) {
	int i;
	if (arrayEvento != NULL && limiteEvento > 0) {
		for (i = 0; i < limiteEvento; i++) {
			arrayEvento[i].isEmpty = 0;
		}
	}
}

/**
 * \brief Imprime los datos de un evento
 * \param unRecurso variable de tipo evento
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int evento_imprimir(evento unEVento) {
	int retorno = -1;
	if (unEVento.isEmpty == 1) {
		retorno = 0;
		printf(	"\n ID evento:%d  Localidad:%s  Cantidad:%d  fecha:%d,%d,%d  idRecurso: %d\n",
				unEVento.idEvento, unEVento.localidad, unEVento.cantidad,
				unEVento.unaFecha.dia, unEVento.unaFecha.mes,
				unEVento.unaFecha.anio, unEVento.recursoId);
	}
	return retorno;
}

/**
 * \brief Imprime el array de recurso
 * \param arrayEvento Array de tipo evento
 * \param limiteRecurso Limite del array de evento
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int evento_imprimirArray(evento arrayEvento[], int limiteEvento) {
	int respuesta = -1;
	int i;
	if (arrayEvento != NULL && limiteEvento > 0) {
		respuesta = 0;
		for (i = 0; i < limiteEvento; i++) {
			evento_imprimir(arrayEvento[i]);
		}
	}
	return respuesta;
}

/**
 * \brief Carga los datos y da de alta un evento en una posicion del array
 * \param arrayEvento Array de tipo evento
 * \param arrayRecurso Array de tipo recurso
 * \param arrayTipo Array de tipo tipo
 * \param limiteEVento Limite del array de evento
 * \param limiteRecurso Limite del array de recurso
 * \param limiteTipo Limite del array de tipo
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */

int evento_altaArray(evento arrayEvento[], recurso arrayRecurso[], tipo arrayTipo[], int limiteEvento, int limiteRecurso, int limiteTipo) {
	int retorno = -1;
	evento auxiliar;
	int opcion;
	int indice;

	if(arrayEvento != NULL && arrayRecurso != NULL && arrayTipo != NULL && limiteEvento > 0 && limiteRecurso > 0 && limiteTipo > 0){

	indice = evento_buscarEspacioLibre(arrayEvento, limiteEvento);

	if (indice != -1) {

		recurso_imprimirArray(arrayRecurso, arrayTipo, limiteRecurso,limiteTipo);
		if (utn_getNumero(&opcion,
				"\nElija el ID del recurso que quiera ingresar 1-20\n", "error", 1,
				20, 10000) == 0){

			if (buscarIdRecurso(arrayRecurso, limiteRecurso, opcion) == 1) {
				auxiliar.recursoId = opcion;

				if (utn_getDescripcion(auxiliar.localidad, LOCALIDAD,
						"\nIngrese la localidad?\n", "\nERROR\n", 2) == 0
						&& utn_getNumero(&auxiliar.cantidad,
								"\nIngrese la cantidad de personas?\n",
								"\nERROR\n", 1, 10000, 2) == 0
						&& utn_getNumero(&auxiliar.unaFecha.dia,
								"Ingrese el dia\n", "Error\n", 1, 31, 2) == 0
						&& utn_getNumero(&auxiliar.unaFecha.mes,
								"Ingrese el mes\n", "Error\n", 1, 12, 2) == 0
						&& utn_getNumero(&auxiliar.unaFecha.anio,
								"Ingrese el anio\n", "Error\n", 100, 300000, 2)== 0) {

					auxiliar.idEvento = idEvento();

					auxiliar.isEmpty = 1;

					arrayEvento[indice] = auxiliar;

					retorno = 0;

				}
			} else {
				printf("\nEste ID no existe, debe ingresar uno que exista");
				}
			}

		}
	}
	return retorno;
}


/** \brief Busca un ID que sea igual al valorBuscado y devuelve la posicion en que se encuentra
 * \param arrayRecurso Array de tipo recurso
 * \param limiteRecurso Limite del array de recurso
 * \param valorBuscado variable de tipo INT
 * \return Retorna la posicion donde encontro la coincidencia, si no encuentra retorna -1
 *
 */

int buscarIdRecurso(recurso arrayRecurso[], int limiteRecurso, int valorBuscado) {
	int respuesta = -1;
	int i;
	if (arrayRecurso != NULL && limiteRecurso > 0 && valorBuscado > 0) {
		respuesta = 0;
		for (i = 0; i < limiteRecurso - 1; i++) {
			if (arrayRecurso[i].idRecurso == valorBuscado) {
				respuesta = 1;
				break;
			}
		}
	}
	return respuesta;
}

/**
 * \brief Buscar primer posicion vacia
 * \param arrayEvento Array de evento
 * \param limiteEvento Limite del array de evento
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int evento_buscarEspacioLibre(evento arrayEvento[], int limiteEvento) {
	int respuesta = -1;
	int i;
	if (arrayEvento != NULL && limiteEvento > 0) {
		respuesta = 0;
		for (i = 0; i < limiteEvento; i++) {
			if (arrayEvento[i].isEmpty == 0) {
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}
