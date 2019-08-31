/*============================================================================
 * License: BSD-3-Clause
 * Copyright 2019, Issam Almustafa <Lssam.almustafa@gmail.com>
 * All rights reserved.
 * Date: 2019/07/25
 *===========================================================================*/

#ifndef _SERVICE_TESTING_H_
#define _SERVICE_TESTING_H_

/*==================[inclusions]=============================================*/
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*==================[cplusplus]==============================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================[macros]=================================================*/

/*==================[typedef]================================================*/


typedef  struct MedirPerformance{

	volatile  uint8_t estado ;
	volatile  uint32_t id_of_package;
	volatile  uint8_t * payload;
	volatile  uint32_t tiempo_de_llegada;
	volatile  uint32_t tiempo_de_recepcion;
	volatile  uint32_t tiempo_de_inicio;
	volatile  uint32_t tiempo_de_fin;
	volatile  uint32_t tiempo_de_salida;
	volatile  uint32_t tiempo_de_transmision;
	volatile  uint16_t package_length;
	volatile  uint16_t  alocated_memory;

};



typedef struct MedirPerformance *Token_pt;												//Define a pointer type that can only points at this type of structure

/*==================[external data declaration]==============================*/

/*==================[external functions declaration]=========================*/

int fsmMesurePerformance(Token_pt t, uint8_t *pLoad,uint16_t memSize);
int CompileToken(Token_pt pt, char *msg);													//This function compiles the token message in a string form from the integer fields of the token structure
int op0(char *data, const char* buffer);
/*==================[cplusplus]==============================================*/

#ifdef __cplusplus
}
#endif

/*==================[end of file]============================================*/
#endif /* #ifndef _SERVER_H_ */
