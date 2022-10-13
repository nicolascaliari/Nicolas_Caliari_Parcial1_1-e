/*
 * tipo.h
 *
 *  Created on: 4 oct. 2022
 *      Author: nicolas
 */

#ifndef TIPO_H_
#define TIPO_H_


typedef struct {
	int idTipo;
	char descripcion[31];
}tipo;
void HardcodeoTipos(tipo arrayTipo[], int limiteTipo);
int pedirTipo(tipo arrayTipo[] , int limiteTipo);
int mostrarTipos(tipo arrayTipo[], int limiteTipo);




#endif /* TIPO_H_ */
