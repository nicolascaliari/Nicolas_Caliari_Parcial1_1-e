/*
 ============================================================================
 Name        : primer_prueba.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "recurso.h"
#include "evento.h"
#include "informes.h"
#include "tipo.h"

#define CANTIDAD_RECURSOS 100
#define CANTIDAD_EVENTOS 100
#define CANTIDAD_TIPOS 100

int main(void) {
	int opcion;
	int auxiliarIndice;
	recurso unRecurso[CANTIDAD_RECURSOS];
	evento unEvento[CANTIDAD_EVENTOS];
//	tipo unTipo[CANTIDAD_TIPOS];
	int idEvento = 20000;
	int banderaRecurso;
	banderaRecurso = 1;

	recurso_inicializarArray(unRecurso, CANTIDAD_RECURSOS);
	evento_inicializarArray(unEvento, CANTIDAD_EVENTOS);

	do {
		if (!utn_getNumero(&opcion, "\n\n1.ALTA RECURSO"
				"\n2.MODIFICAR RECURSO"
				"\n3.BAJA RECURSO"
				"\n4.-LISTAR RECURSOS"
				"\n5.LISTAR TIPOS"
				"\n6.-ALTA EVENTO"
				"\n7.LISTAR EVENTOS\n"
				"\n8.INFORMES"
				"\n9.Salir\n", "\nError opcion invalida", 1, 8, 2)) {
			switch (opcion) {
			case 1:
				if (recurso_altaArray(unRecurso, CANTIDAD_RECURSOS) == 1) {
					printf("Dado de alta exitosamente");
					banderaRecurso = 0;
				} else {
					printf("No se pudo dar de alta");
				}

				break;
			case 2:
				if (recurso_modificarArray(unRecurso, CANTIDAD_RECURSOS) == 1) {
					printf("Modificacion exitosa");
				} else {
					printf("No se pudo realizar la modificacion");
				}
				break;

			case 3:

				if (recurso_bajaArray(unRecurso, CANTIDAD_RECURSOS,
						auxiliarIndice) == 1) {
					printf("Dado de baja exitosamente");
				} else {
					printf("No se pudo dar de baja");
				}
				break;
			case 4:
				recurso_ordenarPorIdDescripcion(unRecurso, CANTIDAD_RECURSOS);
				recurso_imprimirArray(unRecurso, CANTIDAD_RECURSOS);

				break;

			case 5:

				recurso_imprimirArray(unRecurso, CANTIDAD_RECURSOS);
//				listarTipos(unTipo);
				break;

			case 6:
				if (banderaRecurso == 0) {

					auxiliarIndice = evento_getEmptyIndex(unEvento,
					CANTIDAD_EVENTOS);
					if (auxiliarIndice >= 0) {
						if (evento_altaArray(unEvento, CANTIDAD_EVENTOS,
								auxiliarIndice, &idEvento) == 0) {
							printf("\nCarga realizada con exito\n");
						}
					} else {
						printf("\nNO HAY MAS LUGAR");
					}
				} else {
					printf("Debes ingresar un recurso al menos");
				}
				break;

			case 7:
				evento_imprimirArray(unEvento, CANTIDAD_EVENTOS);

				break;
			case 8:
				menu();
				break;

			}
		}
	} while (opcion != 8);

	return EXIT_SUCCESS;
}

//la PK es la clave primaria, que debe ser unica en cada estructura,
//no se repite dentro de esa estructura
//por ejemplo idAnimal
//
//
//la Fk es una clave primaria de OTRA estructura,
//entonces si se puede repetir no hay problema (siempre y cuando sea FK, osea no es la primaria)
