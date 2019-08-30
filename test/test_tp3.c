/* Copyright 2019-2020, Issam ALmustafa
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
/*==================[Inclusions]===========================================*/
#include "unity.h"
#include "tp3.h"
#include "service_testing.h"
#include "service_testing.h"
#include "driver_testing.h"
/*==================[macros and definitions]=================================*/
/*==================[internal data declaration]==============================*/
static struct MedirPerformance performance;
Token_pt  ptr;
/*==================[internal functions declaration]=========================*/
void tearDown(void);
void test_tp3_1(void);
void test_tp3_2(void);
void test_tp3_3(void);
/*==================[internal data definition]===============================*/
/*==================[external data definition]===============================*/
/*==================[internal functions definition]==========================*/
void tearDown(void){}					   		//This function is used by ceedling and needs to be empty

void test_tp3_1(void){							//Test GetHeap function, this function extracts the data section from a package and is used inside other functions
	char package[]="{004hello}";
	char data[100];
	GetData(data,package);
	printf("%s", data);
	TEST_ASSERT_EQUAL_HEX16('h',data[0]);
	TEST_ASSERT_EQUAL_HEX16('e',data[1]);
	TEST_ASSERT_EQUAL_HEX16('l',data[2]);
	TEST_ASSERT_EQUAL_HEX16('l',data[3]);
	TEST_ASSERT_EQUAL_HEX16('o',data[4]);

}
void test_tp3_2(void){												//Test if two buffer content is the same

	char buff1[]="abc";
	char buff2[]="abc";
	int result=match(buff1,buff2);
	TEST_ASSERT_EQUAL_HEX16(0,result);

}
void test_tp3_3(void){												//Test if the second  FSM function call updated the corresponding  fields  according to the new state
	//TEST_FAIL_MESSAGE("Failed");
	ptr=&performance;
	char msg[100]="Hola, this is a test";
	fsmMesurePerformance(ptr,NULL,NULL);
	fsmMesurePerformance(ptr,msg,sizeof(msg));
	TEST_ASSERT_EQUAL_HEX16(2,ptr->estado);
	TEST_ASSERT_EQUAL_HEX16(strlen(msg),ptr->package_length);
	TEST_ASSERT_EQUAL_HEX16(sizeof(msg),ptr->alocated_memory);
}
void test_tp3_4(void){											   //Test if CompileToken() did compile the token and included the correct ID based on the previous call of fsmMesurePerformance() that has set the ID
	//TEST_FAIL_MESSAGE("Failed");
	ptr=&performance;
	char token[100];
	bzero(token,strlen(token));
	CompileToken(ptr,token);
	//printf("test id is in token %c", token[5]);
	TEST_ASSERT_EQUAL_HEX16('1',token[5]);
}
void test_tp3_5(void){											//Test if ASCII function converts Hexdecimal to ASCII correctly by verifying the first letter
	//TEST_FAIL_MESSAGE("Failed");
	char ascii[55];
	char hex[105]="68";
	ASCI(hex,strlen(hex),ascii);
	TEST_ASSERT_EQUAL_HEX16('h',ascii[0]);									//This function  checks if length() did really count correctly the number of  bytes, assuming it is 5
}
/*==================[external functions definition]==========================*/

/*==================[Principal function ]======================================*/
void setUp(void){


}
/*==================[End of file]========================================*/
