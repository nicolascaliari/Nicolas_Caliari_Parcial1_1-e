/*
 * evento.h
 *
 *  Created on: 3 oct. 2022
 *      Author: nicolas
 */

#ifndef EVENTO_H_
#define EVENTO_H_
#define LOCALIDAD 30

typedef struct {
	int dia;
	int mes;
	int anio;
}fecha;


typedef struct {
	int idEvento;
	char localidad[LOCALIDAD];
	float fecha;
	int cantidad;
	int recursoId;
	fecha unaFecha;
	int isEmpty;
}evento;

int evento_imprimir(evento pElemento);
int evento_inicializarArray(evento array[],int limite);
int evento_altaArray(evento array[],int limite, int indice, int* id);
int evento_getEmptyIndex(evento array[],int limite);
int evento_imprimirArray(evento array[],int limite);
int evento_buscarId(evento array[], int limite, int valorBuscado);
int evento_modificarArray(evento array[],int limite, int indice);
int evento_bajaArray(evento array[],int limite, int indice);



#endif /* EVENTO_H_ */
