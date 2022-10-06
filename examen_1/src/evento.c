#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "recurso.h"
#include "utn.h"
#include "evento.h"


/**
 * \brief Imprime los datos de un cliente
 * \param pElemento Puntero al producto que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int evento_imprimir(evento pElemento) {
	int retorno = -1;
	if (pElemento.isEmpty == 0) {
		retorno = 0;
		printf("\n ID:%d \n Localidad:%s \n Cantidad:%d \n  fecha:%d,%d,%d",
				pElemento.idEvento, pElemento.localidad, pElemento.cantidad,
				pElemento.unaFecha.dia, pElemento.unaFecha.mes,
				pElemento.unaFecha.anio);
	}
	return retorno;
}

/**
 * \brief Imprime el array de clientes
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int evento_imprimirArray(evento array[], int limite) {
	int respuesta = -1;
	int i;
	if (array != NULL && limite > 0) {
		respuesta = 0;
		for (i = 0; i < limite; i++) {
			evento_imprimir(array[i]);
		}
	}
	return respuesta;
}

/**
 * \brief Inicializa el array
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int evento_inicializarArray(evento array[], int limite) {
	int respuesta = -1;
	int i;
	if (array != NULL && limite > 0) {
		respuesta = 0;
		for (i = 0; i < limite; i++) {
			array[i].isEmpty = 1;
		}
	}
	return respuesta;
}

/**
 * \brief Da de alta una pantalla en una posicion del array
 * \param array Array de pantallas a ser actualizado
 * \param limite Limite del array de pantallas
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado a la pantalla
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int evento_altaArray(evento array[], int limite, int indice, int *id) {
	int respuesta = -1;
	evento bufferEvento;

	if (array != NULL
			&& limite > 0&& indice < limite && indice >= 0 && id != NULL) {
		if (utn_getDescripcion(bufferEvento.localidad, LOCALIDAD,
				"\nIngrese la localidad?\n", "\nERROR\n", 2) == 0
				&& utn_getNumero(&bufferEvento.cantidad,
						"\nIngrese la cantidad de personas?\n", "\nERROR\n", 1,
						10000, 2) == 0
				&& utn_getNumero(&bufferEvento.unaFecha.dia, "Ingrese el dia\n",
						"Error\n", 1, 31, 2) == 0
				&& utn_getNumero(&bufferEvento.unaFecha.mes, "Ingrese el mes\n",
						"Error\n", 1, 12, 2) == 0
				&& utn_getNumero(&bufferEvento.unaFecha.anio, "Ingrese el anio\n",
						"Error\n", 100, 300000, 2) == 0) {
			respuesta = 0;
			bufferEvento.idEvento = *id;
			bufferEvento.isEmpty = 0;
			array[indice] = bufferEvento;
			(*id)++;
		}

	}
	return respuesta;
}

/**
 * \brief Actualiza los datos de un cliente en una posicion del array
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int evento_modificarArray(evento array[], int limite, int indice) {
	int respuesta = -1;
	evento bufferProduct;

	if (array != NULL && limite > 0 && indice < limite && indice >= 0
			&& array[indice].isEmpty == 0) {
		if (utn_getDescripcion(bufferProduct.localidad, LOCALIDAD,
				"\nINgrese la localidad?\n", "\nERROR\n", 2) == 0
				&& utn_getNumero(&bufferProduct.cantidad,
						"\nINgrese la cantidad?\n", "\nERROR\n", 0, 10000, 2)
						== 0) {
			respuesta = 0;
			bufferProduct.idEvento = array[indice].idEvento;
//			bufferProduct.tipoId = tipos();
			bufferProduct.isEmpty = 0;
			array[indice] = bufferProduct;
		}
	}
	return respuesta;
}

/**
 * \brief Actualiza una posicion del array
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int evento_bajaArray(evento array[], int limite, int indice) {
	int respuesta = -1;
	if (array != NULL && limite > 0 && indice < limite && indice >= 0
			&& array[indice].isEmpty == 0) {
		array[indice].isEmpty = 1;
		respuesta = 0;
	}
	return respuesta;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
 * \param array cliente Array de cliente
 * \param limite int Tamaño del array
 * \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
 * \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
 *
 */
int evento_buscarId(evento array[], int limite, int valorBuscado) {
	int respuesta = -1;
	int i;
	if (array != NULL && limite > 0 && valorBuscado >= 0) {
		respuesta = 0;
		for (i = 0; i < limite; i++) {
			if (array[i].idEvento == valorBuscado) {
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

/**
 * \brief Buscar primer posicion vacia
 * \param array Array de clientes
 * \param limite Limite del array de clientes
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int evento_getEmptyIndex(evento array[], int limite) {
	int respuesta = -1;
	int i;
	if (array != NULL && limite > 0) {
		respuesta = 0;
		for (i = 0; i < limite; i++) {
			if (array[i].isEmpty == 1) {
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}
