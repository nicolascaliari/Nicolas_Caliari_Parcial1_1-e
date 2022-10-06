#include "tipo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "recurso.h"
#include "utn.h"
#include "tipo.h"

int tipos(void) {
	int i;
	int opcion;
	tipo tipos;

	utn_getNumero(&opcion,
			"Ingrese 1-LOCUCION \n 2-ANIMACION \n 3-ILUMINACION \n 4-DJ",
			"error", 1, 4, 2);

	switch (opcion) {

	case 1:
		tipos.idTipo = 1000;
		strcpy(tipos.descripcion, "locucion");
		printf("%s", tipos.descripcion);
		break;
	case 2:
		tipos.idTipo = 1001;
		strcpy(tipos.descripcion, "animacion");
		printf("%s", tipos.descripcion);
		break;
	case 3:
		tipos.idTipo = 1002;
		strcpy(tipos.descripcion, "iluminacion");
		printf("%s", tipos.descripcion);
		break;
	case 4:
		tipos.idTipo = 1003;
		strcpy(tipos.descripcion, "DJ");
		printf("%s", tipos.descripcion);
		break;

	}
	return tipos.idTipo;
}

//int listarTipos(tipo pElemento) {
//
//	int retorno = -1;
////	if (pElemento.isEmpty == 0) {
//		retorno = 0;
//		printf("\n Descripcion:%s tipoId:%d",
//				pElemento.descripcion, pElemento.idTipo);
////	}
//	return retorno;
//
//}
