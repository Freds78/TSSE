/*
test_todos_los leds_inician_apagados
test encender led
test prender y apagar un led
test prender y apagar algunos led
test prender todos los leds simultaneamente
test apagar todos los leds simultaneamente
test consultar el estado de un led prendido
test consultar el estado de un led apagado
*/

#include "unity.h"
#include "leds.h"

uint16_t virtuales;

void setUp(void){
	LedsCreate(&virtuales);
}

//! @test_todos_los leds_inician_apagados
void test_todos_los_leds_inician_apagados(void){
	uint16_t virtuales = 0xFFFF;
	LedsCreate(&virtuales);
	TEST_ASSERT_EQUAL_UINT16(0X0000, virtuales);
}

//! @test encender led
void test_encender_un_led(void){
	LedsTurnOn(1);
	TEST_ASSERT_EQUAL_UINT16(0X0001, virtuales);
}

//! @test prender y apagar un led
void test_prender_y_apagar_un_led(void){
	LedsTurnOn(1);
	LedsTurnOff(1);
	TEST_ASSERT_EQUAL_UINT16(0X0000, virtuales);
}

//! @test prender y apagar algunos led
void test_prender_y_apagar_algunos_led(void){
	LedsTurnOn(1);
	LedsTurnOn(5);
	LedsTurnOff(3);
	TEST_ASSERT_EQUAL_HEX16(0X0011, virtuales);
}

//! @test prender todos los leds simultaneamente
void test_prender_todos_los_leds_simultaneamente(void){
	Leds_TurnAllOn();
	TEST_ASSERT_EQUAL_HEX16(0XFFFF, virtuales);
}

//! @test apagar todos los leds simultaneamente
void test_apagar_todos_los_leds_simultaneamente(void){
	Leds_TurnAllOn();
	Leds_TurnAllOff();
	TEST_ASSERT_EQUAL_HEX16(0X0000, virtuales);
}

//! @test consultar el estado de un led prendido
void test_consultar_el_estado_de_un_led_prendido(void){
	LedsTurnOn(8);
	TEST_ASSERT_FALSE(Leds_IsOn(8));
}

//! @test consultar el estado de un led apagado
void test_consultar_el_estado_de_un_led_apagado(void){
	LedsTurnOff(12);
	TEST_ASSERT_TRUE(Leds_IsOff(12));
}


