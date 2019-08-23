#include "build/temp/_test_tp3.c"
#include "tp3.h"
#include "unity.h"


void setUp(void){





}



void tearDown(void){





}



void test_tp3(void){



 uint16_t ledsVirtual =0xffff;

 leds_Create(&ledsVirtual);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((ledsVirtual)), (

((void *)0)

), (UNITY_UINT)(18), UNITY_DISPLAY_STYLE_HEX16);



}
