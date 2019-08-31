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

 char package[]="{005hello}";

 char data[100];

 op0(data,package);

 printf("%s", data);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)(('H')), (UNITY_INT)(UNITY_INT16)((data[4])), (

((void *)0)

), (UNITY_UINT)(55), UNITY_DISPLAY_STYLE_HEX16);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)(('E')), (UNITY_INT)(UNITY_INT16)((data[5])), (

((void *)0)

), (UNITY_UINT)(56), UNITY_DISPLAY_STYLE_HEX16);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)(('L')), (UNITY_INT)(UNITY_INT16)((data[6])), (

((void *)0)

), (UNITY_UINT)(57), UNITY_DISPLAY_STYLE_HEX16);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)(('L')), (UNITY_INT)(UNITY_INT16)((data[7])), (

((void *)0)

), (UNITY_UINT)(58), UNITY_DISPLAY_STYLE_HEX16);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)(('O')), (UNITY_INT)(UNITY_INT16)((data[8])), (

((void *)0)

), (UNITY_UINT)(59), UNITY_DISPLAY_STYLE_HEX16);



}

void test_tp3_2(void){



 char package[]="{005HELLO}";

 char data[100];

 op1(data,package);

 printf("%s", data);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)(('h')), (UNITY_INT)(UNITY_INT16)((data[4])), (

((void *)0)

), (UNITY_UINT)(68), UNITY_DISPLAY_STYLE_HEX16);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)(('e')), (UNITY_INT)(UNITY_INT16)((data[5])), (

((void *)0)

), (UNITY_UINT)(69), UNITY_DISPLAY_STYLE_HEX16);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)(('l')), (UNITY_INT)(UNITY_INT16)((data[6])), (

((void *)0)

), (UNITY_UINT)(70), UNITY_DISPLAY_STYLE_HEX16);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)(('l')), (UNITY_INT)(UNITY_INT16)((data[7])), (

((void *)0)

), (UNITY_UINT)(71), UNITY_DISPLAY_STYLE_HEX16);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)(('o')), (UNITY_INT)(UNITY_INT16)((data[8])), (

((void *)0)

), (UNITY_UINT)(72), UNITY_DISPLAY_STYLE_HEX16);





}

void test_tp3_3(void){



 ptr=&performance;

 char msg[100]="Hola, this is a test";

 fsmMesurePerformance(ptr,

                         ((void *)0)

                             ,

                              ((void *)0)

                                  );

 fsmMesurePerformance(ptr,msg,sizeof(msg));

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((2)), (UNITY_INT)(UNITY_INT16)((ptr->estado)), (

((void *)0)

), (UNITY_UINT)(82), UNITY_DISPLAY_STYLE_HEX16);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((strlen(msg))), (UNITY_INT)(UNITY_INT16)((ptr->package_length)), (

((void *)0)

), (UNITY_UINT)(83), UNITY_DISPLAY_STYLE_HEX16);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((sizeof(msg))), (UNITY_INT)(UNITY_INT16)((ptr->alocated_memory)), (

((void *)0)

), (UNITY_UINT)(84), UNITY_DISPLAY_STYLE_HEX16);

}

void test_tp3_4(void){



 ptr=&performance;

 char token[100];

 bzero(token,strlen(token));

 CompileToken(ptr,token);



 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)(('1')), (UNITY_INT)(UNITY_INT16)((token[5])), (

((void *)0)

), (UNITY_UINT)(93), UNITY_DISPLAY_STYLE_HEX16);

}

void test_tp3_5(void){



 char ascii[55];

 char hex[105]="68";

 ASCI(hex,strlen(hex),ascii);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)(('h')), (UNITY_INT)(UNITY_INT16)((ascii[0])), (

((void *)0)

), (UNITY_UINT)(100), UNITY_DISPLAY_STYLE_HEX16);

}







void setUp(void){





}
