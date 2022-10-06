#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "recurso.h"
#include "utn.h"
#include "tipo.h"

static int eGen_ObtenerID(void) {
	//ID AUTOINCREMENTAL - PRIVADO / GLOBAL
	//INICIALIZADO UNA UNICA VEZ AL COMIENZO DEL PROGRAMA CON ALCANCE UNICAMENTE EN FUNCION eGen_ObtenerID();
	static int Gen_idIncremental = 0;
	return Gen_idIncremental++;
}

/**
 * \brief Imprime los datos de un cliente
 * \param pElemento Puntero al producto que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int recurso_imprimir(recurso pElemento) {
	int retorno = 0;
//	int cantidad = 0;
	if (pElemento.isEmpty == 0) {
		retorno = 0;
		printf("\n ID:%d \n Descripcion:%s \n Precio:%.2f \n tipoId:%d\n",
				pElemento.idRecurso, pElemento.descripcion,
				pElemento.precioPorHora, pElemento.tipoId);

//				cantidad++;
	}
//
//	if(cantidad  == 0){
//		retorno = 1;
//		printf("NO hay nada para mostrar");
//	}
	return retorno;
}

/**
 * \brief Imprime el array de clientes
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int recurso_imprimirArray(recurso array[], int limite) {
	int respuesta = -1;
	int i;
	if (array != NULL && limite > 0) {
		respuesta = 0;
		for (i = 0; i < limite; i++) {
			recurso_imprimir(array[i]);
		}
	}
	return respuesta;
}

/**
 * \brief Inicializa el array
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int recurso_inicializarArray(recurso array[], int limite) {
	int respuesta = -1;
	int i;
	if (array != NULL && limite > 0) {
		respuesta = 0;
		for (i = 0; i < limite; i++) {
			array[i].isEmpty = 1;
		}
	}
	return respuesta;
}

/**
 * \brief Da de alta una pantalla en una posicion del array
 * \param array Array de pantallas a ser actualizado
 * \param limite Limite del array de pantallas
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado a la pantalla
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int recurso_altaArray(recurso array[], int limite) {
	int rtn = 0;
	recurso auxGen;

	//BUSCO ESPACIO EN ARRAY
	int index = recurso_getEmptyIndex(array, limite);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
		//PIDO DATOS - CARGO Gen AUXILIAR
		auxGen = eGen_CargarDatos();
		//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
		auxGen.idRecurso = eGen_ObtenerID();
		//CAMBIO SU ESTADO A "OCUPADO"
		auxGen.isEmpty = 0;
		//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		array[index] = auxGen;

		//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		rtn = 1;
	}

	return rtn;
}

recurso eGen_CargarDatos(void) {
	recurso auxiliar;
	utn_getDescripcion(auxiliar.descripcion, DESCRIPCION, "\nDescripcion?\n",
			"\nERROR\n", 2);
	utn_getNumeroFlotante(&auxiliar.precioPorHora, "\nPrecio?\n", "\nERROR\n",
			0, 10000, 2);
	auxiliar.tipoId = tipos();

	return auxiliar;
}

/**
 * \brief Actualiza los datos de un cliente en una posicion del array
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */

recurso eGen_ModificarUno(recurso Gen) {
	recurso auxiliar = Gen;
	int opcion;

	if (!utn_getNumero(&opcion, "\nMenu para modificar recurso"
			"\n\n1.Ingrese 1 para modificar precio por hora"
			"\n2.Ingrese 2 para modificar la descripcion",
			"\nError opcion invalida", 1, 2, 2)) {
		switch (opcion) {
		case 1:
			utn_getNumeroFlotante(&auxiliar.precioPorHora, "\nPrecio?\n",
					"\nERROR\n", 0, 10000, 2);
			break;
		case 2:
			utn_getDescripcion(auxiliar.descripcion, DESCRIPCION,
					"\nDescripcion?\n", "\nERROR\n", 2);
			break;
		}

	}
	return auxiliar;
}

int recurso_modificarArray(recurso array[], int limite) {
	int rtn = 0;
	int idGen;
	int index;
	int flag = 0;
	recurso auxiliar;

	//LISTO TODOS LOS Gen
	if (recurso_imprimirArray(array, limite) == 0) {
		//BANDERA EN 1 SI HAY Gen DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Gen PARA MODIFICAR
	if (flag == 1) {
		//PIDO ID A MODIFICAR
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		utn_getNumero(&idGen, "Ingrese el ID que desea modificar\n",
				"Error al ingresar id", 0, 10, 3);
//			printf("INGRESE ID A DAR DE BAJA: ");
//			scanf("%d", &idGen);

//BUSCO INDEX POR ID EN ARRAY
		while (recurso_buscarId(array, limite, idGen) == -1) {
			puts("NO EXISTE ID.");
			utn_getNumero(&idGen, "Ingrese el ID que desea modificar\n",
					"Error al ingresar id", 0, 10, 3);
			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/

		}

		//OBTENGO INDEX DEL ARRAY DE Gen A MODIFICAR
		index = recurso_buscarId(array, limite, idGen);

		//LLAMO A FUNCION QUE MODIFICA Gen
		auxiliar = eGen_ModificarUno(array[index]);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//MODIFICACION ACEPTADA
		array[index] = auxiliar;

		//RETORNO 1 SI SE MODIFICO CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}

/**
 * \brief Actualiza una posicion del array
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int recurso_bajaArray(recurso array[], int limite, int indice) {
	int rtn = 0;
	int idGen;
	int index;
	int flag = 0;

	//LISTO TODOS LOS Gen
	if (recurso_imprimirArray(array, limite) == 0) {
		//BANDERA EN 1 SI HAY Gen DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Gen PARA DAR DE BAJA
	if (flag == 1) {
		//PIDO ID A DAR DE BAJA
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		utn_getNumero(&idGen, "Ingrese el ID que desea dar de baja\n",
				"Error al ingresar id", 0, 10, 3);

		//BUSCO INDEX POR ID EN ARRAY
		while (recurso_buscarId(array, limite, idGen) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			utn_getNumero(&idGen, "Ingrese el ID que desea dar de baja\n",
					"Error al ingresar id", 0, 10, 3);
		}

		//OBTENGO INDEX DEL ARRAY DE Gen A DAR DE BAJA
		index = recurso_buscarId(array, limite, idGen);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//BAJA ACEPTADA - CAMBIO ESTADO A "BAJA"
		array[index].isEmpty = 1;

		//RETORNO 1 SI SE DIO DE BAJA CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
 * \param array cliente Array de cliente
 * \param limite int Tamaño del array
 * \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
 * \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
 *
 */
int recurso_buscarId(recurso array[], int limite, int valorBuscado) {
	int respuesta = -1;
	int i;
	if (array != NULL && limite > 0 && valorBuscado >= 0) {
		respuesta = 0;
		for (i = 0; i < limite; i++) {
			if (array[i].idRecurso == valorBuscado) {
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

/**
 * \brief Buscar primer posicion vacia
 * \param array Array de clientes
 * \param limite Limite del array de clientes
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int recurso_getEmptyIndex(recurso array[], int limite) {
	int respuesta = -1;
	int i;
	if (array != NULL && limite > 0) {
		respuesta = 0;
		for (i = 0; i < limite; i++) {
			if (array[i].isEmpty == 1) {
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

int recurso_ordenarPorIdDescripcion(recurso array[], int limite) {
	int respuesta = -1;
	int flagSwap;
	int i;
	recurso buffer;
	if (array != NULL && limite > 0) {
		do {
			flagSwap = 0;
			for (i = 0; i < limite - 1; i++) {

				if (array[i].tipoId > array[i + 1].tipoId) {
					flagSwap = 1;
					buffer = array[i];
					array[i] = array[i + 1];
					array[i + 1] = buffer;
				} else {

					if (strncmp(array[i].descripcion, array[i + 1].descripcion,
					DESCRIPCION) > 0) {
						flagSwap = 1;
						buffer = array[i];
						array[i] = array[i + 1];
						array[i + 1] = buffer;
					}
				}

			}
			limite--;
		} while (flagSwap);
	}
	return respuesta;
}

//int cli_ordenarPorIdDescripcion(recurso* array,int limite)
//{
//	int respuesta = -1;
//	int flagSwap;
//	int i;
//	recurso buffer;
//	int auxiliarCmp;
//	if(array != NULL && limite > 0)
//	{
//		do
//		{
//			flagSwap = 0;
//			for(i=0;i<limite-1;i++)
//			{
//				auxiliarCmp = strncmp(array[i].descripcion,array[i+1].descripcion,DESCRIPCION);
//				if(	 auxiliarCmp > 0 ||
//					(auxiliarCmp == 0 && array[i].tipoId < array[i+1].tipoId) )
//				{
//					flagSwap = 1;
//					buffer = array[i];
//					array[i] = array[i+1];
//					array[i+1]=buffer;
//				}
//			}
//			limite--;
//		}while(flagSwap);
//	}
//	return respuesta;
//}

/**
 * \brief Ordenar el array de clientes por nombre
 * \param array Array de clientes
 * \param limite Limite del array de clientes
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
//int prod_ordenarPorDescripcion(recurso* array,int limite)
//{
//	int respuesta = -1;
//	int flagSwap;
//	int i;
//	recurso buffer;
//	if(array != NULL && limite > 0)
//	{
//		do
//		{
//			flagSwap = 0;
//			for(i=0;i<limite-1;i++)
//			{
//				if(array[i].isEmpty || array[i+1].isEmpty)
//				{
//					continue;
//				}
//				if(strncmp(array[i].descripcion,array[i+1].descripcion,NOMBRE_LEN) > 0)
//				{
//					flagSwap = 1;
//					buffer = array[i];
//					array[i] = array[i+1];
//					array[i+1]=buffer;
//				}
//			}
//			limite--;
//		}while(flagSwap);
//	}
//	return respuesta;
//}
//
//
//int OrdenaArrayInt(recurso* array,int limite)
//{
//   int flagSwap;
//   int i;
//   int contador = 0;
//   int retorno = -1;
//   recurso buffer;
//
//   if(array != NULL && limite > 0){
//	   do{
//		   flagSwap=0;
//		   for(i=0; i<limite-1;i++){
//			   if(array[i].precio < array[i+1].precio){
//				   flagSwap = 1;
//				   buffer = array[i];
//				   array[i] = array[i+1];
//				   array[i+1] = buffer;
//			   }
//			   contador++;
//		   }
//	   }while(flagSwap);
//	   retorno = contador;
//   }
//   return retorno;
//}
