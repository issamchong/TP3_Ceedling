/*============================================================================
 * License: BSD-3-Clause
 * Copyright 2019, Issam Almustafa <Lssam.almustafa@gmail.com>
 * All rights reserved.
 * Date: 2019/07/25
 *===========================================================================*/
/*==================[inclusions]=============================================*/
#include "service_testing.h"  // <= own header
/*==================[macros and definitions]=================================*/
/*==================[internal data declaration]==============================*/
	volatile uint16_t  time1=0;
	volatile uint16_t  time2=0;
/*==================[internal functions declaration]=========================*/
/*==================[internal data definition]===============================*/
/*==================[external data definition]===============================*/
/*==================[internal functions definition]==========================*/
/*==================[external functions definition]==========================*/

int CompileToken(Token_pt pt,char *msg){

	char id[10];
	char pload[20];
	char Tllegar[10];
	char Trecp[10];
	char Tinicio[10];
	char Tfin[10];
	char Tsalida[10];
	char Ttrans[10];
	char len[10];
	char mem[10];

    snprintf(id,sizeof(id),"%d",pt->id_of_package);
	snprintf(pload,sizeof(pload),"%d",pt->payload);
	snprintf(Tllegar,sizeof(Tllegar),"%d",pt->tiempo_de_llegada);
	snprintf(Trecp,sizeof(Trecp),"%d",pt->tiempo_de_recepcion);
	snprintf(Tinicio,sizeof(Tinicio),"%d",pt->tiempo_de_inicio);
	snprintf(Tfin,sizeof(Tfin),"%d",pt->tiempo_de_fin);
	snprintf(Tsalida,sizeof(Tsalida),"%d",pt->tiempo_de_salida);
	snprintf(Ttrans,sizeof(Ttrans),"%d",pt->tiempo_de_transmision);
	snprintf(len,sizeof(len),"%d",pt->package_length);
	snprintf(mem,sizeof(mem),"%d",pt->alocated_memory);

    strcat(msg,"\0");
    strcat(msg,"{5ID:");
    strcat(msg,id);

    strcat(msg,"PLoad:");
    strcat(msg,pload);

    strcat(msg,"Tlleg:");
    strcat(msg,Tllegar);

    strcat(msg,"TRec:");
    strcat(msg,Trecp);

    strcat(msg,"TIn:");
    strcat(msg,Tinicio);

    strcat(msg,"TFn:");
    strcat(msg,Tfin);

    strcat(msg,"TSal:");
    strcat(msg,Tsalida);

    strcat(msg,"TTran:");
    strcat(msg,Ttrans);

    strcat(msg,"LEN:");
    strcat(msg,len);

    strcat(msg,"MEM:");
    strcat(msg,mem);

    strcat(msg,"}");
}
int fsmMesurePerformance(Token_pt  t, uint8_t *pload, uint16_t AloMem){

	switch(t->estado)
	{
	case 0:
		t->estado=1;
		t->id_of_package++;
		t->tiempo_de_llegada=0;
		time2=1;
		t->tiempo_de_recepcion=(uint32_t)(time2-time1);					//Save of receiving last byte
		time1=time2;									   	   	   	   	//Increment the package ID
		time2=0;
		break;
	case 1:
		t->estado=2;
		t->payload=pload;
		t->package_length=strlen(pload);
		t->alocated_memory=AloMem;
		break;
	case 2:
		time2=1;
		t->tiempo_de_inicio=(uint32_t)(time2-time1);					//Update the corresponding time
		time1=time2;
		time2=0;
		t->estado=3;													//R4.3 satisfy requirement 4.3
		break;
	case 3:
		time2=2;
		t->estado=4;												 // R4.4 satisfy requirement 4.4
		t->tiempo_de_fin=(uint32_t)(time2-time1);					 //Update the corresponding time
		time1=time2;
		time2=0;
		//printf("TIME last byte in  is %p\n",t->tiempo_de_fin);
		break;
	case 4:
		time2=3;											//Set time2 to current tick count in ms
		t->estado=5;														// R4.5 Update the FSM state
		t->tiempo_de_salida=(uint32_t)(time2-time1);						//Update the corresponding time
		time1=time2;
		time2=0;
		//printf("TIME last byte in  is %p\n",t->tiempo_de_salida);
		break;
	case 5:																	// R4.6 starts
		time2=4;											//Get current tick count
		t->estado=6;
		t->tiempo_de_transmision=(uint32_t)(time2-time1);					//Update the corresponding time
		break;
	default:
		t->estado=0;
		break;
	}
	return 0;
}
void GetHeap(char *frame){
	   uint8_t Heap =125;
	   char sizeHeap[10];
	   char pload_len[3];
	   char data[100];

	   snprintf(sizeHeap,sizeof(sizeHeap),"%d",Heap);              //Convert Heap variable into string and save it in sizeHeap
	   strcpy(data," Heap size is ");								//Add text to data
	   snprintf(pload_len,sizeof(pload_len),"%d",strlen(data));							//Get data buffer length and save it in pload_len
	   strcat(data,sizeHeap);										//Add heap size to data
	   strcpy(frame,"{");											//Add SOF
	   strcat(frame,"3");											//Add operation number to the frame as a string
	   strcat(frame,pload_len);										//Add the payload length to the frame
	   strcat(frame,data);											//Add the actual data to be displayed
	   strcat(frame,"}");											//Add the EOF
}
int match(char *str1,char *str2){

	   while (*str1 == *str2) {
	      if (*str1 == '\0' || *str2 == '\0')
	         break;

	      str1++;												//Increment until you reach the last empty byte of any string "\0"
	      str2++;
	   }
       //come here when the pointer is pointing at nothing "\0"
	   if (*str1 == '\0' && *str2 == '\0')						//Check if both pointers are pointing at the end of the string
	      return 0;
	   else
	      return -1;

}
int GetData(char *data, const char* buffer ){

	strcpy(data,buffer+4);
	data[strlen(data)-1]='\0';
	return 1;
}






/*==================[end of file]============================================*/
