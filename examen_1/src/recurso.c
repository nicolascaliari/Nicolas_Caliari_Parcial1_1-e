#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "recurso.h"
#include "utn.h"
#include "tipo.h"

/**
 *\brief: Otorga un ID autoincremental.
 *\param: ---
 *\return: retorna el id autoincrementado.
 **/
static int idRecurso(void);
static int idRecurso(void) {
	static int Gen_idIncremental = 1;
	return Gen_idIncremental++;
}

/**
 * \brief Inicia el campo isEmpty del array de tipo recurso en 0
 * \param arrayRecurso Array de tipo recurso
 * \param limiteRecurso Limite del array
 * \return void
 *
 */
void recurso_inicializarArray(recurso arrayRecurso[], int limiteRecurso) {
	int i;
	if (arrayRecurso != NULL && limiteRecurso > 0) {
		for (i = 0; i < limiteRecurso; i++) {
			arrayRecurso[i].isEmpty = 0;
		}
	}
}

/**
 * \brief Imprime los datos de un recurso
 * \param unRecurso variable de tipo recurso
 * \param arrayTipo de tipo tipo
 * \param limiteTipo Limite de tipo
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int recurso_imprimir(recurso unRecurso, tipo arrayTipo[], int limiteTipo) {
	int retorno = -1;
	int i;
	if (unRecurso.isEmpty == 1 && arrayTipo != NULL && limiteTipo > 0) {
		for (i = 0; i < limiteTipo; i++) {
			if (unRecurso.tipoId == arrayTipo[i].idTipo) {
				printf(
						"\n ID:%d   Descripcion:%s   Precio:%.2f   tipoId:%s  Id de tipo: %d\n",
						unRecurso.idRecurso, unRecurso.descripcion,
						unRecurso.precioPorHora, arrayTipo[i].descripcion,
						arrayTipo[i].idTipo);
			}
		}
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief Imprime el array de recurso
 * \param arrayRecurso Array de tipo recurso
 * \param arrayTipo Array de tipo tipo
 * \param limiteRecurso Limite del array de recurso
 * \param limiteTipo Limite del array de tipo
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int recurso_imprimirArray(recurso arrayRecurso[], tipo arrayTipo[], int limiteRecurso, int limiteTipo) {
	int respuesta = -1;
	int i;
	if (arrayRecurso != NULL && arrayTipo != NULL && limiteRecurso > 0
			&& limiteTipo > 0) {
		for (i = 0; i < limiteRecurso; i++) {
			recurso_imprimir(arrayRecurso[i], arrayTipo, limiteTipo);
		}
		respuesta = 0;
	}

	return respuesta;
}

/**
 * \brief Carga los datos y da de alta un recurso en una posicion del array
 * \param arrayRecurso Array de tipo recurso
 * \param arrayTipo Array de tipo tipo
 * \param limiteRecurso Limite del array de recurso
 * \param limiteTipo Limite del array de tipo
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int recurso_altaArray(recurso arrayRecurso[], int limiteRecurso, tipo arrayTipo[], int limiteTipo) {
	int retorno = -1;
	recurso auxiliar;
	int indice;

	if(arrayRecurso != NULL && arrayTipo && limiteRecurso > 0 && limiteTipo > 0){



	indice = recurso_buscarEspacioLibre(arrayRecurso, limiteRecurso);

	if (indice != -1) {

		if (utn_getDescripcion(auxiliar.descripcion, DESCRIPCION,"\nDescripcion?\n", "\nERROR\n", 100000) == 0
			&& utn_getNumeroFlotante(&auxiliar.precioPorHora, "\nPrecio?\n","\nERROR\n", 0, 10000, 100000) == 0)
		{
			auxiliar.tipoId = pedirTipo(arrayTipo, limiteTipo);
		}

		auxiliar.idRecurso = idRecurso();

		auxiliar.isEmpty = 1;

		arrayRecurso[indice] = auxiliar;

		retorno = 0;
		}
	}

	return retorno;
}

/**
 * \brief Modifico los datos de una variable de tipo recurso seleccionado
 * \param arrayRecurso Array de tipo recurso
 * \param arrayTipo Array de tipo tipo
 * \param limiteRecurso Limite del array de recurso
 * \param limiteTipo Limite del array de tipo
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */

int recurso_modificarRecurso(recurso arrayRecurso[], tipo arrayTipo[], int limiteRecurso, int limiteTipo) {

	int retorno = -1;
	int id;
	int indice;
	int opcion;

	if (arrayRecurso != NULL && arrayTipo != NULL && limiteTipo > 0 && limiteRecurso > 0) {

		recurso_imprimirArray(arrayRecurso, arrayTipo, limiteRecurso,limiteTipo);

		if (utn_getNumero(&id, "Ingrese el ID que desea modificar",
				"Error al ingresar id", 0, 20, 3) == 0) {

			while (recurso_buscarId(arrayRecurso, limiteRecurso, id) == -1) {
				puts("NO EXISTE ID.");
				utn_getNumero(&id, "Ingrese el ID que desea modificar","Error al ingresar id", 0, 20, 3);
			}

			indice = recurso_buscarId(arrayRecurso, limiteRecurso, id);

			if (indice != -1) {

				if (utn_getNumero(&opcion, "\nMenu para modificar recurso"
						"\n\n1.Ingrese 1 para modificar precio por hora"
						"\n2.Ingrese 2 para modificar la descripcion",
						"\nError opcion invalida", 1, 2, 10000) == 0) {
					switch (opcion) {
					case 1:
						utn_getNumeroFlotante(&arrayRecurso[indice].precioPorHora,"\nPrecio?\n", "\nERROR\n", 1, 10000, 100000);
						retorno = 0;
						break;
					case 2:
						utn_getDescripcion(arrayRecurso[indice].descripcion,DESCRIPCION, "\nDescripcion?\n", "\nERROR\n", 1000000);
						retorno = 0;
						break;
					}

				}

			}

		}
	}
	return retorno;
}

/**
 * \brief Da de baja un recurso ingresando su ID
 * \param arrayRecurso Array de tipo recurso
 * \param arrayTipo Array de tipo tipo
 * \param limiteRecurso Limite del array de recurso
 * \param limiteTipo Limite del array de tipo
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int recurso_bajaArray(recurso arrayRecurso[], tipo arrayTipo[], int limiteRecurso, int limiteTipo) {
	int retorno = -1;
	int id;
	int indice;

	if (arrayRecurso != NULL && arrayTipo != NULL && limiteRecurso > 0 && limiteTipo > 0) {

		recurso_imprimirArray(arrayRecurso, arrayTipo, limiteRecurso, limiteTipo);

		if (utn_getNumero(&id, "Ingrese el ID que desea modificar","Error al ingresar id", 1, 20, 10000) == 0) {

			while (recurso_buscarId(arrayRecurso, limiteRecurso, id) == -1) {
				puts("NO EXISTE ID.");
				utn_getNumero(&id, "Ingrese el ID que desea modificar", "Error al ingresar id", 1, 20, 10000);
			}

			indice = recurso_buscarId(arrayRecurso, limiteRecurso, id);

			arrayRecurso[indice].isEmpty = 0;

			retorno = 0;
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
int recurso_buscarId(recurso arrayRecurso[], int limiteRecurso, int valorBuscado) {
	int respuesta = -1;
	int i;
	if (arrayRecurso != NULL && limiteRecurso > 0 && valorBuscado > 0) {
		for (i = 0; i < limiteRecurso; i++) {
			if (arrayRecurso[i].idRecurso == valorBuscado) {
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}


/**
*\brief: Verifica que haya espacio para cargar un nuevo dato de tipo transporte.
*\param: Array de tipo transporte, Longitud del array.
*\return: Retorna 1 si encuentra espacio, Retorna 0 si no lo encuentra.
**/
int buscarEspacio(recurso arrayRecurso[], int limiteArray){
	int retorno = 0;
	if(arrayRecurso != NULL && limiteArray > 0){
		for(int i = 0; i < limiteArray; i++){

			if(arrayRecurso[i].isEmpty == 0){
				retorno = 1;
			}
		}
	}
	return retorno;
}

/**
 * \brief Buscar primer posicion vacia
 * \param arrayRecurso Array de recursos
 * \param limiteRecurso Limite del array de recurso
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int recurso_buscarEspacioLibre(recurso arrayRecurso[], int limiteRecurso) {
	int respuesta = -1;
	int i;
	if (arrayRecurso != NULL && limiteRecurso > 0) {
		respuesta = 0;
		for (i = 0; i < limiteRecurso; i++) {
			if (arrayRecurso[i].isEmpty == 0) {
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

/**
 * \brief Ordena el array por ID y por descripcion
 * \param arrayRecurso Array de recursos
 * \param limiteRecurso Limite del array de recurso
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */

int recurso_ordenarPorIdDescripcion(recurso arrayRecurso[], int limiteRecurso) {
	int i;
	int j;
	recurso buffer;
	if (arrayRecurso != NULL && limiteRecurso > 0) {

		for (i = 0; i < limiteRecurso - 1; i++) {
			for (j = i + 1; j < limiteRecurso; j++) {
				if (arrayRecurso[i].tipoId > arrayRecurso[j].tipoId) {
					buffer = arrayRecurso[i];
					arrayRecurso[i] = arrayRecurso[j];
					arrayRecurso[j] = buffer;
				} else if (arrayRecurso[i].tipoId == arrayRecurso[j].tipoId) {
					if (strncmp(arrayRecurso[i].descripcion, arrayRecurso[j].descripcion, limiteRecurso) > 0) {
						buffer = arrayRecurso[i];
						arrayRecurso[i] = arrayRecurso[j];
						arrayRecurso[j] = buffer;
					}
				}
			}

		}

	}
	return 0;
}
