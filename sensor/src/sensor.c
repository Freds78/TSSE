#include "sensor.h"
#include "sapi.h"

#define SKIP_ROMCOM 0xCC

uint8_t scratch[9];

 void initialize_sequence(){

	gpioConfig( GPIO2, GPIO_OUTPUT );
	gpioWrite( GPIO2, 0 );
	delayInaccurateUs( 500 );
	gpioConfig( GPIO2, GPIO_INPUT );
	delayInaccurateUs( 90 );
	delayInaccurateUs( 410 );
}

 uint8_t read_bit() {

	uint8_t read;
	gpioConfig( GPIO2, GPIO_OUTPUT );
	gpioWrite( GPIO2, 0 );
	delayInaccurateUs( 3 );
	gpioConfig( GPIO2, GPIO_INPUT );
	delayInaccurateUs( 10 );
	read = gpioRead( GPIO2 );
	delayInaccurateUs( 55 );
	return read;
}

 void send_bit(uint8_t bit_data) {

	gpioConfig( GPIO2, GPIO_OUTPUT );
	gpioWrite( GPIO2, 0 );
	delayInaccurateUs( 2 );
    	if (bit_data) {
    	gpioWrite( GPIO2, 1 );
    	delayInaccurateUs( 60 );
     	} else {
    	delayInaccurateUs( 60 );
    	gpioWrite( GPIO2, 1 );
    	delayInaccurateUs( 10 );
    	}
}


void send_byte(uint8_t data) {
 int8_t i;

 for (i = 0; i < 8; i++) {
	 send_bit(data & 0x01);
	 data = data >> 1;
 }
}

uint8_t read_byte() {
	uint8_t byte = 0;
	int8_t i;
	uint8_t j;

	for (i=0; i < 8; i++) {
		j = read_bit();
		j = j << i;
		byte = byte | j;
	}
	return byte;
}

void skip_Rom(){
	send_byte(SKIP_ROMCOM);
}


void Read_Scratchpad(){

	int8_t i;
	for (i = 0; i < 9; i++) {
		scratch[i] = read_byte();
	}
	if (crc8() != 0){
		initialize_sequence();
	}
}


uint8_t crc8 () {
 	uint8_t div = 0b10001100; // Rotated poly
 	uint8_t crc = 0;
 	int8_t i;

 	for (i = 0; i < 8; i++) {
	 	uint8_t byte = scratch[i];
	 	int8_t j;
	 	for (j = 0; j < 8; j++) {
		 	uint8_t crc_carry = crc & 1;
		 	crc = crc >> 1;
		 	uint8_t byte_carry = byte & 1;
		 	byte = byte >>1;
		 	if (crc_carry ^ byte_carry)
				crc ^= div;
	 	}
 	}
 return crc;
}

