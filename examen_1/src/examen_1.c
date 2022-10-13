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

#define CANTIDAD_RECURSOS 20
#define CANTIDAD_EVENTOS 20
#define CANTIDAD_TIPOS 4

int main(void) {
	int opcion;
	recurso unRecurso[CANTIDAD_RECURSOS];
	evento unEvento[CANTIDAD_EVENTOS];
	tipo unTipo[CANTIDAD_TIPOS];
	int banderaImprimir = 0;
	int banderaEvento = 0;
	int contador = 0;

	HardcodeoTipos(unTipo, CANTIDAD_TIPOS);

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
				"\n9.Salir\n", "\nError opcion invalida", 1, 9, 2)) {
			switch (opcion) {
			case 1:
				if (buscarEspacio(unRecurso, CANTIDAD_RECURSOS) == 1) {
					if (recurso_altaArray(unRecurso, CANTIDAD_RECURSOS, unTipo, CANTIDAD_TIPOS) == 0) {
						printf("Dado de alta exitosamente");
						banderaImprimir = 1;
						contador++;
					} else {
						printf("No se pudo dar de alta");
					}
				} else {
					printf("No hay mas espacio");
				}

				break;
			case 2:
				if (banderaImprimir == 1 && recurso_modificarRecurso(unRecurso, unTipo, CANTIDAD_RECURSOS, CANTIDAD_TIPOS) == 0) {
					printf("Modificacion exitosa");
				} else {
					printf("No se pudo realizar la modificacion");
				}
				break;

			case 3:

				if (banderaImprimir == 1 && recurso_bajaArray(unRecurso, unTipo, CANTIDAD_RECURSOS, CANTIDAD_TIPOS) == 0) {
					printf("Dado de baja exitosamente");
					contador--;
					if (contador == 0) {
						banderaImprimir = 0;
					}
				} else {
					printf("No se pudo dar de baja");
				}
				break;
			case 4:
				if (banderaImprimir == 1) {
					recurso_ordenarPorIdDescripcion(unRecurso, CANTIDAD_TIPOS);
					recurso_imprimirArray(unRecurso, unTipo, CANTIDAD_RECURSOS,
					CANTIDAD_TIPOS);
				} else {
					printf("Todavia no se cargo ningun recurso");
				}

				break;

			case 5:
				mostrarTipos(unTipo, CANTIDAD_TIPOS);
				break;

			case 6:
				if (banderaImprimir == 1 && evento_altaArray(unEvento, unRecurso, unTipo, CANTIDAD_EVENTOS, CANTIDAD_RECURSOS, CANTIDAD_TIPOS) == 0) {
					printf("\nDado de alta exitosamente");
					banderaEvento = 1;
				} else {
					printf("\nNo se pudo dar de alta");
				}
				break;

			case 7:
				if (banderaEvento == 1) {
					evento_imprimirArray(unEvento, CANTIDAD_EVENTOS);
				} else {
					printf("No cargaste ningun evento");
				}

				break;
			case 8:
				if (banderaImprimir == 1 && banderaEvento == 1){
					menu(unRecurso, unTipo, unEvento, CANTIDAD_RECURSOS,CANTIDAD_TIPOS, CANTIDAD_EVENTOS);
				} else{
					printf("Debes dar un alta de recurso y un alta de evento");
				}

				break;

			}
		}
	} while (opcion != 9);

	return 0;
}
