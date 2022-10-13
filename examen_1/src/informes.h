/*
 * informes.h
 *
 *  Created on: 3 oct. 2022
 *      Author: nicolas
 */


#ifndef INFORMES_H_
#define INFORMES_H_
#include "recurso.h"
void menu(recurso arrayRecurso[], tipo arrayTipo[], evento arrayEvento[], int limiteRecurso, int limiteTipo, int limiteEvento);
int filtrarPorTipo(recurso valor[], tipo arrayTipo[], int limite, int limiteTipo);
int informe_imprimir(recurso unRecurso, tipo arrayTipos[], int limiteTipos);
int fechas_imprimir(evento arrayEvento[], int limiteEVento);
int filtrarPorFecha(evento arrayEvento[], int limiteEvento);
int calcularImporteTotal(evento arrayEvento[], tipo arrayTipo[], recurso arrayRecurso[],int limiteEvento, int limiteTipo, int limiteRecurso);
int importeTotalPorFechayTipo(evento arrayEvento[],recurso arrayRecurso[] ,tipo arrayTipo[], int limiteEvento, int limiteTipo, int limiteRecurso);



#endif /* INFORMES_H_ */
