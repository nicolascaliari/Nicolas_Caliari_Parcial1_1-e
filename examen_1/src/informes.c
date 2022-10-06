#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "recurso.h"
#include "utn.h"



void menu(void) {

	int opcion;
	do {
		if (!utn_getNumero(&opcion,
				"\n\n1.Mostrar recursos de un tipo seleccionado"
				"\n2.Mostrar todos los eventos efectuados en una fecha seleccionada"
				"\n3.Informar importe total de los eventos realizados para un recurso seleccionado\n"
				"\n4.Informar importe total de todos los eventos de un tipo en una fecha seleccionada"
				, "\nError opcion invalida", 1, 7,
				2)) {
			switch (opcion) {
			case 1:
				break;
			case 2:
				break;
			}
		}
	} while (opcion != 5);
}
