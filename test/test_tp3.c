#include "unity.h"
#include "tp3.h"

void setUp(void){


}

void tearDown(void){


}

void test_tp3(void){
	//TEST_FAIL_MESSAGE("Failed");
	uint16_t ledsVirtual =0xffff;
	leds_Create(&ledsVirtual);
	TEST_ASSERT_EQUAL_HEX16(0,ledsVirtual);

}
