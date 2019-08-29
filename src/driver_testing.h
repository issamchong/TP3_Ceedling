/*============================================================================
 * License: BSD-3-Clause
 * Copyright 2019, Issam Almustafa <Lssam.almustafa@gmail.com>
 * All rights reserved.
 * Date: 2019/07/25
 *===========================================================================*/

#ifndef _DRIVER_TESTING_H_
#define _DRIVER_TESTING_H_

/*==================[inclusions]=============================================*/

#include <stdint.h>
#include<stdio.h>
#include <string.h>
/*==================[cplusplus]==============================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================[macros]=================================================*/

/*==================[typedef]================================================*/

/*==================[external data declaration]==============================*/

/*==================[external functions declaration]=========================*/


//This function copies the data portion of the the message buffer to data  and casts data type to read-only on MsgBuffer inside this block only
//This function gets the operation byte and saves it into operation buffer
int ASCI(char *frame,uint8_t size,char *buf);


/*==================[cplusplus]==============================================*/

#ifdef __cplusplus
}
#endif

/*==================[end of file]============================================*/
#endif /* #ifndef _TASK2_H_ */
