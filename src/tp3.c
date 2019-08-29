
/*============================================================================
 * License: BSD-3-Clause
 * Copyright 2019, Issam Almustafa <Lssam.almustafa@gmail.com>
 * All rights reserved.
 * Date: 2019/07/25
 *===========================================================================*/

/*==================[inclusions]=============================================*/

#include "tp3.h"  // <= own header
/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/

void length(uint16_t *buf, uint16_t *len){

	*len=strlen(buf);

}
void bufsize(uint16_t *buf, uint16_t *size ){

	*size=sizeof(buf);

}
void sumsat(uint16_t *var ){

	*var=0xffff;

}
void subsat(uint16_t *var ){

	*var=0x0000;
}
void twice(uint16_t *var ){

	*var*2;
}



/*==================[end of file]============================================*/
