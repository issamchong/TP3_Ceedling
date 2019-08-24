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
/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/
void tearDown(void);
void test_tp3_1(void);
void test_tp3_2(void);
void test_tp3_3(void);
void test_tp3_4(void);
void test_tp3_5(void)
/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/
;
void tearDown(void){					   //This function is used by ceedling and needs to be empty


}

void test_tp3_1(void){						//This is the start of th first test length()
	TEST_FAIL_MESSAGE("Failed");
	uint16_t buf[10];						//Declaring a buffer for test purpose of size 10
	uint16_t cant;							//This variable stores the number of bytes the buffer contains
	length(buf,&cant);						//This is our function to test, it measures the number of bytes of a buffer
	TEST_ASSERT_EQUAL_HEX16(5,cant);		//This function  checks if length() did really count correctly the number of  bytes, assuming it is 5

}
void test_tp3_2(void){						//This is the start of the second test to test bufsize()
	TEST_FAIL_MESSAGE("Failed");			//Error message if test fails
	uint16_t buf[10];						//Declaring a buffer for test purpose of size 10
	uint16_t size;							///This variable stores the number of bytes the buffer contains
	bufsize(buf,&size);						//This is the function to test, it measures the size of a given buffer  and saves the result in the variable size
	TEST_ASSERT_EQUAL_HEX16(10,size);		//Verify of the returned value is correct

}

void test_tp3_3(void){						//This is the third test to test sumsat()
	TEST_FAIL_MESSAGE("Failed");			//Error message if test fails
	uint16_t MAX=0xffff;					//Set MAX to the maximum value 16 bit register can have
	uint16_t value;							//Value is the argument passed to the function
	sumsat(&value);							//This is the function to test, it increment the passed argument and the purpose is to know when it is saturated
	TEST_ASSERT_EQUAL_HEX16(MAX,value);     //Check if the function does really saturate the variable

}
void test_tp3_4(void){						// This is the 4th function to test subsat()
	TEST_FAIL_MESSAGE("Failed");
	uint16_t MIN=0x0000;					//MIN is used to for comparison purpose against the argument passed to the function
	uint16_t value;							//This variable  holds the value passed to the function
	subsat(&value);							//This is the function to test, it saturates the given argument to zero
	TEST_ASSERT_EQUAL_HEX16(MIN,value);		//Check if the function did really saturated the argument

}

void test_tp3_5(void){						//This is the 5th test function to test twice()
	TEST_FAIL_MESSAGE("Failed");
	uint16_t x;								//First argument  goes here
	uint16_t y=2*x;							//The second argument  is stored here which is twice the first (x)
	twice(&x);								//The function  takes the variable pointer and doubles its value
	TEST_ASSERT_EQUAL_HEX16(y,x);			//Check if the value was really doubled
}



/*==================[external functions definition]==========================*/

/*==================[Principal function ]======================================*/
void setUp(void){


}
/*==================[End of file]========================================*/
