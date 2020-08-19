#include "sensor.h"
#include "sapi.h"


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

