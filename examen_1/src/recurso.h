/*
 * recurso.h
 *
 *  Created on: 1 oct. 2022
 *      Author: nicolas
 */

#ifndef RECURSO_H_
#define RECURSO_H_
#define DESCRIPCION 1024



typedef struct {
	int idRecurso;
	char descripcion[DESCRIPCION];
	float precioPorHora;
	int tipoId;
	int isEmpty;
} recurso;


int recurso_imprimir(recurso pElemento);
int recurso_inicializarArray(recurso array[], int limite);
int recurso_altaArray(recurso array[], int limite);
int recurso_getEmptyIndex(recurso array[], int limite);
int recurso_imprimirArray(recurso array[], int limite);
int recurso_buscarId(recurso array[], int limite, int valorBuscado);
int recurso_modificarArray(recurso array[], int limite);
int recurso_bajaArray(recurso array[], int limite, int indice);
int recurso_ordenarPorDescripcion(recurso array[], int limite);
int OrdenaArrayInt(recurso array[], int limite);
int recurso_ordenarPorIdDescripcion(recurso array[], int limite);
recurso eGen_ModificarUno(recurso Gen);
recurso eGen_CargarDatos(void);

#endif /* RECURSO_H_ */
