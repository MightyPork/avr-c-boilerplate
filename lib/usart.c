#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "calc.h"
#include "usart.h"


void usart_init(uint16_t ubrr)
{
	/*Set baud rate */
	UBRR0H = (uint8_t)(ubrr >> 8);
	UBRR0L = (uint8_t) ubrr;

	// Enable Rx and Tx
	UCSR0B = (1 << RXEN0) | (1 << TXEN0);

	// Clear U2X0
	cbi(UCSR0A, U2X0);

	// 8-bit data, 1 stop bit
	UCSR0C = (0b11 << UCSZ00);
}


/** Set Double Speed Asynchronous mode */
void usart_set_2x(bool set)
{
	set_bit(UCSR0A, U2X0, set);
}


/** Send byte over USART */
void usart_tx(uint8_t data)
{
	// Wait for transmit buffer
	while (!usart_tx_ready());
	// send it
	UDR0 = data;
}


/** Receive one byte over USART */
uint8_t usart_rx(void)
{
	// Wait for data to be received
	while (!usart_rx_ready());
	// Get and return received data from buffer
	return UDR0;
}


/** Send string over USART */
void usart_puts(const char* str)
{
	while (*str) {
		usart_tx(*str++);
	}
}


/** Send progmem string over USART */
void usart_puts_P(const char* str)
{
	char c;
	while ((c = pgm_read_byte(str++))) {
		usart_tx(c);
	}
}


/** Clear receive buffer */
void usart_flush_rx(void)
{
	uint8_t dummy;
	while (bit_is_high(UCSR0A, RXC0)) {
		dummy = UDR0;
	}
}
