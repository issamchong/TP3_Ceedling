#include "build/temp/_test_tp3.c"
#include "driver_testing.h"
#include "service_testing.h"
#include "tp3.h"
#include "unity.h"






static struct MedirPerformance performance;

Token_pt ptr;



void tearDown(void);

void test_tp3_1(void);

void test_tp3_2(void);

void test_tp3_3(void);







void tearDown(void){}



void test_tp3_1(void){



 char frame[105];

 GetHeap(frame);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)(('3')), (UNITY_INT)(UNITY_INT16)((frame[1])), (

((void *)0)

), (UNITY_UINT)(54), UNITY_DISPLAY_STYLE_HEX16);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)(('1')), (UNITY_INT)(UNITY_INT16)((frame[2])), (

((void *)0)

), (UNITY_UINT)(55), UNITY_DISPLAY_STYLE_HEX16);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)(('4')), (UNITY_INT)(UNITY_INT16)((frame[3])), (

((void *)0)

), (UNITY_UINT)(56), UNITY_DISPLAY_STYLE_HEX16);

}

void test_tp3_2(void){



 ptr=&performance;

 ptr->estado=0;

 fsmMesurePerformance(ptr,

                         ((void *)0)

                             ,

                              ((void *)0)

                                  );

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1)), (UNITY_INT)(UNITY_INT16)((ptr->estado)), (

((void *)0)

), (UNITY_UINT)(63), UNITY_DISPLAY_STYLE_HEX16);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1)), (UNITY_INT)(UNITY_INT16)((ptr->id_of_package)), (

((void *)0)

), (UNITY_UINT)(64), UNITY_DISPLAY_STYLE_HEX16);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((ptr->tiempo_de_llegada)), (

((void *)0)

), (UNITY_UINT)(65), UNITY_DISPLAY_STYLE_HEX16);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1)), (UNITY_INT)(UNITY_INT16)((ptr->tiempo_de_recepcion)), (

((void *)0)

), (UNITY_UINT)(66), UNITY_DISPLAY_STYLE_HEX16);

}

void test_tp3_3(void){



 ptr=&performance;

 char msg[100]="Hola, this is a test";

 fsmMesurePerformance(ptr,msg,sizeof(msg));

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((2)), (UNITY_INT)(UNITY_INT16)((ptr->estado)), (

((void *)0)

), (UNITY_UINT)(73), UNITY_DISPLAY_STYLE_HEX16);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((strlen(msg))), (UNITY_INT)(UNITY_INT16)((ptr->package_length)), (

((void *)0)

), (UNITY_UINT)(74), UNITY_DISPLAY_STYLE_HEX16);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((sizeof(msg))), (UNITY_INT)(UNITY_INT16)((ptr->alocated_memory)), (

((void *)0)

), (UNITY_UINT)(75), UNITY_DISPLAY_STYLE_HEX16);

}

void test_tp3_4(void){



 ptr=&performance;

 char token[100];

 bzero(token,strlen(token));

 CompileToken(ptr,token);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)(('5')), (UNITY_INT)(UNITY_INT16)((token[1])), (

((void *)0)

), (UNITY_UINT)(83), UNITY_DISPLAY_STYLE_HEX16);

}

void test_tp3_5(void){



 char ascii[55];

 char hex[105]="68 6f 6c 61";

 printf("%s ",hex);

 ASCI(hex,strlen(hex),ascii);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)(('h')), (UNITY_INT)(UNITY_INT16)((ascii[0])), (

((void *)0)

), (UNITY_UINT)(91), UNITY_DISPLAY_STYLE_HEX16);

}







void setUp(void){





}
