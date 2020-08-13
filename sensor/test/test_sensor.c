/*

test initialize_sequence
test Read_Bit
test_Send_bit
test_Read_byte
test_Send_byte
test_skip_Rom
test read_Scratchpad

*/

#include "unity.h"
#include "sensor.h"
#include "mock_sapi.h"


void setUp(void)
{
}

//! @test_initialize_sequence
void test_initialize(void){
	gpioConfig_ExpectAndReturn(GPIO2, GPIO_OUTPUT, TRUE);
	gpioWrite_ExpectAndReturn(GPIO2, 0 , TRUE);
	delayInaccurateUs_Expect(500);
	gpioConfig_ExpectAndReturn(GPIO2, GPIO_INPUT, TRUE);
	delayInaccurateUs_Expect(90);
	delayInaccurateUs_Expect(410);
	initialize_sequence();
}

//! @test_read_Bit
void test_Read_Bit(void){
	gpioConfig_ExpectAndReturn(GPIO2, GPIO_OUTPUT, TRUE);
	gpioWrite_ExpectAndReturn(GPIO2, 0 , TRUE);
	delayInaccurateUs_Expect(3);
	gpioConfig_ExpectAndReturn(GPIO2, GPIO_INPUT, TRUE);
	delayInaccurateUs_Expect(10);
	gpioRead_ExpectAndReturn(GPIO2, TRUE);
	delayInaccurateUs_Expect(55);
	read_bit();

}

//! @test_Send_bit
void test_Send_bit(void){
	bool bit_data;
	gpioConfig_ExpectAndReturn(GPIO2, GPIO_OUTPUT, TRUE);
	gpioWrite_ExpectAndReturn(GPIO2, 0 , TRUE);
	delayInaccurateUs_Expect(2);
	gpioWrite_ExpectAndReturn(GPIO2, 1 , TRUE);
	delayInaccurateUs_Expect(60);
	gpioWrite_ExpectAndReturn(GPIO2, 1 , FALSE);
	delayInaccurateUs_Expect(60);
	delayInaccurateUs_Expect(10);
	send_bit(bit_data);

}

//! @test_Send_byte
void test_Send_byte(void){
	uint8_t data = 0xF;
	send_byte(data);
	TEST_ASSERT_EQUAL_UINT8(0X0, data);
}

//! @test_Skip_Rom
void test_Skip_Rom(void){
	skip_Rom();
	
}

//! @test_Read_byte
void test_Read_byte(void){
	read_byte();
}

//! @test_Crc8
void test_Crc8 (void){
	crc8 ();
}

//! @test_read_Scratchpad
void test_read_Scratchpad(void){
	Read_Scratchpad();
}

