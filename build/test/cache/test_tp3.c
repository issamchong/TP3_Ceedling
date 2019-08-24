#include "build/temp/_test_tp3.c"
#include "tp3.h"
#include "unity.h"










void tearDown(void);

void test_tp3_1(void);

void test_tp3_2(void);

void test_tp3_3(void);

void test_tp3_4(void);

void test_tp3_5(void)











;

void tearDown(void){





}



void test_tp3_1(void){



 uint16_t buf[10];

 uint16_t cant;

 length(buf,&cant);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((5)), (UNITY_INT)(UNITY_INT16)((cant)), (

((void *)0)

), (UNITY_UINT)(63), UNITY_DISPLAY_STYLE_HEX16);



}

void test_tp3_2(void){

 UnityFail( (("Failed")), (UNITY_UINT)(67));

 uint16_t buf[10];

 uint16_t size;

 bufsize(buf,&size);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((10)), (UNITY_INT)(UNITY_INT16)((size)), (

((void *)0)

), (UNITY_UINT)(71), UNITY_DISPLAY_STYLE_HEX16);



}



void test_tp3_3(void){

 UnityFail( (("Failed")), (UNITY_UINT)(76));

 uint16_t MAX=0xffff;

 uint16_t value;

 sumsat(&value);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((MAX)), (UNITY_INT)(UNITY_INT16)((value)), (

((void *)0)

), (UNITY_UINT)(80), UNITY_DISPLAY_STYLE_HEX16);



}

void test_tp3_4(void){

 UnityFail( (("Failed")), (UNITY_UINT)(84));

 uint16_t MIN=0x0000;

 uint16_t value;

 subsat(&value);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((MIN)), (UNITY_INT)(UNITY_INT16)((value)), (

((void *)0)

), (UNITY_UINT)(88), UNITY_DISPLAY_STYLE_HEX16);



}



void test_tp3_5(void){

 UnityFail( (("Failed")), (UNITY_UINT)(93));

 uint16_t x;

 uint16_t y=2*x;

 twice(&x);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((y)), (UNITY_INT)(UNITY_INT16)((x)), (

((void *)0)

), (UNITY_UINT)(97), UNITY_DISPLAY_STYLE_HEX16);

}













void setUp(void){





}
