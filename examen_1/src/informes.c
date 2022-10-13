#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "recurso.h"
#include "evento.h"
#include "utn.h"
#include "informes.h"
#include "tipo.h"


void menu(recurso arrayRecurso[], tipo arrayTipo[], evento arrayEvento[], int limiteRecurso, int limiteTipo, int limiteEvento) {
int opcion;

if(arrayRecurso != NULL && arrayEvento != NULL && arrayTipo != NULL && limiteRecurso > 0 && limiteEvento > 0 && limiteTipo > 0){


	do {
		if (!utn_getNumero(&opcion,
						"\n\n1.Mostrar recursos de un tipo seleccionado"
						"\n2.Mostrar todos los eventos efectuados en una fecha seleccionada"
						"\n3.Informar importe total de los eventos realizados para un recurso seleccionado"
						"\n4.Informar importe total de todos los eventos de un tipo en una fecha seleccionada\n\n",
						"\nError opcion invalida", 1, 4, 100000)) {
			switch (opcion) {
			case 1:
				if (filtrarPorTipo(arrayRecurso, arrayTipo, limiteRecurso,limiteTipo) == 0) {
					printf("\nSalio bien");
				} else {
					printf("\nEse ID no esta cargado");
				}
				break;
			case 2:
				if (filtrarPorFecha(arrayEvento, limiteEvento) == 0) {
					printf("\nEl filtrado salio bien");
				} else {
					printf("\nEsa fecha no esta cargada");
				}
				break;
			case 3:
				if (calcularImporteTotal(arrayEvento, arrayTipo, arrayRecurso, limiteEvento, limiteTipo, limiteRecurso) == 0) {
					printf("\nEl importe total salio bien");
				} else {
					printf("\nAlgo salio mal");
				}
				break;
			case 4:
				if (importeTotalPorFechayTipo(arrayEvento, arrayRecurso, arrayTipo, limiteEvento, limiteTipo, limiteRecurso)== 0) {
					printf("\nEl importe total por fecha y tipo salio bien");
				} else {
					printf("\nEl importe total por fecha y tipo salio mal");
				}
				break;
				}
			}


		} while (opcion != 5);
	}
}

/**
 * \brief Pide un tipo para verificar que este cargado para imprimir los recursos con ese ID
 * \param arrayRecurso Array de recursos
 * \param arrayTipo Array de tipos
 * \param limiteRecurso Limite del array de recurso
 * \param limiteTipo Limite del array de tipos
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */

int filtrarPorTipo(recurso arrayRecurso[], tipo arrayTipo[], int limiteRecurso,int limiteTipo) {
	int i;
	int idIngresadoPorUsuario;
	int retorno = -1;

	if(arrayRecurso != NULL && arrayTipo != NULL && limiteRecurso > 0 && limiteTipo > 0){



	if (utn_getNumero(&idIngresadoPorUsuario,"\nIngrese un tipo: 1000\n 1001\n 1002\n 1003\n", "error", 1000, 1003, 10000) == 0) {

		for (i = 0; i < limiteRecurso; i++) {
			if (arrayRecurso[i].tipoId == idIngresadoPorUsuario && arrayRecurso[i].isEmpty == 1) {
				retorno = 0;
				informe_imprimir(arrayRecurso[i], arrayTipo, limiteTipo);

				}
			}
		}
	}
	return retorno;
}


/**
 * \brief Imprime un recurso de un tipo filtrado
 * \param unRecurso Array de recursos
 * \param arrayTipo Array de tipos
 * \param limiteTipo Limite del array de tipos
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int informe_imprimir(recurso unRecurso, tipo arrayTipos[], int limiteTipos) {
	int retorno = -1;
	int i;
	if (unRecurso.isEmpty == 1 && arrayTipos != NULL && limiteTipos > 0) {
		for (i = 0; i < limiteTipos; i++) {
			if (unRecurso.tipoId == arrayTipos[i].idTipo) {
				retorno = 0;
				printf("\n ID:%d   Descripcion:%s   Precio:%.2f   tipoId:%s  id: %d\n",
						unRecurso.idRecurso, unRecurso.descripcion,
						unRecurso.precioPorHora, arrayTipos[i].descripcion,
						arrayTipos[i].idTipo);
			}
		}
	}
	return retorno;
}

/**
 * \brief Pide una fecha y para verificar que este cargado para imprimir los eventos cargados en esa fecha
 * \param arrayEvento Array de eventos
 * \param limiteEvento Limite del array de evento
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */

int filtrarPorFecha(evento arrayEvento[], int limiteEvento) {
	int retorno = -1;
	int i;
	fecha unaFecha;

	if(arrayEvento != NULL && limiteEvento > 0){

	fechas_imprimir(arrayEvento, limiteEvento);

	if (utn_getNumero(&unaFecha.anio, "\nIngrese un anio\n", "Error", 2000, 2022,100000) == 0
			&& utn_getNumero(&unaFecha.mes, "\nIngrese un mes\n", "Error", 1, 12,100000) == 0
			&& utn_getNumero(&unaFecha.dia, "\nIngrese un dia\n", "Error", 1, 31,100000) == 0){
		for (i = 0; i < limiteEvento; i++) {
			if (unaFecha.anio == arrayEvento[i].unaFecha.anio
					&& unaFecha.mes == arrayEvento[i].unaFecha.mes
					&& unaFecha.dia == arrayEvento[i].unaFecha.dia
					&& arrayEvento[i].isEmpty == 1) {
				retorno = 0;
				printf("\n ID:%d   Localidad:%s   Cantidad:%d   Anio:%d  Mes:%d  Dia:%d\n",
						arrayEvento[i].idEvento, arrayEvento[i].localidad,
						arrayEvento[i].cantidad, arrayEvento[i].unaFecha.anio,
						arrayEvento[i].unaFecha.mes,
						arrayEvento[i].unaFecha.dia);
				}
			}
		}
	}
	return retorno;
}


/**
 * \brief recorre las fechas cargadas y las imprime
 * \param arrayEvento array de eventos
 * \param limiteEvento Limite del array de evento
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int fechas_imprimir(evento arrayEvento[], int limiteEVento) {
	int retorno = -1;
	int i;
	if (arrayEvento != NULL && limiteEVento > 0) {
		retorno = 0;
		for (i = 0; i < limiteEVento; i++) {
			if (arrayEvento[i].isEmpty == 1) {

				printf("\n -%d/%d/%d\n", arrayEvento[i].unaFecha.anio,arrayEvento[i].unaFecha.mes, arrayEvento[i].unaFecha.dia);
			}
		}
	}
	return retorno;
}


/**
 * \brief Pide un ID y para verificar que este cargado y acumula los precios por hora de ese ID
 * \param arrayEvento array de eventos
 * \param arrayRecurso Array de recursos
 * \param arrayTipo Array de tipos
 * \param limiteEvento Limite del array de eventos
 * \param limiteRecurso Limite del array de recurso
 * \param limiteTipo Limite del array de tipos
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int calcularImporteTotal(evento arrayEvento[], tipo arrayTipo[], recurso arrayRecurso[], int limiteEvento, int limiteTipo,int limiteRecurso) {
	int total;
	int i;
	int acumulador = 0;
	int id;
	int retorno = -1;
	if(arrayEvento != NULL && arrayRecurso != NULL && arrayTipo != NULL && limiteEvento > 0 && limiteRecurso > 0 && limiteTipo > 0){



	evento_imprimirArray(arrayEvento, limiteEvento);

	utn_getNumero(&id, "\nIngrese un ID de tipo 1000/1001/1002/1003", "error", 1000, 1003, 100000);

	for (i = 0; i < limiteRecurso; i++) {
		if (id == arrayRecurso[i].tipoId && arrayRecurso[i].isEmpty == 1) {
			acumulador += arrayRecurso[i].precioPorHora;
			retorno = 0;
			}

		}
	total = acumulador;
	printf("\nEl total acumulado para ese ID es:%d\n", total);
	}
	return retorno;
}


/**
 * \brief Pide un ID y una fecha para verificar que este cargado y acumula los precios por hora de ese ID y para esa fecha
 * \param arrayEvento array de eventos
 * \param arrayRecurso Array de recursos
 * \param arrayTipo Array de tipos
 * \param limiteEvento Limite del array de eventos
 * \param limiteRecurso Limite del array de recurso
 * \param limiteTipo Limite del array de tipos
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int importeTotalPorFechayTipo(evento arrayEvento[], recurso arrayRecurso[], tipo arrayTipo[], int limiteEvento, int limiteTipo, int limiteRecurso) {
	int i;
	int j;
	int tipo;
	fecha unaFecha;
	int acumulador = 0;
	int total;
	int retorno = -1;

	if(arrayEvento != NULL && arrayRecurso != NULL && arrayTipo != NULL && limiteEvento > 0 && limiteRecurso > 0 && limiteTipo > 0){



	mostrarTipos(arrayTipo, limiteTipo);

	if (utn_getNumero(&tipo, "\nIngrese un ID tipo  1000/1004", "Error", 1000, 1004, 100000) == 0) {
		fechas_imprimir(arrayEvento, limiteEvento);

		if (utn_getNumero(&unaFecha.anio, "\nIngrese un anio", "Error", 1900, 2022, 100000) == 0
				&& utn_getNumero(&unaFecha.mes, "\nIngrese un mes", "Error", 1,12, 100000) == 0
				&& utn_getNumero(&unaFecha.dia, "\nIngrese un dia", "Error", 1, 31, 100000) == 0){

			for (i = 0; i < limiteRecurso; i++) {
				for (j = 0; j < limiteEvento; j++) {

					if (tipo == arrayRecurso[i].tipoId
						&& arrayRecurso[i].idRecurso == arrayEvento[j].recursoId
						&& unaFecha.anio == arrayEvento[j].unaFecha.anio
						&& unaFecha.mes == arrayEvento[j].unaFecha.mes
						&& unaFecha.dia == arrayEvento[j].unaFecha.dia) {

						acumulador += arrayRecurso[i].precioPorHora;
						retorno = 0;
						}
					}
				}
			}
			total = acumulador;
			printf("\nEl total es: %d", total);
		}

	}

	return retorno;
}
