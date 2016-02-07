#pragma once

//
// Utilities for UART communication.
//
// First, init uart with usart_init().
// Then enable interrupts you want with usart_XXX_isr_enable().
//

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

#include <stdbool.h>
#include <stdint.h>


/* USART BAUD RATE REGISTER values at 16 MHz */
enum {
	BAUD_9600 = 103,
	BAUD_14400 = 68,
	BAUD_19200 = 51,
	BAUD_28800 = 34,
	BAUD_38400 = 25,
	BAUD_57600 = 16,
	BAUD_76800 = 12,
	BAUD_115200 = 8,
	BAUD_250k = 3,
	BAUD_500k = 1,
	BAUD_1M = 0,
};

/** Init UART with a UBRR value */
void usart_init(uint16_t ubrr);

/** Check if there's a byte in the RX register */
#define usart_rx_ready() (0 != (UCSR0A & (1 << RXC0)))

/** Check if transmission of everything is done */
#define usart_tx_ready() (0 != (UCSR0A & (1 << UDRE0)))




// ---- Enable UART interrupts ------------

/** Enable or disable RX ISR */
inline void usart_rx_isr_enable(bool yes)
{
	set_bit(UCSR0B, RXCIE0, yes);
}

/** Enable or disable TX ISR (1 byte is sent) */
inline void usart_tx_isr_enable(bool yes)
{
	set_bit(UCSR0B, TXCIE0, yes);
}

/** Enable or disable DRE ISR (all is sent) */
inline void usart_dre_isr_enable(bool yes)
{
	set_bit(UCSR0B, UDRIE0, yes);
}


// ---- Basic IO --------------------------

/** Send byte over USART */
inline void usart_tx(uint8_t data)
{
	// Wait for transmit buffer
	while (!usart_tx_ready());
	// send it
	UDR0 = data;
}


/** Receive one byte over USART */
inline uint8_t usart_rx(void)
{
	// Wait for data to be received
	while (!usart_rx_ready());
	// Get and return received data from buffer
	return UDR0;
}

/** Send byte over UART */
#define usart_putc(data) usart_tx((data))

/** Clear receive buffer */
void usart_clear_rx();


// ---- Strings ---------------------------

/** Send string over UART */
void usart_puts(const char* str);

/** Send progmem string over UART */
void usart_puts_P(const char* str);
