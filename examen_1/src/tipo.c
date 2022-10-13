#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "tipo.h"
#define CANTIDAD_TIPOS 4

/**
 * \brief Hardcodea los campos de la estructura tipo
 * \param arrayTipo Array de tipos
 * \param limiteTipo Limite del array de tipos
 * \return void
 */
void HardcodeoTipos(tipo arrayTipo[], int limiteTipo) {
	if (arrayTipo != NULL && limiteTipo > 0) {

		arrayTipo[0].idTipo = 1000;
		strncpy(arrayTipo[0].descripcion, "LOCUCION", 30);
		arrayTipo[1].idTipo = 1001;
		strncpy(arrayTipo[1].descripcion, "ANIMACION", 30);
		arrayTipo[2].idTipo = 1002;
		strncpy(arrayTipo[2].descripcion, "ILUMINACION", 30);
		arrayTipo[3].idTipo = 1003;
		strncpy(arrayTipo[3].descripcion, "DJ", 30);
	}
}

/**
 * \brief Pide un ID y lo retorna
 * \param arrayTipo Array de tipos
 * \param limiteTipo Limite del array de tipos
 * \return Retorna el ID ingresado
 *
 */
int pedirTipo(tipo arrayTipo[], int limiteTipo) {
	int opcion;

	if (arrayTipo != NULL && limiteTipo > 0) {

		mostrarTipos(arrayTipo, limiteTipo);

		utn_getNumero(&opcion, "\nElija el ID del tipo que quiera ingresar","error", 1000, 1003, 10000);

	}
	return opcion;
}

/**
 * \brief Muestra todos los tipos hardcodeados
 * \param arrayTipo Array de tipos
 * \param limiteTipo Limite del array de tipos
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int mostrarTipos(tipo arrayTipo[], int limiteTipo) {
	int i;
	int retorno = -1;

	if (arrayTipo != NULL && limiteTipo > 0) {
		retorno = 0;
		printf(" id    descripcion");
		for (i = 0; i < limiteTipo; i++) {
			printf("\n%d   %s", arrayTipo[i].idTipo, arrayTipo[i].descripcion);
		}
	}
	return retorno;
}
