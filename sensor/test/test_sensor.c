/*

test initialize_sequence
test Read_Bit
test_Send_bit

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
	uint8_t read;
	read = 1;
	gpioConfig_ExpectAndReturn(GPIO2, GPIO_OUTPUT, TRUE);
	gpioWrite_ExpectAndReturn(GPIO2, 0 , TRUE);
	delayInaccurateUs_Expect(3);
	gpioConfig_ExpectAndReturn(GPIO2, GPIO_INPUT, TRUE);
	delayInaccurateUs_Expect(10);
	gpioRead_ExpectAndReturn(GPIO2, read);
	delayInaccurateUs_Expect(55);
	TEST_ASSERT_EQUAL(1, read);
	read_bit();
	

}

//! @test_Send_bit
void test_Send_bit(void){
	uint8_t bit_data;
	bit_data = 1;
	gpioConfig_ExpectAndReturn(GPIO2, GPIO_OUTPUT, TRUE);
	gpioWrite_ExpectAndReturn(GPIO2, 0 , TRUE);
	delayInaccurateUs_Expect(2);
	if(bit_data == 1){
		
		gpioWrite_ExpectAndReturn(GPIO2, 1 , TRUE);
		delayInaccurateUs_Expect(60);
		TEST_ASSERT_EQUAL_INT(1, 1);
	}else{
		
	delayInaccurateUs_Expect(60);
	gpioWrite_ExpectAndReturn(GPIO2, 1 , TRUE);
	delayInaccurateUs_Expect(10);
	TEST_ASSERT_EQUAL_INT(0, 1);
	}
	send_bit(1);
}

