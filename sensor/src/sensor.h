#include <stdint.h>
#include<stdbool.h>// Booleanos

void initialize_sequence();
uint8_t read_bit();
void send_bit(uint8_t bit_data);
void send_byte(uint8_t data);
uint8_t read_byte();
void skip_Rom();
void Read_Scratchpad();
uint8_t crc8 ();

