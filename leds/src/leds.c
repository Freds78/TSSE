#include "leds.h"
#include<stdbool.h>// Booleanos

#define LEDS_ALL_OFF 0x0000;
#define LED_BIT_ON 1
#define LED_TO_BITS_OFFSET 1
#define LEDS_ALL_ON 0xFFFF;
#define FIRST_LED 1
#define LAST_LED 16


static uint16_t *puerto;
static uint16_t ledsImage;



int LedOutOfRange(uint8_t leds)
{
	return (leds < FIRST_LED) || (leds > LAST_LED);
}

uint8_t LedToBit(uint8_t led){
	return (led-LED_TO_BITS_OFFSET);
}

uint16_t BitMask(uint8_t bit){
	return (LED_BIT_ON << bit);
}

void LedsCreate(uint16_t *direccion){
 	puerto = direccion;
	*puerto = LEDS_ALL_OFF;
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
	*puerto = LEDS_ALL_ON;
}

void Leds_TurnAllOff()
{
	*puerto = LEDS_ALL_OFF;
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
