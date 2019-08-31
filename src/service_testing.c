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
	void upper_string(char s[]) {
	   int c = 0;

	   while (s[c] != '\0') {
	      if (s[c] >= 'a' && s[c] <= 'z') {
	         s[c] = s[c] - 32;
	      }
	      c++;
	   }
	}

	void lower_string(char s[]) {
	   int c = 0;

	   while (s[c] != '\0') {
	      if (s[c] >= 'A' && s[c] <= 'Z') {
	         s[c] = s[c] + 32;
	      }
	      c++;
	   }
	}
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


int op0(char *data, const char* buffer ){

	char temp[100];
	char SizeData[5];																//This string is used to store the size bytes of the data
	char pload_lenth[5];
	int n=0;
	if(!((buffer[0]=='{') && (buffer[strlen(buffer)-1]=='}'))){						//Verify if either start of frame or end of frame is not valid
		puts("Invalid Frame op0");												//Display error if frame does not have "{" or "}"
		}else{
			bzero(SizeData,sizeof(SizeData));
			bzero(pload_lenth,sizeof(pload_lenth));
			SizeData[0]=buffer[2];												   // Save the first byte of the size field in first  element of this buffer
		    SizeData[1]=buffer[3];												   //Save the second byte of size field in this second element  of this buffer
	    //	puts(SizeData);
	    //	puts(SizeData);
	    	strcpy(data,buffer+4);													//Get payload only and save it in data
		    data[strlen(data)-1]='\0';     											//get rid of EOF "}"
	    //	puts(data);
		    snprintf(pload_lenth,4,"%d\n",strlen(data));
	    	//puts(pload_lenth);
		  //  printf("lenth is %d\n",strlen(pload_lenth)-1);
	    	if((strlen(pload_lenth)-1)==1){
		    	if(SizeData[1]==pload_lenth[0]){
			    	printf("the same op0\n");
			    	strcpy(temp,buffer);												//Copy package content to temp
			    	temp[4]='\0';
			     	upper_string(data);
			    	strcat(temp,data);													//add to temp the processed data
			    	strcpy(data,temp);													//copy temp content back to data
			    	data[strlen(data)]='}';      										//Add EOF
			    	//puts(data);
			    	bzero(temp,strlen(temp));
		    	}else{
		    		puts("Data corropted op0");
		    	}

		    }else{
		    	if((SizeData[0]==pload_lenth[0])&&(SizeData[1]==pload_lenth[1])){		//verify length is the same in case of two bytes length
		    		printf("the same op0\n");
		    		strcpy(temp,buffer);												//Copy package content to temp
		    		temp[4]='\0';
		    		upper_string(data);
		    		strcat(temp,data);													//add to temp the processed data
		    		strcpy(data,temp);													//copy temp content back to data
		    		data[strlen(data)]='}';      										//Add EOF
		    		//puts(data);
		    		bzero(temp,strlen(temp));
		    	}else{
		    		puts("Data corropted op0");
		    	}
		    }
		}
}

int op1(char *data, const char* buffer ){

	char temp[100];
	char SizeData[5];																//This string is used to store the size bytes of the data
	char pload_lenth[5];
	int n=0;
	if(!((buffer[0]=='{') && (buffer[strlen(buffer)-1]=='}'))){						//Verify if either start of frame or end of frame is not valid
		puts(" Invalid Frame op1");												//Display error if frame does not have "{" or "}"
		}else{
			bzero(SizeData,sizeof(SizeData));
			bzero(pload_lenth,sizeof(pload_lenth));
			SizeData[0]=buffer[2];												   // Save the first byte of the size field in first  element of this buffer
		    SizeData[1]=buffer[3];												   //Save the second byte of size field in this second element  of this buffer
	   // 	puts(SizeData);
	   // 	puts(SizeData);
	    	strcpy(data,buffer+4);													//Get payload only and save it in data
		    data[strlen(data)-1]='\0';     											//get rid of EOF "}"
	    //	puts(data);
		    snprintf(pload_lenth,4,"%d\n",strlen(data));
	    //	puts(pload_lenth);
		  //  printf("lenth is %d\n",strlen(pload_lenth)-1);
	    	if((strlen(pload_lenth)-1)==1){												//Verify that the number of bytes is less than 10
		    	if(SizeData[1]==pload_lenth[0]){										//Verify that length of payload is the same in case of 1 byte length
			    	printf("the same op1\n");
			    	strcpy(temp,buffer);												//Copy package content to temp
			    	temp[4]='\0';
			    	lower_string(data);
			    	strcat(temp,data);													//add to temp the processed data
			    	strcpy(data,temp);													//copy temp content back to data
			    	data[strlen(data)]='}';      										//Add EOF
			    	//puts(data);
			    	bzero(temp,strlen(temp));
		    	}else{
		    		puts("Data corropted op1");
		    	}

		    }else{
		    	if((SizeData[0]==pload_lenth[0])&&(SizeData[1]==pload_lenth[1])){		//verify that the payload length is the same in case of two bytes
		    		printf("the same op1\n");
		    		strcpy(temp,buffer);												//Copy package content to temp
		    		temp[4]='\0';
		    		lower_string(data);
		    		strcat(temp,data);													//add to temp the processed data
		    		strcpy(data,temp);													//copy temp content back to data
		    		data[strlen(data)]='}';      										//Add EOF
		    		//puts(data);
		    		bzero(temp,strlen(temp));
		    	}else{
		    		puts("Data corropted op1");
		    	}
		    }
		}
}







/*==================[end of file]============================================*/
