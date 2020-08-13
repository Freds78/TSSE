#include "leds.h"
#include<stdbool.h>// Booleanos

#define LEDS_ALL_OFF 0x0000;
#define LED_BIT_ON 1
#define LED_TO_BITS_OFFSET 1
#define ALL_LEDS_ON ~0
#define ALL_LEDS_OFF ~ALL_LEDS_ON
#define FIRST_LED 1
#define LAST_LED 16


static uint16_t *puerto;
static uint16_t ledsImage;



int LedOutOfRange(uint8_t leds)
{
	return (leds < FIRST_LED) || (leds > LAST_LED);
}

static void updateStatus(void)
{
	*puerto = ledsImage;
}

uint8_t LedToBit(uint8_t led){
	return (led-LED_TO_BITS_OFFSET);
}

uint16_t BitMask(uint8_t bit){
	return (LED_BIT_ON << bit);
}

void LedsCreate(uint16_t *direccion){
 	puerto = direccion;
	ledsImage = LEDS_ALL_OFF;
	*puerto = ledsImage;
}

void LedsTurnOn(uint8_t leds){

	if(LedOutOfRange(leds)){
		return;
	}
	*puerto |= BitMask(LedToBit(leds));
}

void LedsTurnOff(uint8_t leds){
	
	if(LedOutOfRange(leds)){
		return;
	}
	*puerto &= ~BitMask(LedToBit(leds));
}

/***********************************************/
void Leds_TurnAllOn()
{
	ledsImage = ALL_LEDS_ON;
	updateStatus();
}

void Leds_TurnAllOff()
{
	ledsImage = ALL_LEDS_OFF;
	updateStatus();
}

bool Leds_IsOn(uint8_t leds)
{
	if (LedOutOfRange(leds)) {
		return 0;
	} else {
		return (ledsImage & BitMask(LedToBit(leds)) != 0);
	}
}

bool Leds_IsOff(uint8_t leds)
{
	return !(Leds_IsOn(leds));
}
