/*============================================================================
 * License: BSD-3-Clause
 * Copyright 2019, Issam Almustafa <Lssam.almustafa@gmail.com>
 * All rights reserved.
 * Date: 2019/07/25
 *===========================================================================*/

#ifndef _TP3_H_
#define _TP3_H_

/*==================[inclusions]=============================================*/
#include <stdint.h>
#include<stdio.h>
#include <string.h>
#include "tp3.h"

/*==================[cplusplus]==============================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================[macros]=================================================*/

/*==================[typedef]================================================*/

/*==================[external data declaration]==============================*/

/*==================[external functions declaration]=========================*/

void length(uint16_t *buf, uint16_t *len);
void bufsize(uint16_t *buf, uint16_t *size );
void sumsat(uint16_t *var );
void subsat(uint16_t *var );
void twice(uint16_t *var );


#ifdef __cplusplus
}
#endif

/*==================[end of file]============================================*/
#endif /* #ifndef _SERVER_H_ */
